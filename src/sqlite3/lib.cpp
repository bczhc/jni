//
// Created by bczhc on 21/12/22.
//

#include "lib.h"

constexpr auto EXCEPTION_CLASS = "pers/zhc/jni/sqlite/SQLiteException";

void throwSqliteException(JNIEnv *env, const SqliteException &e) {
    throwSqliteException(env, e.what());
}

void throwSqliteException(JNIEnv *env, const String &msg) {
    bczhc::throwCustomException(env, EXCEPTION_CLASS, "%s", msg.getCString());
}
