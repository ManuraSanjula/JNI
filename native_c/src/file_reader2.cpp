/*
 * file_reader2.cpp
 *
 *  Created on: Aug 22, 2020
 *      Author: meisam
 */

#include "../header/test23_FileReader2.h"
#include <string>
#include <fstream>
#include <map>

static jfieldID file_id ;
static jfieldID id_id ;
static std::map<jlong, std::ifstream*> file_streams ;

/*
 * Class:     test23_FileReader2
 * Method:    initIDs
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test23_FileReader2_initIDs
  (JNIEnv *jvm, jclass FileReader2_class) {
	file_id = jvm -> GetFieldID(FileReader2_class, "file", "Ljava/lang/String;") ;
	id_id = jvm -> GetFieldID(FileReader2_class, "id", "J") ; // long --> signature: J
}

/*
 * Class:     test23_FileReader2
 * Method:    open0
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test23_FileReader2_open0
  (JNIEnv *jvm, jobject FileReader2_obj) {
	// get id
	jlong id = jvm -> GetLongField(FileReader2_obj, id_id) ;
	printf("opening file stream with id %li\n", id) ;
	// get the c++ name of the file
	jstring file_name = (jstring) jvm -> GetObjectField(FileReader2_obj, file_id) ;
	const char* file_name_chars = jvm -> GetStringUTFChars(file_name, 0) ;
	// create ifstream
	std::ifstream* file_input = new std::ifstream ; // allocating on the heap
	file_streams.insert(std::pair<jlong,std::ifstream*>(id, file_input)) ;
	// open ifstream
	file_streams.at(id)->open(file_name_chars) ;
	// release the native heap for the file name
	jvm -> ReleaseStringUTFChars(file_name, file_name_chars) ;
}

/*
 * Class:     test23_FileReader2
 * Method:    close0
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test23_FileReader2_close0
  (JNIEnv *jvm, jobject FileReader2_obj) {
	// get id
	jlong id = jvm -> GetLongField(FileReader2_obj, id_id) ;
	(*file_streams.at(id)).close() ;
	// remove from map
	delete file_streams.at(id) ;
	file_streams.erase(id) ;
}

/*
 * Class:     test23_FileReader2
 * Method:    next0
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_test23_FileReader2_next0
  (JNIEnv *jvm, jobject FileReader2_obj) {
	// get id
	jlong id = jvm -> GetLongField(FileReader2_obj, id_id) ;
	std::string next ;
	(*file_streams.at(id)) >> next ;
	return jvm -> NewStringUTF(next.c_str()) ;
}

/*
 * Class:     test23_FileReader2
 * Method:    eof
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_test23_FileReader2_eof
  (JNIEnv *jvm, jobject FileReader2_obj) {
	// get id
	jlong id = jvm -> GetLongField(FileReader2_obj, id_id) ;
	return (*file_streams.at(id)).eof() ;
}
