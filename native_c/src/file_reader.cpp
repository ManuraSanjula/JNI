/*
 * file_reader.cpp
 *
 *  Created on: Aug 20, 2020
 *      Author: meisam
 */

#include "../header/test23_FileReader.h"
#include <string>
#include <fstream>

static jfieldID file_id ;
static std::ifstream file_input ; // native file stream

/*
 * Class:     test23_FileReader
 * Method:    initIDs
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test23_FileReader_initIDs
  (JNIEnv *jvm, jclass FileReader_class) {
	file_id = jvm -> GetFieldID(FileReader_class, "file", "Ljava/lang/String;") ;
}

/*
 * Class:     test23_FileReader
 * Method:    open0
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test23_FileReader_open0
  (JNIEnv *jvm, jobject FileReader_obj) {
	// get the c++ name of the file
	jstring file_name = (jstring) jvm -> GetObjectField(FileReader_obj, file_id) ;
	const char* file_name_chars = jvm -> GetStringUTFChars(file_name, 0) ;
	// open it
	file_input.open(file_name_chars) ;
	// release the native heap for the file name
	jvm -> ReleaseStringUTFChars(file_name, file_name_chars) ;
}

/*
 * Class:     test23_FileReader
 * Method:    close0
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test23_FileReader_close0
  (JNIEnv *jvm, jobject FileReader_obj) {
	file_input.close() ;
}

/*
 * Class:     test23_FileReader
 * Method:    next0
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_test23_FileReader_next0
  (JNIEnv *jvm, jobject FileReader_obj) {
	std::string next ;
	file_input >> next ; // operator >> is overloaded. reads the next word and puts it inside std string
	return jvm -> NewStringUTF(next.c_str()) ; // can only pass const char*
}

/*
 * Class:     test23_FileReader
 * Method:    eof
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_test23_FileReader_eof
  (JNIEnv *jvm, jobject FileReader_obj) {
	return file_input.eof() ;
}


