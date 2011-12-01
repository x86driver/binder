LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := service.cpp gpsclient.cpp myservice.cpp

LOCAL_MODULE := service

# for now, until I do a full rebuild.
#LOCAL_PRELINK_MODULE := false

LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += libutils libui

LOCAL_CFLAGS += -Idalvik/libnativehelper/include/nativehelper -O0 -g

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := service.cpp client.cpp gpsclient.cpp

LOCAL_MODULE := client

# for now, until I do a full rebuild.
#LOCAL_PRELINK_MODULE := false

LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += libutils libui

LOCAL_CFLAGS += -Idalvik/libnativehelper/include/nativehelper -O0 -g

include $(BUILD_EXECUTABLE)

