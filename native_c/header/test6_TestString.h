/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class test6_TestString */

#ifndef _Included_test6_TestString
#define _Included_test6_TestString
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     test6_TestString
 * Method:    sayHello
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_test6_TestString_sayHello
  (JNIEnv *, jobject);

/*
 * Class:     test6_TestString
 * Method:    println
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_test6_TestString_println
  (JNIEnv *, jobject, jstring);

/*
 * Class:     test6_TestString
 * Method:    concat
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_test6_TestString_concat
  (JNIEnv *, jobject, jstring, jstring);

#ifdef __cplusplus
}
#endif
#endif