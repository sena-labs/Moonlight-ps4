#pragma once

/* Exit-to-dashboard without crashing: stop stream, close pad, ask the system
 * to exec the shell. Falls back to suspend if LoadExec is unavailable. */

void app_exit_to_dashboard(void);
