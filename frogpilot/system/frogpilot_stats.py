import json
import os
import random
import socket
import subprocess
import sys
import urllib.error
import urllib.parse
import urllib.request

from collections import Counter
from datetime import datetime, timezone
from urllib3.exceptions import ConnectTimeoutError, NewConnectionError, ReadTimeoutError

import openpilot.system.sentry as sentry

from openpilot.common.conversions import Conversions as CV
from openpilot.system.version import get_build_metadata

from openpilot.frogpilot.common.frogpilot_utilities import run_cmd
from openpilot.frogpilot.common.frogpilot_variables import get_frogpilot_toggles, params, params_tracking

def get_county_center(latitude, longitude):
  try:
    url = f"https://nominatim.openstreetmap.org/reverse?format=jsonv2&lat={latitude}&lon={longitude}&addressdetails=1"
    request = urllib.request.Request(url, headers={"User-Agent": "frogpilot-county-center-checker/1.0 (https://github.com/FrogAi/FrogPilot)"})
    with urllib.request.urlopen(request, timeout=10) as response:
      location_data = json.load(response)

    address = location_data.get("address", {})
    county = address.get("county", "Unknown")
    country = address.get("country", "United States")
    country_code = address.get("country_code", "US").upper()
    state = address.get("state", "N/A") if country_code == "US" else "N/A"

    if county and county != "Unknown":
      try:
        county_query = f"https://nominatim.openstreetmap.org/search?county={urllib.parse.quote(county)}&country={country_code}&format=json&limit=1&extratags=1"
        county_request = urllib.request.Request(county_query, headers={"User-Agent": "frogpilot-county-center-checker/1.0 (https://github.com/FrogAi/FrogPilot)"})
        with urllib.request.urlopen(county_request, timeout=10) as county_response:
          county_data = json.load(county_response)

        if county_data:
          extratags = county_data[0].get("extratags", {}) or {}
          population_string = extratags.get("population")
          try:
            county_population = int(str(population_string).replace(',', '').strip()) if population_string else 0
          except Exception:
            county_population = 0

          if county_population >= 100000:
            center_latitude = float(county_data[0]["lat"])
            center_longitude = float(county_data[0]["lon"])
            print(f"Using county center for {county}, {state}, {country} → ({center_latitude}, {center_longitude})")
            return center_latitude, center_longitude, county, state, country
          else:
            if country_code == "US" and state != "N/A":
              state_capital_query_url = f"https://nominatim.openstreetmap.org/search?state={urllib.parse.quote(state)}&country={country_code}&q=capital&format=json&limit=1"
              state_capital_request = urllib.request.Request(state_capital_query_url, headers={"User-Agent": "frogpilot-county-center-checker/1.0 (https://github.com/FrogAi/FrogPilot)"})
              with urllib.request.urlopen(state_capital_request, timeout=10) as state_capital_response:
                state_capital_data = json.load(state_capital_response)

              if state_capital_data:
                capital_latitude = float(state_capital_data[0]["lat"])
                capital_longitude = float(state_capital_data[0]["lon"])
                print(f"County population below 100000 ({county_population}). Using state capital for {state} → ({capital_latitude}, {capital_longitude})")
                return capital_latitude, capital_longitude, "Unknown", state, country

            country_capital_query_url = f"https://nominatim.openstreetmap.org/search?country={country_code}&q=capital&format=json&limit=1"
            country_capital_request = urllib.request.Request(country_capital_query_url, headers={"User-Agent": "frogpilot-county-center-checker/1.0 (https://github.com/FrogAi/FrogPilot)"})
            with urllib.request.urlopen(country_capital_request, timeout=10) as country_capital_response:
              country_capital_data = json.load(country_capital_response)

            if country_capital_data:
              capital_latitude = float(country_capital_data[0]["lat"])
              capital_longitude = float(country_capital_data[0]["lon"])
              print(f"County population below 100000 ({county_population}). Using country capital for {country} → ({capital_latitude}, {capital_longitude})")
              return capital_latitude, capital_longitude, "Unknown", state, country

            sentry.capture_exception(Exception(f"Capital lookup returned no results for {state}/{country_code}"))
        else:
          sentry.capture_exception(Exception(f"County lookup returned no results for {county}, {country_code}"))
      except Exception as county_error:
        if not isinstance(county_error, (ConnectTimeoutError, NewConnectionError, ReadTimeoutError, TimeoutError, socket.gaierror, socket.timeout)):
          sentry.capture_exception(county_error)

    print(f"Falling back to (0, 0) for {latitude}, {longitude}")
    return 0, 0, "Unknown", "N/A", "Unknown"

  except (urllib.error.URLError, urllib.error.HTTPError, socket.gaierror, socket.timeout, TimeoutError, Exception) as error:
    print(f"Falling back due to geocoding error: {error}")
    return 0, 0, "Unknown", "N/A", "Unknown"

