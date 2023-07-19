/*
 * object_arrays.cpp
 *
 *  Created on: Jul 12, 2020
 *      Author: meisam
 */

#include "../header/test5_TestObjectArray.h"

/*
 * Class:     test5_TestObjectArray
 * Method:    ones
 * Signature: (II)[[D
 */
JNIEXPORT jobjectArray JNICALL Java_test5_TestObjectArray_ones
  (JNIEnv *env, jobject TestObjectArray, jint rows, jint columns) {
	// 1. create object array
	jclass obj_class = env -> FindClass("[D") ;
	jobjectArray obj_array = env -> NewObjectArray(rows, obj_class, nullptr) ;
	// 2. create each element
	for(int k=0; k<rows; k++) {
		jdoubleArray jarray = env -> NewDoubleArray(columns) ;
		jdouble carray[columns] ; // created on the stack
		for(int i=0; i<columns; i++)
			carray[i] = 1.0 ;
		env -> SetDoubleArrayRegion(jarray, 0, columns, carray) ;
		env -> SetObjectArrayElement(obj_array, k, jarray) ;
	}
	return obj_array ;
}

/*
 * Class:     test5_TestObjectArray
 * Method:    max
 * Signature: ([[D)D
 */
//JNIEXPORT jdouble JNICALL Java_test5_TestObjectArray_max
//  (JNIEnv *env, jobject TestObjectArray, jobjectArray x) {
//	jdouble max_val = 0.0 ;
//	jint rows = env -> GetArrayLength(x) ;
//	for(int i=0; i<rows; i++) {
//		jdoubleArray jarray = (jdoubleArray)(env -> GetObjectArrayElement(x, i)) ;
//		jint columns = env -> GetArrayLength(jarray) ;
//		jdouble carray[columns] ; // allocating on the stack
//		env -> GetDoubleArrayRegion(jarray, 0, columns, carray) ;
//		for(int k=0; k<columns; k++) {
//			if(max_val < carray[k])
//				max_val = carray[k] ;
//		}
//	}
//
//	return max_val ;
//}


/*
 * Class:     test5_TestObjectArray
 * Method:    max0
 * Signature: ([D)D
 */
JNIEXPORT jdouble JNICALL Java_test5_TestObjectArray_max0
  (JNIEnv *env, jobject TestObjectArray, jdoubleArray x) {
	jint len = env -> GetArrayLength(x) ;
	jdouble carray[len] ;
	env -> GetDoubleArrayRegion(x, 0, len, carray) ;
	jdouble max_val = 0.0 ;
	for(int k=0; k<len; k++) {
		if(max_val < carray[k])
			max_val = carray[k] ;
	}
	return max_val ;
}

