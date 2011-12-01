#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include "gpsclient.h"
#include "client.h"
#include "service.h"
#include "name.h"

namespace android {

    BpGpsdClient::BpGpsdClient(const android::sp<android::IBinder>& impl)
        : android::BpInterface<IGpsdClient>(impl)
    {}

    void BpGpsdClient::onChanged(int x) {
        printf("%s called: %d\n", __FUNCTION__, x);
        Parcel data, reply;
        data.writeInterfaceToken(String16(GPSD_CLIENT_NAME));
        data.writeInt32(x);
        remote()->transact(1, data, &reply);
    }

    IMPLEMENT_META_INTERFACE(GpsdClient, GPSD_CLIENT_NAME);


    status_t BnGpsdClient::onTransact(uint32_t code,
                                const Parcel &data,
                                Parcel *reply,
                                uint32_t flags)
    {

        int x = 0;

        switch (code) {
            case 1:
                CHECK_INTERFACE(IGpsdClient, data, reply);
                x = data.readInt32();
                onChanged(x);
                break;
        }

        return 0;
    }

    void BnGpsdClient::onChanged(int x)
    {
        printf("%s: %d\n", __FUNCTION__, x);
    }

};  // namespace android
