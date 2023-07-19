/*
 * global_caching.cpp
 *
 *  Created on: Jul 29, 2020
 *      Author: meisam
 */

#include "../header/test11_TestGlobalCaching.h"

// global caching
static jclass person_class ;
static jfieldID first_name_id ;
static jfieldID last_name_id ;
static jfieldID eye_color_id ;
static jfieldID nationality_id ;
static jfieldID age_id ;
static jfieldID height_id ;

/*
 * Class:     test11_TestGlobalCaching
 * Method:    initIDs
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test11_TestGlobalCaching_initIDs
  (JNIEnv *env, jclass TestGlobalCaching) {
	person_class = env -> FindClass("test11/Person") ;
	first_name_id = env -> GetFieldID(person_class, "firstName", "Ljava/lang/String;") ;
	last_name_id = env -> GetFieldID(person_class, "lastName", "Ljava/lang/String;") ;
	eye_color_id = env -> GetFieldID(person_class, "eyeColor", "Ljava/lang/String;") ;
	nationality_id = env -> GetFieldID(person_class, "nationality", "Ljava/lang/String;") ;
	age_id = env -> GetFieldID(person_class, "age", "I") ;
	height_id = env -> GetFieldID(person_class, "height", "D") ;

	printf("executing initialization of IDs \n") ;
}


/*
 * Class:     test11_TestGlobalCaching
 * Method:    setProperties
 * Signature: (Ltest11/Person;Ljava/lang/String;Ljava/lang/String;ID)V
 */
JNIEXPORT void JNICALL Java_test11_TestGlobalCaching_setProperties
  (JNIEnv *env, jclass TestGlobalCaching, jobject person, jstring eyeColor,
		  jstring nationality, jint age, jdouble height) {
	env -> SetObjectField(person, eye_color_id, eyeColor) ;
	env -> SetObjectField(person, nationality_id, nationality) ;
	env -> SetIntField(person, age_id, age) ;
	env -> SetDoubleField(person, height_id, height) ;
}

/*
 * Class:     test11_TestGlobalCaching
 * Method:    setFirstName
 * Signature: (Ltest11/Person;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_test11_TestGlobalCaching_setFirstName
  (JNIEnv *env, jclass TestGlobalCaching, jobject person, jstring firstName) {
	env -> SetObjectField(person, first_name_id, firstName) ;
}

/*
 * Class:     test11_TestGlobalCaching
 * Method:    setLastName
 * Signature: (Ltest11/Person;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_test11_TestGlobalCaching_setLastName
  (JNIEnv *env, jclass TestGlobalCaching, jobject person, jstring lastName) {
	env -> SetObjectField(person, last_name_id, lastName) ;
}

