//
// Created by bczhc on 21/12/22.
//

#ifndef JNI_LIB_H
#define JNI_LIB_H

#include "../jni_help.h"
#include "../../third_party/my-cpp-lib/exception.hpp"
#include "../../third_party/my-cpp-lib/string.hpp"

void throwSqliteException(JNIEnv *env, const SqliteException &e);

void throwSqliteException(JNIEnv *env, const String &msg);

#endif //JNI_LIB_H
