package test2;

public class Overload2 {

	public native double func(double x) ; // instance method
	// Java_test2_Overload2_func__D (JNIEnv *, jobject, jdouble)

	public static native double func(double[] x) ;
	// Java_test2_Overload2_func___3D (JNIEnv *, jclass, jdoubleArray)

}
