/*
 * method_local_inner_class.cpp
 *
 *  Created on: Aug 16, 2020
 *      Author: meisam
 */

#include "../header/Student.h"

/*
 * Class:     Student
 * Method:    printInfo
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test22_TestMethodLocal_000241Student_printInfo
  (JNIEnv *jvm, jobject Student_obj) {
	jclass Student_class = jvm -> GetObjectClass(Student_obj) ;
	jfieldID name_id = jvm -> GetFieldID(Student_class, "name", "Ljava/lang/String;") ;
	jfieldID age_id = jvm -> GetFieldID(Student_class, "age", "I") ;
	jint age = jvm -> GetIntField(Student_obj, age_id) ;
	jstring name = (jstring) jvm -> GetObjectField(Student_obj, name_id) ;
	const char* name_chars = jvm -> GetStringUTFChars(name, 0) ;
	printf("%s's age is %d", name_chars, age) ;
	jvm -> ReleaseStringUTFChars(name, name_chars) ;
}


