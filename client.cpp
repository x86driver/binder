#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include "client.h"
#include "service.h"
#include "name.h"

namespace android {

class BpGpsdClient : public android::BpInterface<IGpsdClient> {
public:
    BpGpsdClient(const android::sp<android::IBinder>& impl)
        : android::BpInterface<IGpsdClient>(impl)
    {}

    void hello(const char *str)
    {
        android::Parcel data, reply;
        android::String16 name(GPSD_SERVICE_NAME);
        data.writeInterfaceToken(name);
        data.writeCString(str);
        remote()->transact(BnGpsdService::GET_GPS, data, &reply);

        printf("recv: %d\n", reply.readInt32());
    }
};

IMPLEMENT_META_INTERFACE(GpsdClient, GPSD_SERVICE_NAME);

};

int main()
{
    android::sp<android::IServiceManager> sm = android::defaultServiceManager();
    android::sp<android::IBinder> binder;
    android::sp<android::IGpsdClient> shw;

    do {
        binder = sm->getService(android::String16(GPSD_SERVICE_NAME));
        if (binder != 0)
            break;
        printf("waiting for service\n");
        sleep(1);
    } while (1);

    shw = android::interface_cast<android::IGpsdClient>(binder);
    shw->hello("fun");

    return 0;
}
