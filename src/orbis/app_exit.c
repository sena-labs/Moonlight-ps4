#include "app_exit.h"

#include <stdio.h>

#include "log.h"

#ifdef __ORBIS__
#include <orbis/libkernel.h>
#include <orbis/SystemService.h>
#endif

void app_exit_to_dashboard(void) {
#ifdef __ORBIS__
    LOGI("app_exit: leaving to dashboard");
    int rc = sceSystemServiceLoadExec("exit://home", NULL);
    if (rc != 0) {
        LOGW("app_exit: LoadExec rc=0x%08x, trying NavigateToGoHome", rc);
        sceSystemServiceNavigateToGoHome();
        LOGW("app_exit: NavigateToGoHome returned");
    }
    /* Nothing worked: park instead of returning into the CRT exit path. */
    for (;;)
        sceKernelUsleep(1000 * 1000);
#else
    LOGI("app_exit: host build, nothing to do");
#endif
}
