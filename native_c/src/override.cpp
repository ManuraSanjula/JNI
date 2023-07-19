
#include "../header/test_TestOverrideSuperClass.h"
#include "../header/test_TestOverrideSubClass.h"

/*
 * Class:     test_TestOverrideSuperClass
 * Method:    func
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_test_TestOverrideSuperClass_func
  (JNIEnv *env, jobject TestOverrideSuperClass, jdouble x) {
	printf("inside super class\n") ;
	return x ;
}


/*
 * Class:     test_TestOverrideSubClass
 * Method:    func
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_test_TestOverrideSubClass_func
  (JNIEnv *env, jobject TestOverrideSubClass, jdouble x) {
	printf("inside sub class\n") ;
	return 2.0*x ;
}





