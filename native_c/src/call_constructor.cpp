/*
 * call_constructor.cpp
 *
 *  Created on: Jul 31, 2020
 *      Author: meisam
 */

#include "../header/test15_TestConstructorCall.h"

/*
 * Class:     test15_TestConstructorCall
 * Method:    createPerson
 * Signature: (Ljava/lang/String;I)Ltest15/Person;
 */
JNIEXPORT jobject JNICALL Java_test15_TestConstructorCall_createPerson
  (JNIEnv *jvm, jclass TestConstructorCall, jstring name, jint age) {
	// step 1: jclass of Person
	jclass person_class = jvm -> FindClass("test15/Person") ;
	// step 2: call constructor --> special method
	jmethodID constructor_id = jvm -> GetMethodID(person_class, "<init>", "(Ljava/lang/String;)V") ;
	// step 3: create new object
	jobject person_obj = jvm -> NewObject(person_class, constructor_id, name) ;
	return person_obj ;
}


