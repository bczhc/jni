#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-reserved-identifier"

#include "../../third_party/my-cpp-lib/third_party/sqlite3-single-c/sqlite3.h"
#include "../jni_h/pers_zhc_jni_JNI_Sqlite3.h"
#include "../../third_party/my-cpp-lib/sqlite3.hpp"
#include "lib.h"

using namespace bczhc;
using namespace std;

class CB : public Sqlite3::SqliteCallback {
private:
    jclass stringClass;
    jmethodID callbackMId;
    JNIEnv *&env;
    jobject &callbackObject;
    jclass mCallbackClass{};
public:
    CB(JNIEnv *&env, jobject &callbackObject) : env(env), callbackObject(callbackObject) {
        jclass callbackClass = env->GetObjectClass(callbackObject);
        callbackMId = env->GetMethodID(callbackClass, "callback",
                                       "([Ljava/lang/String;)I");
        stringClass = (jclass) env->NewGlobalRef(env->FindClass("java/lang/String"));
    }

    ~CB() {
        env->DeleteLocalRef(mCallbackClass);
        env->DeleteGlobalRef(stringClass);
    }

public:
    int callback(void *arg, int colNum, char **content, char **colName) override {
        jobjectArray contentArray = env->NewObjectArray(colNum, stringClass, nullptr);
        for (int i = 0; i < colNum; ++i) {
            jstring s = env->NewStringUTF(content[i]);
            env->SetObjectArrayElement(contentArray, i, s);
            env->DeleteLocalRef(s);
        }
        auto r = (int) env->CallIntMethod(callbackObject, callbackMId, contentArray);
        env->DeleteLocalRef(contentArray);
        return r;
    }
};

JNIEXPORT jlong JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_open
        (JNIEnv *env, jclass, jstring path) {
    const char *file = env->GetStringUTFChars(path, (jboolean *) nullptr);
    try {
        auto *db = new Sqlite3(file);
        return (jlong) db;
    } catch (const SqliteException &e) {
        String msg = "Open or create database failed.";
        msg.append(" code: ")
                .append(String::toString(e.returnCode));
        throwSqliteException(env, msg);
    }
    env->ReleaseStringUTFChars(path, file);
    return (jlong) 0;
}

JNIEXPORT void JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_close
        (JNIEnv *env, jclass, jlong id) {
    auto *db = (Sqlite3 *) id;
    try {
        db->close();
    } catch (const SqliteException &e) {
        throwSqliteException(env, e);
    }
    delete db;
}

JNIEXPORT void JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_exec
        (JNIEnv *env, jclass, jlong id, jstring cmd, jobject callbackInterface) {

    auto *db = (Sqlite3 *) id;
    const char *command = env->GetStringUTFChars(cmd, (jboolean *) nullptr);
    try {
        if (callbackInterface == nullptr) {
            db->exec(command);
        } else {
            CB callback(env, callbackInterface);
            db->exec(command, callback, nullptr);
        }
    } catch (const SqliteException &e) {
        throwSqliteException(env, e);
    }
    env->ReleaseStringUTFChars(cmd, command);
}

JNIEXPORT jboolean JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_checkIfCorrupt
        (JNIEnv *env, jclass, jlong id) {
    try {
        return (jboolean) ((Sqlite3 *) id)->checkIfCorrupt();
    } catch (const SqliteException &e) {
        throwSqliteException(env, e);
    }
    return {};
}

JNIEXPORT jlong JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_compileStatement
        (JNIEnv *env, jclass, jlong id, jstring statJS) {
    try {
        const char *statement = env->GetStringUTFChars(statJS, nullptr);
        Sqlite3::Statement stat = ((Sqlite3 *) id)->compileStatement(statement);
        auto newStat = new Sqlite3::Statement(stat);
        auto r = (int64_t) newStat;
        env->ReleaseStringUTFChars(statJS, statement);
        return (jlong) r;
    } catch (const SqliteException &e) {
        throwSqliteException(env, e);
    }
    return (jlong) nullptr;
}

JNIEXPORT void JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_key
        (JNIEnv *env, jclass, jlong addr, jstring key) {
    auto keyStr = env->GetStringUTFChars(key, nullptr);

    try {
        if (strlen(keyStr) == 0) {
            throw SqliteException("Key cannot be empty");
        }
        ((Sqlite3 *) addr)->key(keyStr);
        env->ReleaseStringUTFChars(key, keyStr);
    } catch (const SqliteException &e) {
        env->ReleaseStringUTFChars(key, keyStr);
        throwSqliteException(env, e);
    }
}

JNIEXPORT void JNICALL Java_pers_zhc_jni_JNI_00024Sqlite3_rekey
        (JNIEnv *env, jclass, jlong addr, jstring key) {
    auto keyStr = env->GetStringUTFChars(key, nullptr);

    try {
        if (strlen(keyStr) == 0) {
            throw SqliteException("Key cannot be empty");
        }
        ((Sqlite3 *) addr)->rekey(keyStr);
        env->ReleaseStringUTFChars(key, keyStr);
    } catch (const SqliteException &e) {
        env->ReleaseStringUTFChars(key, keyStr);
        throwSqliteException(env, e);
    }
}
