#ifndef _SERVICE_H
#define _SERVICE_H

#include <utils/KeyedVector.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <utils/String16.h>
#include <utils/threads.h>
#include <string.h>

namespace android {

class IGpsService : public IInterface {
public:

        DECLARE_META_INTERFACE(GpsService);
        virtual String16 getInterfaceDescriptor();
};

class BnGpsService : public BnInterface<IGpsService> {
public:

    enum {
        GET_GPS = IBinder::FIRST_CALL_TRANSACTION + 0
    };

    static void instantiate();

    virtual status_t onTransact(uint32_t code,
                                const Parcel &data,
                                Parcel *reply,
                                uint32_t flags);

};

#endif
