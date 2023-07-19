/*
 * call_inner_classes.cpp
 *
 *  Created on: Aug 16, 2020
 *      Author: meisam
 */

#include "../header/test22_Person_Book.h"
#include "../header/test22_Person_Bag.h"

/*
 * Class:     test22_Person_Book
 * Method:    printTitle
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test22_Person_00024Book_printTitle
  (JNIEnv *jvm, jobject Person_Book) {
	// we want to call "printTitle" method
	// step 1:
//	jclass Person_Book_class = jvm -> FindClass("test22/Person$Book") ;
	jclass Person_Book_class = jvm -> GetObjectClass(Person_Book) ;
	// step 2: get title id
	jfieldID title_id = jvm -> GetFieldID(Person_Book_class, "title", "Ljava/lang/String;") ;
	// step 3: get the title
	jobject title_obj = jvm -> GetObjectField(Person_Book, title_id) ;
	jstring title = (jstring) title_obj ;
	const char* title_chars = jvm -> GetStringUTFChars(title, 0) ;
	printf("title = %s", title_chars) ;
	jvm -> ReleaseStringUTFChars(title, title_chars) ;
}

/*
 * Class:     test22_Person_Bag
 * Method:    printSize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test22_Person_00024Bag_printSize__
  (JNIEnv *jvm, jobject Person_Bag_obj) {
	jclass Person_Bag_class = jvm -> FindClass("test22/Person$Bag") ;
//	jclass Person_Bag_class = jvm -> GetObjectClass(Person_Bag_obj) ;
	// size id
	jfieldID size_id = jvm -> GetFieldID(Person_Bag_class, "size", "I") ;
	// get the actual value of the field
	jint size = jvm -> GetIntField(Person_Bag_obj, size_id) ;
	printf("size = %d\n", size) ;
}

/*
 * Class:     test22_Person_Bag
 * Method:    printSize
 * Signature: (Ltest22/Person$Bag;)V
 */
JNIEXPORT void JNICALL Java_test22_Person_00024Bag_printSize__Ltest22_Person_00024Bag_2
  (JNIEnv *jvm, jclass Person_Bag, jobject bag_obj) {
	// size id
	jfieldID size_id = jvm -> GetFieldID(Person_Bag, "size", "I") ;
	// get the actual value of the field
	jint size = jvm -> GetIntField(bag_obj, size_id) ;
	printf("size = %d\n", size) ;
}

