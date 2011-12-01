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

int main()
{
    android::BnGpsdService::instantiate();
    android::ProcessState::self()->startThreadPool();
    android::IPCThreadState::self()->joinThreadPool();

    return 0;
}

