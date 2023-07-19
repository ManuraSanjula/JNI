package test2;

public class Overload {

//	public native double my_func(double x) ;
//	// Java_test2_Overload_my_1func__D
//
//	public native double my_func(String text) ;
//	// Java_test2_Overload_my_1func__Ljava_lang_String_2

	public native double func(double x) ;
	// Java_test2_Overload_func__D

	public native double func(My_Class obj) ;
	// __Ltest2_My_1Class_2
	// __Ltest2_My_1Class_2

}
