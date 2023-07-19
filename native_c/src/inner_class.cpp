/*
 * inner_class.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: meisam
 */

#include "../header/test22_TestInnerClass.h"

/*
 * Class:     test22_TestInnerClass
 * Method:    createBag
 * Signature: ()Ltest22/Person/Bag;
 */
JNIEXPORT jobject JNICALL Java_test22_TestInnerClass_createBag
  (JNIEnv *jvm, jclass TestInnerClass) {
	// Bag is static inner class: Person$Bag
	jclass Bag_class = jvm -> FindClass("test22/Person$Bag") ;
	// constructor is a special method INVOKESPECIA
	jmethodID constructor_id = jvm -> GetMethodID(Bag_class, "<init>", "(I)V") ;
	// instantiate
	jobject bag_obj = jvm -> NewObject(Bag_class, constructor_id, 32) ;
	return bag_obj ;
}

/*
 * Class:     test22_TestInnerClass
 * Method:    createBook
 * Signature: (Ltest22/Person;)Ltest22/Person/Book;
 */
JNIEXPORT jobject JNICALL Java_test22_TestInnerClass_createBook
  (JNIEnv *jvm, jclass TestInnerClass, jobject person) {
	jclass Book_class = jvm -> FindClass("test22/Person$Book") ;
	jmethodID constructor_id = jvm -> GetMethodID(Book_class, "<init>", "(Ltest22/Person;Ljava/lang/String;)V") ;
	jstring book_name = jvm -> NewStringUTF("War and Peace in C++") ;
	jobject book_obj = jvm -> NewObject(Book_class, constructor_id, person, book_name) ;
	return book_obj ;
}

