/*
 * call_static_methods.cpp
 *
 *  Created on: Jul 30, 2020
 *      Author: meisam
 */

#include "../header/test13_TestCallStaticMethods.h"

/*
 * Class:     test13_TestCallStaticMethods
 * Method:    callPrintInfo
 * Signature: (Ltest13/Person;)V
 */
JNIEXPORT void JNICALL Java_test13_TestCallStaticMethods_callPrintInfo
  (JNIEnv *jvm, jclass TestCallStaticMethods, jobject person) {
	// goal: call "printInfo(person)" in the Person class
	// step 1: get jclass
	jclass person_class = jvm -> FindClass("test13/Person") ;
	// step 2: get method identifier --> static
	jmethodID print_info_id = jvm -> GetStaticMethodID(person_class, "printInfo", "(Ltest13/Person;)V") ;
	// step 3: ask jvm to call the method
	jvm -> CallStaticVoidMethod(person_class, print_info_id, person) ;
}

/*
 * Class:     test13_TestCallStaticMethods
 * Method:    callSetInfo
 * Signature: (Ltest13/Person;Ljava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_test13_TestCallStaticMethods_callSetInfo
  (JNIEnv *jvm, jclass TestCallStaticMethods, jobject person, jstring name, jint age) {
	jclass person_class = jvm -> FindClass("test13/Person") ;
	jmethodID set_info_id = jvm -> GetStaticMethodID(person_class, "setInfo", "(Ltest13/Person;Ljava/lang/String;I)V") ;
	jvm -> CallStaticVoidMethod(person_class, set_info_id, person, name, age) ;
}

/*
 * Class:     test13_TestCallStaticMethods
 * Method:    printMemory
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test13_TestCallStaticMethods_printMemory
  (JNIEnv *jvm, jclass TestCallStaticMethods) {
	// Runtime --> call a method "getRuntime()"
	jclass runtime_class = jvm -> FindClass("java/lang/Runtime") ;
	jmethodID getRuntime_id = jvm -> GetStaticMethodID(runtime_class, "getRuntime", "()Ljava/lang/Runtime;") ;
	jobject runtime_obj = jvm -> CallStaticObjectMethod(runtime_class, getRuntime_id) ;
	// call "freeMemory()"
	jmethodID freeMemory_id = jvm -> GetMethodID(runtime_class, "freeMemory", "()J") ;
	jlong value = jvm -> CallLongMethod(runtime_obj, freeMemory_id) ;
	printf("Free memory = %ld MB", value/(1024*1024)) ;
}



