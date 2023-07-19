/*
 * primitives.cpp
 *
 *  Created on: Jul 12, 2020
 *      Author: meisam
 */

#include "../header/test4_TestPrimitive.h"

/*
 * Class:     test4_TestPrimitive
 * Method:    isOdd
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_test4_TestPrimitive_isOdd
  (JNIEnv *env, jobject TestPrimitive, jint x) {
//	bool result = x%2 ? false : true ;
	jboolean result = x%2 ? false : true ;
	return result ;
}

/*
 * Class:     test4_TestPrimitive
 * Method:    func1
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_test4_TestPrimitive_func1
  (JNIEnv *env, jobject TestPrimitive, jdouble x) {
//	double y = 2.0*x ;
//	return y ;
	jdouble y = 2.0 *x ;
	return y ;
}

/*
 * Class:     test4_TestPrimitive
 * Method:    func2
 * Signature: (B)F
 */
JNIEXPORT jfloat JNICALL Java_test4_TestPrimitive_func2
  (JNIEnv *env, jobject TestPrimitive, jbyte x) {
	jfloat y = 0.22*(x + 1.1) ;
	return y ;
}

