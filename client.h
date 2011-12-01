#ifndef _CLIENT_H
#define _CLIENT_H

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <utils/String16.h>
#include <utils/threads.h>

#include "name.h"

namespace android {

class IGpsdClient : public android::IInterface {
public:
    DECLARE_META_INTERFACE(GpsdClient);
    virtual void onChanged(int x) = 0;
};

};  // namespace android

#endif
