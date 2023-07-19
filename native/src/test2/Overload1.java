package test2;

public class Overload1 { // test2/Overload1

	public native double func(double x) ; // __D
	public native double[] func(double[] x) ; // __[D --> ___3D
	public native double func(double[] x, String text) ; // [DLjava/lang/String; --> _3DLjava_lang_String_2
	// [ --> _3, ; --> _2, / --> _

	public native void func(Overload1 obj, Overload1 obj2) ; // __Ltest2/Overload1; --> __Ltest2_Overload1_2
	// __Ltest2/Overload1;Ltest2/Overload1; -->
	// __Ltest2_Overload1_2Ltest2_Overload1_2
	// __Ltest2_Overload1_2Ltest2_Overload1_2

	// question: _2 & _3 --> _1 ???
	// java convention: JNI --> _1 is replacing _ in method name
	// we DO NOT use _ in method names in java
	// we use CAMEL CASE naming convention
	// my_func --> myFunc
	// my_func --> my_1func

}
