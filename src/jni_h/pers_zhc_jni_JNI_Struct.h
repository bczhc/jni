/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class pers_zhc_jni_JNI_Struct */

#ifndef _Included_pers_zhc_jni_JNI_Struct
#define _Included_pers_zhc_jni_JNI_Struct
#ifdef __cplusplus
extern "C" {
#endif
#undef pers_zhc_jni_JNI_Struct_MODE_BIG_ENDIAN
#define pers_zhc_jni_JNI_Struct_MODE_BIG_ENDIAN 0L
#undef pers_zhc_jni_JNI_Struct_MODE_LITTLE_ENDIAN
#define pers_zhc_jni_JNI_Struct_MODE_LITTLE_ENDIAN 1L
/*
 * Class:     pers_zhc_jni_JNI_Struct
 * Method:    packShort
 * Signature: (S[BII)V
 */
JNIEXPORT void JNICALL Java_pers_zhc_jni_JNI_00024Struct_packShort
  (JNIEnv *, jclass, jshort, jbyteArray, jint, jint);

/*
 * Class:     pers_zhc_jni_JNI_Struct
 * Method:    packInt
 * Signature: (I[BII)V
 */
JNIEXPORT void JNICALL Java_pers_zhc_jni_JNI_00024Struct_packInt
  (JNIEnv *, jclass, jint, jbyteArray, jint, jint);

/*
 * Class:     pers_zhc_jni_JNI_Struct
 * Method:    packLong
 * Signature: (J[BII)V
 */
JNIEXPORT void JNICALL Java_pers_zhc_jni_JNI_00024Struct_packLong
  (JNIEnv *, jclass, jlong, jbyteArray, jint, jint);

/*
 * Class:     pers_zhc_jni_JNI_Struct
 * Method:    packFloat
 * Signature: (F[BII)V
 */
JNIEXPORT void JNICALL Java_pers_zhc_jni_JNI_00024Struct_packFloat
  (JNIEnv *, jclass, jfloat, jbyteArray, jint, jint);

/*
 * Class:     pers_zhc_jni_JNI_Struct
 * Method:    packDouble
 * Signature: (D[BII)V
 */
JNIEXPORT void JNICALL Java_pers_zhc_jni_JNI_00024Struct_packDouble
  (JNIEnv *, jclass, jdouble, jbyteArray, jint, jint);

/*
 * Class:     pers_zhc_jni_JNI_Struct
 * Method:    unpackShort
 * Signature: ([BII)S
 */
JNIEXPORT jshort JNICALL Java_pers_zhc_jni_JNI_00024Struct_unpackShort
  (JNIEnv *, jclass, jbyteArray, jint, jint);

/*
 * Class:     pers_zhc_jni_JNI_Struct
 * Method:    unpackInt
 * Signature: ([BII)I
 */
JNIEXPORT jint JNICALL Java_pers_zhc_jni_JNI_00024Struct_unpackInt
  (JNIEnv *, jclass, jbyteArray, jint, jint);

/*
 * Class:     pers_zhc_jni_JNI_Struct
 * Method:    unpackLong
 * Signature: ([BII)J
 */
JNIEXPORT jlong JNICALL Java_pers_zhc_jni_JNI_00024Struct_unpackLong
  (JNIEnv *, jclass, jbyteArray, jint, jint);

/*
 * Class:     pers_zhc_jni_JNI_Struct
 * Method:    unpackFloat
 * Signature: ([BII)F
 */
JNIEXPORT jfloat JNICALL Java_pers_zhc_jni_JNI_00024Struct_unpackFloat
  (JNIEnv *, jclass, jbyteArray, jint, jint);

/*
 * Class:     pers_zhc_jni_JNI_Struct
 * Method:    unpackDouble
 * Signature: ([BII)D
 */
JNIEXPORT jdouble JNICALL Java_pers_zhc_jni_JNI_00024Struct_unpackDouble
  (JNIEnv *, jclass, jbyteArray, jint, jint);

#ifdef __cplusplus
}
#endif
#endif
