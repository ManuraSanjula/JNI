/*
 * static_fields.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: meisam
 */

#include "../header/test8_TestStaticFields.h"

/*
 * Class:     test8_TestStaticFields
 * Method:    printPersonInfo
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test8_TestStaticFields_printPersonInfo
  (JNIEnv *env, jobject TestStaticFields) {
	// step 1: jclass of Person (find on the classpath)
	jclass person_class = env -> FindClass("test8/Person") ;
	// step 2: jfieldID
	jfieldID name_fid = env -> GetStaticFieldID(person_class, "name", "Ljava/lang/String;") ;
	jfieldID age_fid = env -> GetStaticFieldID(person_class, "age", "I") ;
	// step 3: get the values
	jint age = env -> GetStaticIntField(person_class, age_fid) ;
	printf("age = %d \n", age) ;
	jobject name_obj = env -> GetStaticObjectField(person_class, name_fid) ;
	jstring name = (jstring) name_obj ;
	const char* name_array = env -> GetStringUTFChars(name, 0) ;
	printf("name = %s\n", name_array) ;
	env -> ReleaseStringUTFChars(name, name_array) ;
}


