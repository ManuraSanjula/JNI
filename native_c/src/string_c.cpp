/*
 * string_c.cpp
 *
 *  Created on: Jul 25, 2020
 *      Author: meisam
 */

#include "../header/test6_TestString.h"
#include <string>

/*
 * Class:     test6_TestString
 * Method:    sayHello
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_test6_TestString_sayHello
  (JNIEnv *env, jobject TestString) {
	// C-style string literal --> const char*
//	const char* text = "Hello World!!" ;
//	jstring str = env -> NewStringUTF(text) ;
//	return str ;
	// C++ style string --> std::string
	std::string text = "Hello World!!" ;
	return env -> NewStringUTF(text.c_str()) ;
}

/*
 * Class:     test6_TestString
 * Method:    println
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_test6_TestString_println
  (JNIEnv *env, jobject TestString, jstring jtext) {
//	jboolean isCopy ;
//	const char* text = env -> GetStringUTFChars(jtext, &isCopy) ;
//	printf("%s\n", text) ;
	const char* carray = env -> GetStringUTFChars(jtext, 0) ;
	printf("printing in c++ : %s\n", carray) ;
	env -> ReleaseStringUTFChars(jtext, carray) ;
}

/*
 * Class:     test6_TestString
 * Method:    concat
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_test6_TestString_concat
  (JNIEnv *env, jobject TestString, jstring jstr1, jstring jstr2) {
	const char* text1 = env -> GetStringUTFChars(jstr1, 0) ;
	std::string str1 = text1 ;
	const char* text2 = env -> GetStringUTFChars(jstr2, 0) ;
	std::string str2 = text2 ;
	std::string str_concat = str1 + str2 ;
	// release the native heap for character arrays
	env -> ReleaseStringUTFChars(jstr1, text1) ;
	env -> ReleaseStringUTFChars(jstr2, text2) ;
	// return a new java string
	return env -> NewStringUTF(str_concat.c_str()) ;
}


