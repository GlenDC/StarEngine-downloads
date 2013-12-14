LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LS_CPP=$(subst $(1)/,,$(wildcard $(1)/*.cpp))
LS_CPP+= $(subst $(1)/,,$(wildcard $(1)/**/*.cpp))
LS_CPP+= $(subst $(1)/,,$(wildcard $(1)/**/**/*.cpp))
LS_CPP+= $(subst $(1)/,,$(wildcard $(1)/**/**/**/*.cpp))
LOCAL_MODULE    := stargame
LOCAL_CFLAGS 	:= -D FT_FREETYPE_H="freetype/freetype.h"
LOCAL_CPPFLAGS  := -std=gnu++11 -D STAR2D=1 -D LOGGER_MIN_LEVEL=1 -I StarEngine\jni -Ilibs\libpng
LOCAL_SRC_FILES := $(call LS_CPP,$(LOCAL_PATH))
LOCAL_LDLIBS    := -landroid -llog -lEGL -lGLESv1_CM -lGLESv2 -lOpenSLES
APP_PLATFORM := android-14
APP_OPTIM := debug

LOCAL_STATIC_LIBRARIES := android_native_app_glue libpng starengine

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)

$(call import-add-path,$(CURDIR))
$(call import-add-path,libs)
$(call import-module,StarEngine/jni)
$(call import-module,libpng)