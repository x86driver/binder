#include <stdio.h>
#include <utils/Log.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#include <string.h>
#include <cutils/atomic.h>
#include <utils/Errors.h>
#include <binder/IServiceManager.h>
#include <utils/String16.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#include "service.h"
#include "client.h"
#include "name.h"

namespace android {

/*
const String16 IGpsdService::descriptor(GPSD_SERVICE_NAME);

const String16 &IGpsdService::getInterfaceDescriptor() const
{
    return descriptor;
}

IGpsdService::IGpsdService()
{
}

IGpsdService::~IGpsdService()
{
}
*/

void BnGpsdService::instantiate()
{
    static BnGpsdService obj;

    defaultServiceManager()->addService(IGpsdService::descriptor, &obj);

}

BnGpsdService::BnGpsdService()
{
}

BnGpsdService::~BnGpsdService()
{
}

status_t BnGpsdService::onTransact(uint32_t code,
                                  const Parcel &data,
                                  Parcel *reply,
                                  uint32_t flags)
{
    sp<IGpsdClient> listener;
    printf("%s called, code: %d\n", __FUNCTION__, code);

    switch (code) {
        case GET_GPS:
            CHECK_INTERFACE(IGpsdService, data, reply);
            listener = interface_cast<IGpsdClient>(data.readStrongBinder());
            listener->onChanged(234);
//            listener->show();
//            reply->writeInt32(EX_NO_ERROR);
            return android::NO_ERROR;

            break;

        default:
            return BBinder::onTransact(code, data, reply, flags);
    }

    return android::NO_ERROR;
}

void BpGpsdService::hello(sp<IGpsdClient> aListener)
{
    android::Parcel data, reply;
    android::String16 name(GPSD_SERVICE_NAME);
    data.writeInterfaceToken(name);
    data.writeStrongBinder(aListener->asBinder());
    remote()->transact(BnGpsdService::GET_GPS, data, &reply);
}

IMPLEMENT_META_INTERFACE(GpsdService, GPSD_SERVICE_NAME);

};  // namespace android
