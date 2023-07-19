/*
 * method_invokation.cpp
 *
 *  Created on: Jul 29, 2020
 *      Author: meisam
 */

#include "../header/test12_TestMethodCall.h"

/*
 * Class:     test12_TestMethodCall
 * Method:    printPersonName
 * Signature: (Ltest12/Person;)V
 */
JNIEXPORT void JNICALL Java_test12_TestMethodCall_printPersonName
  (JNIEnv *env, jclass TestMethodCall, jobject person) {
	jclass person_class = env -> GetObjectClass(person) ;
	jmethodID print_name_id = env -> GetMethodID(person_class, "printName", "()V") ;
	env -> CallVoidMethod(person, print_name_id) ;

	jmethodID print_info_id = env -> GetMethodID(person_class, "printInfo", "(I)Ljava/lang/String;") ;
	jobject info_obj = env -> CallObjectMethod(person, print_info_id, 23) ;
	jstring info = (jstring) info_obj ;
	const char* info_array = env -> GetStringUTFChars(info, 0) ;
	printf("info = %s", info_array) ;
	env -> ReleaseStringUTFChars(info, info_array) ;
}