def install_influxdb_client():
  try:
    import influxdb_client
    import influxdb_client.client.write_api
  except ModuleNotFoundError:
    print("influxdb-client not found. Attempting installation...")
    stock_mount_options = subprocess.run(["findmnt", "-no", "OPTIONS", "/"], capture_output=True, text=True, check=True).stdout.strip()

    run_cmd(["sudo", "mount", "-o", "remount,rw", "/"], "Successfully remounted / as read-write", "Failed to remount / as read-write")
    run_cmd(["sudo", sys.executable, "-m", "pip", "install", "influxdb-client"], "Successfully installed influxdb-client", "Failed to install influxdb-client", report=False)
    run_cmd(["sudo", "mount", "-o", f"remount,{stock_mount_options}", "/"], "Successfully restored stock mount options", "Failed to restore stock mount options")

def send_stats():
  frogpilot_toggles = get_frogpilot_toggles()

  if frogpilot_toggles.frogs_go_moo:
    return

  if frogpilot_toggles.car_make == "mock":
    return

  install_influxdb_client()

  from influxdb_client import InfluxDBClient, Point, WriteOptions
  from influxdb_client.client.write_api import SYNCHRONOUS

  bucket = os.environ.get("STATS_BUCKET", "")
  org_ID = os.environ.get("STATS_ORG_ID", "")
  token = os.environ.get("STATS_TOKEN", "")
  url = os.environ.get("STATS_URL", "")

  frogpilot_stats = json.loads(params.get("FrogPilotStats") or "{}")

  location = json.loads(params.get("LastGPSPosition") or "{}")
  if not (location.get("latitude") and location.get("longitude")):
    return
  original_latitude = location.get("latitude")
  original_longitude = location.get("longitude")
  latitude, longitude, city, state, country = get_county_center(original_latitude, original_longitude)

  theme_sources = [
    frogpilot_toggles.icon_pack.replace("-animated", ""),
    frogpilot_toggles.color_scheme,
    frogpilot_toggles.distance_icons.replace("-animated", ""),
    frogpilot_toggles.signal_icons.replace("-animated", ""),
    frogpilot_toggles.sound_pack
  ]

  theme_counter = Counter(theme_sources)
  most_common = theme_counter.most_common()
  max_count = most_common[0][1]

  selected_theme = random.choice([item for item, count in most_common if count == max_count]).replace("-user_created", "").replace("_", " ")

  point = (Point("user_stats")
    .field("car_make", "GM" if frogpilot_toggles.car_make == "gm" else frogpilot_toggles.car_make.title())
    .field("car_model", frogpilot_toggles.car_model)
    .field("city", city)
    .field("country", country)
    .field("driving_model", frogpilot_toggles.model_name.replace("🗺️", "").replace("📡", "").replace("👀", "").replace("(Default)", "").strip())
    .field("event", 1)
    .field("frogpilot_drives", params_tracking.get_int("FrogPilotDrives"))
    .field("frogpilot_hours", params_tracking.get_int("FrogPilotMinutes") / 60)
    .field("frogpilot_miles", params_tracking.get_int("FrogPilotKilometers") * CV.KPH_TO_MPH)
    .field("has_pedal", frogpilot_toggles.has_pedal)
    .field("has_sdsu", frogpilot_toggles.has_sdsu)
    .field("latitude", latitude)
    .field("longitude", longitude)
    .field("state", state)
    .field("theme", selected_theme.title())
    .field("total_aol_seconds", float(frogpilot_stats.get("TotalAOLTime", 0)))
    .field("total_lateral_seconds", float(frogpilot_stats.get("TotalLateralTime", 0)))
    .field("total_longitudinal_seconds", float(frogpilot_stats.get("TotalLongitudinalTime", 0)))
    .field("total_tracked_seconds", float(frogpilot_stats.get("TotalTrackedTime", 0)))

    .tag("branch", get_build_metadata().channel)
    .tag("dongle_id", params.get("FrogPilotDongleId", encoding="utf-8"))

    .time(datetime.now(timezone.utc))
  )

  try:
    InfluxDBClient(org=org_ID, token=token, url=url).write_api(write_options=SYNCHRONOUS).write(bucket=bucket, org=org_ID, record=point)
    print("Successfully sent FrogPilot stats!")
  except Exception as exception:
    if not isinstance(exception, (ConnectTimeoutError, NewConnectionError, ReadTimeoutError, TimeoutError, socket.gaierror, socket.timeout)):
      sentry.capture_exception(exception)
    print(f"Failed to send FrogPilot stats: {exception}")
