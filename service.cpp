#include <stdio.h>
#include "service.h"

String16 IGpsService::getInterfaceDescriptor()
{
    return String16("com.garmin.android.gpsd.service");
}

void BnGpsService::instantiate()
{
    static BnGpsService obj;

    defaultServiceManager()->addService(IGpsService::descriptor, &obj);

}

#define CHECK_INTERFACE(interface, data, reply) \
        do { if (!data.enforceInterface(interface::getInterfaceDescriptor())) { \
            LOGW("Call incorrectly routed to " #interface); \
            return android::PERMISSION_DENIED;              \
        } } while (0)

status_t BnGpsService::onTransact(uint32_t code,
                                  const Parcel &data,
                                  Parcel *reply,
                                  uint32_t flags)
{
    switch (code) {
        case GET_GPS:
            CHECK_INTERFACE(IGpsService, data, reply);
            const char *str = data.readCString();
            printf("hello: %s\n", str);
            reply->writeInt32(123);
            return android::NO_ERROR;

            break;

        default:
            return BBinder::onTransact(code, data, reply, flags);
    }

    return android::NO_ERROR;
}
