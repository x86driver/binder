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

namespace android {

const String16 IGpsdService::descriptor("com.garmin.android.gpsd.service");

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
    switch (code) {
        case GET_GPS:
            CHECK_INTERFACE(IGpsdService, data, reply);
            const char *str;
            str = data.readCString();
            printf("hello: %s\n", str);
            reply->writeInt32(123);
            return android::NO_ERROR;

            break;

        default:
            return BBinder::onTransact(code, data, reply, flags);
    }

    return android::NO_ERROR;
}

};  // namespace android

int main()
{
    android::BnGpsdService::instantiate();
    android::ProcessState::self()->startThreadPool();
    android::IPCThreadState::self()->joinThreadPool();

    return 0;
}
