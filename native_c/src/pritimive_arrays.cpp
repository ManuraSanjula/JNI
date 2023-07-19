/*
 * pritimive_arrays.cpp
 *
 *  Created on: Jul 12, 2020
 *      Author: meisam
 */

#include "../header/test5_TestPrimitiveArrays.h"

/*
 * Class:     test5_TestPrimitiveArrays
 * Method:    linspace
 * Signature: (DDI)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_test5_TestPrimitiveArrays_linspace
  (JNIEnv *env, jobject TestPrimitiveArrays, jdouble start, jdouble end, jint num) {
	// create C++ array
//	jdouble carray[num] ; // allocate on stack: automatic, limited size or heap: manual, large size
	jdouble *carray = new jdouble[num] ; // heap allocation --> always returns memory address
	jdouble dx = (end-start)/(num-1.0) ;
	for(int i=0; i<num; i++) {
		carray[i] = start + i*dx ;
		// side note 1 :
		// pointer math --> carray+1 --> progress 8 bytes: dereference * access the value of the memory location
//		*(carray+i) = start + i*dx ;
	}
	// now create java array
//	jdoubleArray jarray = env -> NewDoubleArray(num) ;
//	env -> SetDoubleArrayRegion(jarray, 0, num, carray) ;

	jdoubleArray jarray = (*env).NewDoubleArray(num) ;
	(*env).SetDoubleArrayRegion(jarray, 0, num, carray) ;

	delete[] carray ;

	return jarray ;
}

/*
 * Class:     test5_TestPrimitiveArrays
 * Method:    func1
 * Signature: ([D)D
 */
JNIEXPORT jdouble JNICALL Java_test5_TestPrimitiveArrays_func1
  (JNIEnv *env, jobject TestPrimitiveArrays, jdoubleArray x) {
	// length of java array
	jint len = env -> GetArrayLength(x) ;
	// create a c++ array first
	jdouble carray[len] ;
	// copy java array to C++ array
	env -> GetDoubleArrayRegion(x, 0, len, carray) ;
	// perform operation on c++ array
	jdouble sum = 0.0 ;
	for(int i=0; i<len; i++)
		sum += carray[i] ;
	// return the result
	return sum ;
}

/*
 * Class:     test5_TestPrimitiveArrays
 * Method:    func2
 * Signature: ([D)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_test5_TestPrimitiveArrays_func2
  (JNIEnv *env, jobject TestPrimitiveArrays, jdoubleArray x) {
	// multiply all the elements by 2
	jint len = env -> GetArrayLength(x) ;
	// create c++ array
	jdouble carray[len] ;
	// copy elements
	env -> GetDoubleArrayRegion(x, 0, len, carray) ;
	// perform operation
	for(int i=0; i<len; i++)
		*(carray+i) *= 2 ;
	// return java array
	jdoubleArray y = env -> NewDoubleArray(len) ;
	env -> SetDoubleArrayRegion(y, 0, len, carray) ;
	return y ;
}




