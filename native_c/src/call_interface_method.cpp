/*
 * call_interface_method.cpp
 *
 *  Created on: Jul 31, 2020
 *      Author: meisam
 */

#include "../header/test14_TestInterfaceCall.h"

/*
 * Class:     test14_TestInterfaceCall
 * Method:    callValue
 * Signature: (Ltest14/MathFunction;D)D
 */
JNIEXPORT jdouble JNICALL Java_test14_TestInterfaceCall_callValue
  (JNIEnv *jvm, jclass TestInterfaceCall, jobject func, jdouble x) {
	// step 1: get the jclass of the interface
	jclass mathFunction_class = jvm -> FindClass("test14/MathFunction") ;
	// step 2: method id
	jmethodID value_id = jvm -> GetMethodID(mathFunction_class, "value", "(D)D") ;
	// step 3: call it
	jdouble result = jvm -> CallDoubleMethod(func, value_id, x) ;
	return result ;
}

/*
 * Class:     test14_TestInterfaceCall
 * Method:    callValueScaled
 * Signature: (Ltest14/MathFunction;D)D
 */
JNIEXPORT jdouble JNICALL Java_test14_TestInterfaceCall_callValueScaled
  (JNIEnv *jvm, jclass TestInterfaceCall, jobject func, jdouble x) {
	jclass mathFunction_class = jvm -> FindClass("test14/MathFunction") ;
	jmethodID value_id = jvm -> GetMethodID(mathFunction_class, "valueScaled", "(D)D") ;
	jdouble result = jvm -> CallDoubleMethod(func, value_id, x) ;
	return result ;
}

/*
 * Class:     test14_TestInterfaceCall
 * Method:    callFunctionScaled
 * Signature: (Ltest14/MathFunction;)Ltest14/MathFunction;
 */
JNIEXPORT jobject JNICALL Java_test14_TestInterfaceCall_callFunctionScaled
  (JNIEnv *jvm, jclass TestInterfaceCall, jobject func) {
	jclass mathFunction_class = jvm -> FindClass("test14/MathFunction") ;
	jmethodID functionScaled_id = jvm -> GetStaticMethodID(mathFunction_class, "functionScaled", "(Ltest14/MathFunction;)Ltest14/MathFunction;") ;
	jobject result = jvm -> CallStaticObjectMethod(mathFunction_class, functionScaled_id, func) ;
	return result ;
}

