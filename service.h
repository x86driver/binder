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

    class IGpsdClient;

    class IGpsdService : public IInterface {
    public:

        DECLARE_META_INTERFACE(GpsdService);
        virtual void hello(sp<IGpsdClient> aListener) = 0;
    };

    class BnGpsdService : public BnInterface<IGpsdService> {
    public:

        enum {
            GET_GPS = IBinder::FIRST_CALL_TRANSACTION + 0
        };

        BnGpsdService();
        virtual ~BnGpsdService();

        static void instantiate();

        virtual status_t onTransact(uint32_t code,
                                    const Parcel &data,
                                    Parcel *reply,
                                    uint32_t flags);

        virtual void hello(sp<IGpsdClient> aListener) {}//存東西
    };

    class BpGpsdService : public BpInterface<IGpsdService> {
    public:
        BpGpsdService(const sp<IBinder>& impl)
            : BpInterface<IGpsdService>(impl)
        {}
        void hello(sp<IGpsdClient> aListener);
    };
};  // namespace android

#endif
