#include <stdio.h>
#include <unistd.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include "client.h"
#include "service.h"
#include "gpsclient.h"
#include "name.h"

int main()
{
    android::sp<android::IServiceManager> sm = android::defaultServiceManager();
    android::sp<android::IBinder> binder;
    android::sp<android::IGpsdService> shw;
    android::sp<android::IGpsdClient> m = new android::BnGpsdClient;

    do {
        binder = sm->getService(android::String16(GPSD_SERVICE_NAME));
        if (binder != 0)
            break;
        printf("waiting for service\n");
        sleep(1);
    } while (1);

    shw = android::interface_cast<android::IGpsdService>(binder);
    shw->hello(m);

    pause();
    return 0;
}
