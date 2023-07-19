/*
 * call_nonvirtual_method.cpp
 *
 *  Created on: Aug 2, 2020
 *      Author: meisam
 */

#include "../header/test17_TestInheritance.h"

/*
 * Class:     test17_TestInheritance
 * Method:    callSpeak
 * Signature: (Ltest17/Animal;)V
 */
JNIEXPORT void JNICALL Java_test17_TestInheritance_callSpeak
  (JNIEnv *jvm, jclass TestInheritance, jobject animal) {
	jclass animal_class = jvm -> FindClass("test17/Animal") ;
	jclass cat_class = jvm -> FindClass("test17/Cat") ;
	jmethodID animal_speak_id = jvm -> GetMethodID(animal_class, "speak", "()V") ;
	jmethodID cat_speak_id = jvm -> GetMethodID(cat_class, "speak", "()V") ;
	// case 1: virtual invokation --> we want to use Polymorphism
//	jvm -> CallVoidMethod(animal, animal_speak_id) ;
	// case 2: nonvirtual call
//	jvm -> CallNonvirtualVoidMethod(animal, animal_class, animal_speak_id) ;
	jvm -> CallNonvirtualVoidMethod(animal, cat_class, cat_speak_id) ;
}


