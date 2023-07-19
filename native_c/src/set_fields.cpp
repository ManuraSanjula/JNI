/*
 * set_fields.cpp
 *
 *  Created on: Jul 27, 2020
 *      Author: meisam
 */

#include "../header/test9_TestSetFields.h"

/*
 * Class:     test9_TestSetFields
 * Method:    setNameAndAge
 * Signature: (Ltest9/Person;Ljava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_test9_TestSetFields_setNameAndAge
  (JNIEnv *env, jobject TestSetFields, jobject person, jstring name, jint age) {
	// step 1: get jclass
	jclass person_class = env -> FindClass("test9/Person") ;
	// stpe 2: get field IDs
	jfieldID name_id = env -> GetFieldID(person_class, "name", "Ljava/lang/String;") ;
	jfieldID age_id = env -> GetFieldID(person_class, "age", "I") ;
	jfieldID phone_num_id = env -> GetStaticFieldID(person_class, "phoneNumber", "I") ;
	// step 3: ask jvm to set the fields
	env -> SetObjectField(person, name_id, name) ;
	env -> SetIntField(person, age_id, 31) ;
	env -> SetStaticIntField(person_class, phone_num_id, 111) ;
}


