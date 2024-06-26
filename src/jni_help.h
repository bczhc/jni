//
// Created by root on 19-10-2.
//

#ifndef JNI_JNI_HELP_H
#define JNI_JNI_HELP_H

#include <jni.h>
#include "../third_party/my-cpp-lib/string.hpp"

using namespace bczhc;

namespace bczhc {
    void jniLog(JNIEnv *&env, const char *tag, const char *format, ...);

    void throwException(JNIEnv *&env, const char *format, ...);

    void throwCustomExceptionArgs(JNIEnv *&env, const char *clz, const char *format, va_list args);

    void throwCustomException(JNIEnv *&env, const char *clz, const char *format, ...);
}

#endif //JNI_JNI_HELP_H
