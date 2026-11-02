(() => {
"use strict";

const P = window.Pond;

const REPORT_ERRORS = {
  invalid_issue: "Pick what went wrong from the list",
  offline: "Connect the device to Wi-Fi or a hotspot first, then send your report",
  pending: "Your last report is still sending"
};

let alertToast = null;
let errors = REPORT_ERRORS;
let sending = false;

function isBusy(status) {
  return status === "pending";
}

function refresh() {
  if (location.pathname === "/report") {
    P.refresh();
  }
}

function resetButton(button) {
  button.disabled = false;
  button.lastChild.textContent = button.dataset.label;
}

async function send(body, button) {
  sending = true;

  if (alertToast) {
    alertToast.remove();
  }

  const handle = P.job({ label: "Sending report" });

  try {
    await P.request("POST", "/api/issue_report", body);
    await P.poll(async () => {
      const current = await P.get("/api/issue_report");
      if (!isBusy(current.status)) {
        return current;
      }
    });
  } catch (error) {
    sending = false;
    resetButton(button);
    alertToast = handle.fail(error, "Couldn't send the report", errors);
    return;
  }

  sending = false;

  handle.done("Report sent");

  refresh();
}

function watch() {
  sending = true;

  P.poll(async () => {
    const report = await P.get("/api/issue_report");
    if (!isBusy(report.status)) {
      return report.status;
    }
  }).then(() => {
    sending = false;
    refresh();
  }, error => {
    sending = false;
    P.fail(error, "Couldn't check on the report");
  });
}

P.page("report", {
  title: "Report an Issue",
  async render() {
    let report;
    try {
      report = await P.get("/api/issue_report");
    } catch (error) {
      if (!(error instanceof P.PondError) || error.status !== 404) {
        throw error;
      }

      const unavailable = "<h3>Reporting isn't available</h3><p>Reports reach the FrogPilot team only from FrogPilot installed from its own GitHub.</p>";
      return { body: `<section class="panel report-panel"><div class="empty">${unavailable}</div></section>` };
    }

    const issueOptions = [];
    for (const issue of report.issues) {
      issueOptions.push([issue, issue]);
    }

    errors = {
      ...REPORT_ERRORS,
      invalid_description: `Describe what happened in ${report.description_min_length} to ${report.description_max_length} characters`,
      invalid_discord_user: `Enter your Discord username (up to ${report.discord_user_max_length} characters)`
    };

    const pending = sending || isBusy(report.status);

    let sendLabel = "Send report";
    let sendState = "";
    if (pending) {
      sendLabel = "Sending…";
      sendState = "disabled";
    }

    const issue = report.issues[report.issues.length - 1];
    const issuePicker = P.dropdown({ value: issue, options: issueOptions, label: "What went wrong?", attrs: "data-report-issue" });

    const descriptionError = `<small class="hint report-error" id="report-description-error" aria-hidden="true" hidden>${errors.invalid_description}</small>`;
    const descriptionPlaceholder = "For example: the car braked hard behind a slowing truck on the highway";
    const descriptionInput = `<textarea class="input" name="description" maxlength="${report.description_max_length}"
      aria-describedby="report-description-error" placeholder="${descriptionPlaceholder}"></textarea>`;

    const discordError = `<small class="hint report-error" id="report-discord-error" aria-hidden="true" hidden>${errors.invalid_discord_user}</small>`;
    const discordInput = `<input class="input" name="discord_user" maxlength="${report.discord_user_max_length}" autocomplete="off" required
      aria-describedby="report-discord-error" value="${P.esc(report.discord_user)}" placeholder="So the FrogPilot team can reach you">`;

    const included = "Your settings and the most recent error log go along with it so the problem can be traced.";
    const smallPrint = `<p class="muted small-print">${included}</p>`;

    const sendButton = `<button class="btn btn-primary btn-small" type="submit" data-label="Send report" ${sendState}>${P.ic("send")}${sendLabel}</button>`;

    return {
      body: `
      <section class="panel report-panel"><div class="panel-body"><form class="form-grid" data-report novalidate>
        <label class="field"><span>What went wrong?</span>${issuePicker}</label>
        <label class="field" data-report-description><span>What happened?</span>${descriptionInput}${descriptionError}</label>
        <label class="field"><span>Your Discord name</span>${discordInput}${discordError}</label>
        ${smallPrint}
        <div>${sendButton}</div>
      </form></div></section>`,
      mount: root => {
        const form = root.querySelector("[data-report]");
        const picker = form.querySelector("[data-report-issue]");
        const description = form.querySelector("[data-report-description]");

        const invalid = (field, error) => {
          field.setAttribute("aria-invalid", String(Boolean(error)));
          root.querySelector(`#${field.getAttribute("aria-describedby")}`).hidden = !error;
        };

        const showDescription = () => {
          description.hidden = !report.described_issues.includes(picker.dataset.value);
        };

        showDescription();

        picker.addEventListener("change", showDescription);

        if (isBusy(report.status) && !sending) {
          watch();
        }

        form.addEventListener("submit", async event => {
          event.preventDefault();

          const body = { discord_user: form.discord_user.value.trim(), issue: picker.dataset.value };

          const text = form.description.value.replace(/\s+/g, " ").trim();
          const shortDescription = !description.hidden && text.length < report.description_min_length;

          invalid(form.description, shortDescription);
          invalid(form.discord_user, !body.discord_user);

          if (shortDescription) {
            form.description.focus();
            return;
          }
          if (!body.discord_user) {
            form.discord_user.focus();
            return;
          }

          if (!description.hidden) {
            body.description = text;
          }

          const button = form.querySelector("[type='submit']");
          button.disabled = true;
          button.lastChild.textContent = "Sending…";

          send(body, button);
        });
      }
    };
  }
});
})();
