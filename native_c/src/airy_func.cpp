/*
 * airy_func.cpp
 *
 *  Created on: Aug 1, 2020
 *      Author: meisam
 */

#include "../header/test16_AiryFunction.h"
#include <gsl/gsl_sf_airy.h>



///*
// * Class:     test16_AiryFunction
// * Method:    ai
// * Signature: (D)D
// */
//JNIEXPORT jdouble JNICALL Java_test16_AiryFunction_ai
//  (JNIEnv *jvm, jclass AiryFunction, jdouble x) {
//	return gsl_sf_airy_Ai(x, GSL_PREC_DOUBLE) ;
//}

/*
 * Class:     test16_AiryFunction
 * Method:    bi
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_test16_AiryFunction_bi
  (JNIEnv *jvm, jclass AiryFunction, jdouble x) {
	return gsl_sf_airy_Bi(x, GSL_PREC_DOUBLE) ;
}

///*
// * Class:     test16_AiryFunction
// * Method:    ai
// * Signature: (Ljava/lang/Double;)D
// */
//JNIEXPORT jdouble JNICALL Java_test16_AiryFunction_ai
//  (JNIEnv *jvm, jclass AiryFunction, jobject x) {
//	// step 1: we have to get the double value of x first
//	// invoke the method doubleValue on x object
//	static jclass Double_class = jvm -> GetObjectClass(x) ; // FindClass("java/lang/Double")
//	static jmethodID doubleValue_id = jvm -> GetMethodID(Double_class, "doubleValue", "()D") ;
//	// do not use static on this jdouble
//	jdouble x_value = jvm -> CallDoubleMethod(x, doubleValue_id) ;
//	return gsl_sf_airy_Ai(x_value, GSL_PREC_DOUBLE) ;
//}

/*
 * Class:     test16_AiryFunction
 * Method:    ai
 * Signature: (Ljava/util/List;)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_test16_AiryFunction_ai
  (JNIEnv *jvm, jclass AiryFunction, jobject x_list) {
	static jclass List_class = jvm -> FindClass("java/util/List") ;
	static jmethodID get_id = jvm -> GetMethodID(List_class, "get", "(I)Ljava/lang/Object;") ;
	static jmethodID size_id = jvm -> GetMethodID(List_class, "size", "()I") ;
	jint len = jvm -> CallIntMethod(x_list, size_id) ;
	jdouble vals[len] ;
	printf("size of list = %d\n", len) ;
	static jclass Double_class = jvm -> FindClass("java/lang/Double") ;
	static jmethodID doubleValue_id = jvm -> GetMethodID(Double_class, "doubleValue", "()D") ;
	jobject value_obj = nullptr ;
	jdouble value = 0.0 ;
	for(int i=0; i<len; i++) {
		// call get(i) on x_list --> returns object --> Double
		value_obj = jvm -> CallObjectMethod(x_list, get_id, i) ;
		// Double --> doubleValue
		value = jvm -> CallDoubleMethod(value_obj, doubleValue_id) ;
		printf("value at index %d = %f\n", i, value) ;
	}
}

