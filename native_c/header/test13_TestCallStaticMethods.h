/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class test13_TestCallStaticMethods */

#ifndef _Included_test13_TestCallStaticMethods
#define _Included_test13_TestCallStaticMethods
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     test13_TestCallStaticMethods
 * Method:    callPrintInfo
 * Signature: (Ltest13/Person;)V
 */
JNIEXPORT void JNICALL Java_test13_TestCallStaticMethods_callPrintInfo
  (JNIEnv *, jclass, jobject);

/*
 * Class:     test13_TestCallStaticMethods
 * Method:    callSetInfo
 * Signature: (Ltest13/Person;Ljava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_test13_TestCallStaticMethods_callSetInfo
  (JNIEnv *, jclass, jobject, jstring, jint);

/*
 * Class:     test13_TestCallStaticMethods
 * Method:    printMemory
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test13_TestCallStaticMethods_printMemory
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif