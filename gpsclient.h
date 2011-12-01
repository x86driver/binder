#ifndef _GPSCLIENT_H
#define _GPSCLIENT_H

#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include "gpsclient.h"
#include "client.h"
#include "service.h"

namespace android {

class BpGpsdClient : public BpInterface<IGpsdClient> {
public:
    BpGpsdClient(const sp<android::IBinder>& impl);
    virtual void onChanged(int x);
};

class BnGpsdClient : public BnInterface<IGpsdClient> {
public:
    BnGpsdClient() {}
    virtual status_t onTransact(uint32_t code,
                                const Parcel &data,
                                Parcel *reply,
                                uint32_t flags);

    virtual void onChanged(int x);
};

};  // namespace android

#endif
