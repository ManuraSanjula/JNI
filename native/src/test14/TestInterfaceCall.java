package test14;

public class TestInterfaceCall {

	static {
		System.loadLibrary("native_c");
	}

	public static native double callValue(MathFunction func, double x) ;
	public static native double callValueScaled(MathFunction func, double x) ;
	public static native MathFunction callFunctionScaled(MathFunction func) ;

	public static void test1() {
		MathFunction func1 = x -> Math.sin(x) ;
		double val1 = func1.value(2.1) ;
		System.out.println("Java result = " + val1);
		double result = callValue(func1, 2.1) ;
		System.out.println("C++ result = " + result);
	}

	public static void test2() {
		MathFunction func1 = x -> Math.sin(x) ;
		double val1 = func1.valueScaled(2.1) ;
		System.out.println("Java result = " + val1);
		double result = callValueScaled(func1, 2.1) ;
		System.out.println("C++ result = " + result);
	}

	public static void test3() {
		MathFunction func1 = x -> 2.0*x ;
		MathFunction func2 = MathFunction.functionScaled(func1) ;
		System.out.println("Java result = " + func2.value(2.1));
		MathFunction func3 = callFunctionScaled(x -> 2.0*x) ;
		double result = func3.value(2.1) ;
		System.out.println("C++ result = " + result);
	}

	public static void main(String[] args) {
//		test1() ;
//		test2() ;
		test3() ;
	}

}
