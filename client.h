#ifndef _CLIENT_H
#define _CLIENT_H

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <utils/String16.h>
#include <utils/threads.h>

namespace android {

class IGpsdClient : public android::IInterface {
public:
    DECLARE_META_INTERFACE(GpsdClient);
    virtual void hello(const char *str) = 0;
};

};

#if 0
class BpGpsdClient : public android::BpInterface<IGpsdClient> {
public:
    BpGpsdClient(const android::sp<android::IBinder>& impl)
        : android::BpInterface<IGpsdClient>(impl)
    {}

    void hello(const char *str)
    {
        android::Parcel data, reply;
        data.writeInterfaceToken(IGpsdService::getInterfaceDescriptor());
        data.writeCString(str);
        remote()->transact(0, data, &reply);

        printf("%d\n", reply.readInt32());
    }
};
#endif

#endif
