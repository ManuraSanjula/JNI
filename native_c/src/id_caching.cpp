/*
 * id_caching.cpp
 *
 *  Created on: Jul 27, 2020
 *      Author: meisam
 */

#include "../header/test10_TestMethodCatching.h"




/*
 * Class:     test10_TestMethodCatching
 * Method:    setAge
 * Signature: (Ltest10/Person;I)V
 */
JNIEXPORT void JNICALL Java_test10_TestMethodCatching_setAge
  (JNIEnv *env, jclass TestMethodCatching, jobject person, jint age) {
	// initialization only happens once (first time)
	static jclass person_class = env -> FindClass("test10/Person") ;
	static jfieldID age_id = env -> GetFieldID(person_class, "age", "I") ;
	env -> SetIntField(person, age_id, age) ;
}

/*
 * Class:     test10_TestMethodCatching
 * Method:    setName
 * Signature: (Ltest10/Person;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_test10_TestMethodCatching_setName
  (JNIEnv *env, jclass TestMethodCatching, jobject person, jstring name) {
	// initialization only happens once (first time)
	static jclass person_class = env -> FindClass("test10/Person") ;
	static jfieldID name_id = env -> GetFieldID(person_class, "name", "Ljava/lang/String;") ;
	env -> SetObjectField(person, name_id, name) ;
}

