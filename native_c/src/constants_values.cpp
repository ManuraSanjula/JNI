/*
 * constants_values.cpp
 *
 *  Created on: Aug 9, 2020
 *      Author: meisam
 */

#include <iostream>
#include "../header/test21_ConstantsClass.h"

/*
 * Class:     test21_ConstantsClass
 * Method:    printValues
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_test21_ConstantsClass_printValues
  (JNIEnv *jvm, jclass ConstantsClass) {
//	printf("%li", test21_ConstantsClass_INT_VALUE) ;
	std::cout << test21_ConstantsClass_INT_VALUE << std::endl ;
	std::cout << test21_ConstantsClass_LONG_VALUE << std::endl ;
}


