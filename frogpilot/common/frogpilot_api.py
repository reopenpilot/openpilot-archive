import hashlib
import json
import jwt
import requests
import secrets
import time

from urllib.parse import urlparse

from openpilot.common.api import get_key_pair
from openpilot.common.time import system_time_valid

from openpilot.frogpilot.common.frogpilot_variables import params

API_UNAVAILABLE_STATUSES = frozenset((404, 408, 429))
DEVICE_PROFILE_SCHEMA_VERSION = 1
FROGPILOT_API = "https://api.frogpilot.com"
TOKEN_UNAVAILABLE_STATUSES = frozenset()
UPLOAD_UNAVAILABLE_STATUSES = frozenset((408, 429))


class FrogPilotAPIError(RuntimeError):
  pass


class FrogPilotAPIUnavailableError(FrogPilotAPIError):
  pass


def _raise_for_status(description, status, unavailable_statuses):
  if 200 <= status < 300:
    return

  message = f"{description} failed ({status or 'no response'})"
  if not status or status in unavailable_statuses or 500 <= status < 600:
    raise FrogPilotAPIUnavailableError(message)

  raise FrogPilotAPIError(message)


def get_token():
  return params.get("FrogPilotApiToken", encoding="utf-8")


def regenerate_token():
  if not system_time_valid():
    return False

  api_token = secrets.token_urlsafe(32)
  response = signed_post("/v1/token", {"api_token_hash": hashlib.sha256(api_token.encode()).hexdigest()})
  status = getattr(response, "status_code", 0)

  if not 200 <= status < 300:
    params.remove("FrogPilotRegistration")
    _raise_for_status("POST /v1/token", status, TOKEN_UNAVAILABLE_STATUSES)

  params.put("FrogPilotApiToken", api_token)
  return True


def _post(path, session=requests, timeout=10, **kwargs):
  try:
    return session.post(f"{FROGPILOT_API}{path}", timeout=timeout, allow_redirects=False, **kwargs)
  except (requests.exceptions.ProxyError, requests.exceptions.SSLError):
    raise FrogPilotAPIError(f"POST {path} request failed") from None
  except (requests.exceptions.ConnectionError, requests.exceptions.Timeout):
    return None
  except requests.exceptions.RequestException:
    raise FrogPilotAPIError(f"POST {path} request failed") from None


def post(path, headers=None, **kwargs):
  def send(token):
    return _post(path, headers={**(headers or {}), "Authorization": f"Bearer {token}"}, **kwargs)

  token = get_token()
  if token:
    response = send(token)

    if response is None or response.status_code != 401:
      return response

  return send(get_token()) if regenerate_token() else None


def post_json(path, payload, session=requests, timeout=30):
  response = post(path, json=payload, timeout=timeout, session=session)
  status = getattr(response, "status_code", 0)

  _raise_for_status(f"POST {path}", status, API_UNAVAILABLE_STATUSES)

  try:
    result = response.json()
  except ValueError:
    raise FrogPilotAPIError(f"POST {path} returned invalid JSON") from None

  if not isinstance(result, dict):
    raise FrogPilotAPIError(f"POST {path} returned an invalid response")

  return result


def _signed_body(payload, public_key):
  return json.dumps({**payload, "public_key": public_key}, separators=(",", ":"), sort_keys=True)


def body_digest(payload):
  return hashlib.sha256(_signed_body(payload, get_key_pair()[2]).encode()).hexdigest()


def signed_post(path, payload):
  algorithm, private_key, public_key = get_key_pair()
  if not private_key:
    return None

  body = _signed_body(payload, public_key)
  now = int(time.time())
  token = jwt.encode({
    "aud": "api.frogpilot.com",
    "auth_version": 2,
    "body_sha256": hashlib.sha256(body.encode()).hexdigest(),
    "exp": now + 15 * 60,
    "iat": now,
    "method": "POST",
    "path": path,
  }, private_key, algorithm=algorithm)

  return _post(path, timeout=20, data=body, headers={"Authorization": f"JWT {token}", "Content-Type": "application/json"})


def put_upload(upload, data, description, session=requests):
  if not isinstance(upload, dict):
    raise FrogPilotAPIError(f"{description} upload response is invalid")

  url = upload.get("url", "")
  headers = upload.get("headers")

  try:
    parsed = urlparse(url) if isinstance(url, str) else None
    valid_url = parsed is not None and parsed.scheme == "https" and parsed.hostname and not parsed.username and not parsed.password
  except ValueError:
    valid_url = False

  if not valid_url:
    raise FrogPilotAPIError(f"{description} upload URL is not https")
  if not isinstance(headers, dict) or not all(isinstance(key, str) and isinstance(value, str) for key, value in headers.items()):
    raise FrogPilotAPIError(f"{description} upload headers are invalid")

  try:
    response = session.put(url, data=data, headers=headers, timeout=60, allow_redirects=False)
  except (requests.exceptions.ProxyError, requests.exceptions.SSLError):
    raise FrogPilotAPIError(f"{description} upload request failed") from None
  except (requests.exceptions.ConnectionError, requests.exceptions.Timeout):
    raise FrogPilotAPIUnavailableError(f"{description} upload failed (no response)") from None
  except requests.exceptions.RequestException:
    raise FrogPilotAPIError(f"{description} upload request failed") from None

  _raise_for_status(f"{description} upload", response.status_code, UPLOAD_UNAVAILABLE_STATUSES)
