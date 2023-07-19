package test5;

import java.util.Arrays;

public class TestPrimitiveArrays {

	static {
		System.loadLibrary("native_c");
	}

	// 1. create a java array in C++ and return to java
	public native double[] linspace(double start, double end, int num) ;
	// linspace(0, 5, 5) --> dx = (5-0)/4 ; [0, 0+dx, 0+2*dx, 0+3*dx, 0+4*dx]
	// last element = start + (num-1)*dx --> dx = (end-start)/(num-1)

	// 2. copy java array into c++ array and return a result
	public native double func1(double[] x) ;

	public native double[] func2(double[] x) ;


	public static void main(String[] args) {
		TestPrimitiveArrays test = new TestPrimitiveArrays() ;
		double[] result = test.linspace(0.0, 5.0, 5_000_000) ; // dx = 5/4 = 1.25
		System.out.println(Arrays.toString(result));
		double sum = test.func1(result) ;
		System.out.println(sum);
		double[] result2 = test.func2(result) ;
		System.out.println(Arrays.toString(result2));
	}

}
