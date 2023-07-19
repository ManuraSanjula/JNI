/*
 * call_generics_method.cpp
 *
 *  Created on: Aug 4, 2020
 *      Author: meisam
 */

#include "../header/test19_TestGenericsMethod.h"

/*
 * Class:     test19_TestGenericsMethod
 * Method:    printInfoNative
 * Signature: (Ljava/lang/Number;)V
 */
JNIEXPORT void JNICALL Java_test19_TestGenericsMethod_printInfoNative
  (JNIEnv *jvm, jclass TestGenericsMethod, jobject number) {
	// what is the type of value???????
	// Double --> doubleValue()
	// Integer -->  intValue()
	jclass Number_class = jvm -> FindClass("java/lang/Number") ;
	jmethodID doubleValue_id = jvm -> GetMethodID(Number_class, "doubleValue", "()D") ;
	jdouble value = jvm -> CallDoubleMethod(number, doubleValue_id) ;
	printf("value = %f\n", value) ;

	// do some tests
	jclass Double_class = jvm -> FindClass("java/lang/Double") ;
	jclass Integer_class = jvm -> FindClass("java/lang/Integer") ;
	jboolean is_int = jvm -> IsInstanceOf(number, Integer_class) ;
	if(is_int)
		printf("the type is Integer\n") ;
	else
		printf("the type is Double\n") ;

}


