//
// Created by bczhc on 21/12/22.
//

#include "lib.h"

void throwSqliteException(JNIEnv *env, const char *msg) {
    // TODO: throw real `pers.zhc.jni.sqlite.SQLiteException` in Java
    //  rather than RuntimeException
    bczhc::throwException(env, "%s", msg);
}
