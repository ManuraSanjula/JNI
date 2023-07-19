/*
 * call_reflection.cpp
 *
 *  Created on: Aug 7, 2020
 *      Author: meisam
 */

#include "../header/test20_TestJNIReflection.h"

/*
 * Class:     test20_TestJNIReflection
 * Method:    callNameField
 * Signature: (Ltest20/Person;Ljava/lang/reflect/Field;)V
 */
JNIEXPORT void JNICALL Java_test20_TestJNIReflection_callNameField
  (JNIEnv *jvm, jclass TestJNIReflection, jobject person, jobject field) {
	jclass Person_class = jvm -> FindClass("test20/Person") ;
	jclass Field_class = jvm -> FindClass("java/lang/reflect/Field") ;
	jfieldID name_id = jvm -> FromReflectedField(field) ;
//	jmethodID get_id = jvm -> GetMethodID(Field_class, "get", "(Ljava/lang/Object;)Ljava/lang/Object;") ;
//	jobject name_obj = jvm -> CallObjectMethod(field, get_id, person) ;
//	jstring name = (jstring) name_obj ;
//	const char* name_array = jvm -> GetStringUTFChars(name, 0) ;
//	printf("field value = %s", name_array) ;
//	jvm -> ReleaseStringUTFChars(name, name_array) ;

	jobject name_obj = jvm -> GetObjectField(person, name_id) ;
	jstring name = (jstring) name_obj ;
	const char* name_array = jvm -> GetStringUTFChars(name, 0) ;
	printf("field value = %s", name_array) ;
	jvm -> ReleaseStringUTFChars(name, name_array) ;
}

/*
 * Class:     test20_TestJNIReflection
 * Method:    callMethod
 * Signature: (Ltest20/Person;Ljava/lang/reflect/Method;)V
 */
JNIEXPORT void JNICALL Java_test20_TestJNIReflection_callMethod
  (JNIEnv *jvm, jclass TestJNIReflection, jobject person, jobject method) {
	jmethodID calculate_id = jvm -> FromReflectedMethod(method) ;
	jint result = jvm -> CallIntMethod(person, calculate_id) ;
	printf("result of calculate = %d", result) ;
}




