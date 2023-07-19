/*
 * generic_classes.cpp
 *
 *  Created on: Aug 6, 2020
 *      Author: meisam
 */


#include "../header/test19_TestGenericClass.h"

/*
 * Class:     test19_TestGenericClass
 * Method:    callPrintMembers
 * Signature: (Ltest19/Group;)V
 */
JNIEXPORT void JNICALL Java_test19_TestGenericClass_callPrintMembers
  (JNIEnv *jvm, jclass TestGenericClass, jobject group) {
	// group --> printMembers()
	// We do not specify type parameter for Group --> classpath has no info about <T>
	jclass Group_class = jvm -> FindClass("test19/Group") ;
	jmethodID printMembers_id = jvm -> GetMethodID(Group_class, "printMembers", "()V") ;
	jvm -> CallVoidMethod(group, printMembers_id) ;
	// accessing members field
	jfieldID members_id = jvm -> GetFieldID(Group_class, "members", "[Ljava/lang/Object;") ;
	jobject members_obj = jvm -> GetObjectField(group, members_id) ;
	jobjectArray members_array = (jobjectArray) members_obj ;
	jint len = jvm -> GetArrayLength(members_array) ;
	jclass Person_class = jvm -> FindClass("test19/Person") ;
	for(int i=0; i<len; i++) {
		jobject member = jvm -> GetObjectArrayElement(members_array, i) ;
		jboolean is_person = jvm -> IsInstanceOf(member, Person_class) ;
		if(is_person)
			printf("element %d is a Person object\n", i) ;
	}
}

/*
 * Class:     test19_TestGenericClass
 * Method:    callPrintMembersParameterized
 * Signature: (Ltest19/Group;)V
 */
JNIEXPORT void JNICALL Java_test19_TestGenericClass_callPrintMembersParameterized
  (JNIEnv *jvm, jclass TestGenericClass, jobject group) {
	jclass Group_class = jvm -> FindClass("test19/Group") ;
	jmethodID printMembers_id = jvm -> GetMethodID(Group_class, "printMembers", "()V") ;
	jvm -> CallVoidMethod(group, printMembers_id) ;
	// accessing members field
	jfieldID members_id = jvm -> GetFieldID(Group_class, "members", "[Ljava/lang/Object;") ;
	jobject members_obj = jvm -> GetObjectField(group, members_id) ;
	jobjectArray members_array = (jobjectArray) members_obj ;
	jint len = jvm -> GetArrayLength(members_array) ;
	jclass Person_class = jvm -> FindClass("test19/Person") ;
	for(int i=0; i<len; i++) {
		jobject member = jvm -> GetObjectArrayElement(members_array, i) ;
		jboolean is_person = jvm -> IsInstanceOf(member, Person_class) ;
		if(is_person)
			printf("element %d is a Person object\n", i) ;
		else
			printf("element %d is NOT Person object\n", i) ;
	}
}

