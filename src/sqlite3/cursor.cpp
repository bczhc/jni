//
// Created by bczhc on 2/11/21.
//

#include "../jni_h/pers_zhc_jni_JNI_Sqlite3_Cursor.h"
#include "../../third_party/my-cpp-lib/sqlite3.hpp"
#include "lib.h"

using namespace bczhc;

using Cursor = Sqlite3::Cursor;

JNIEXPORT void JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_00024Cursor_reset
        (JNIEnv *env, jclass, jlong cId) {
    try {
        ((Cursor *) cId)->reset();
    } catch (const SqliteException &e) {
        throwSqliteException(env, e.what());
    }
}

JNIEXPORT jboolean JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_00024Cursor_step
        (JNIEnv *env, jclass, jlong cId) {
    try {
        return (jboolean) ((Cursor *) cId)->step();
    } catch (const SqliteException &e) {
        throwSqliteException(env, e.what());
    }
    return (jboolean) false;
}

JNIEXPORT jbyteArray JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_00024Cursor_getBlob
        (JNIEnv *env, jclass, jlong cId, jint column) {
    try {
        auto b = ((Cursor *) cId)->getBlob((int) column);
        jbyteArray arr = env->NewByteArray(b.size);
        env->SetByteArrayRegion(arr, 0, b.size, (const jbyte *) b.data);
        return arr;
    } catch (const SqliteException &e) {
        throwSqliteException(env, e.what());
    }
    return nullptr;
}

JNIEXPORT jstring JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_00024Cursor_getText
        (JNIEnv *env, jclass, jlong cId, jint c) {
    try {
        auto s = ((Cursor *) cId)->getText((int) c);
        return env->NewStringUTF(s);
    } catch (const SqliteException &e) {
        throwSqliteException(env, e.what());
    }
    return nullptr;
}

JNIEXPORT jdouble JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_00024Cursor_getDouble
        (JNIEnv *env, jclass, jlong cId, jint c) {
    try {
        return (jdouble) ((Cursor *) cId)->getDouble((int) c);
    } catch (const SqliteException &e) {
        throwSqliteException(env, e.what());
    }
    return 0;
}


JNIEXPORT jlong JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_00024Cursor_getLong
        (JNIEnv *env, jclass, jlong cId, jint c) {
    try {
        return (jlong) ((Cursor *) cId)->getLong((int) c);
    } catch (const SqliteException &e) {
        throwSqliteException(env, e.what());
    }
    return 0;
}

JNIEXPORT jint JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_00024Cursor_getInt
        (JNIEnv *env, jclass, jlong cId, jint c) {
    try {
        return (jint) ((Cursor *) cId)->getInt((int) c);
    } catch (const SqliteException &e) {
        throwSqliteException(env, e.what());
    }
    return 0;
}