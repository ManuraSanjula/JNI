package test5;

import java.util.Arrays;

public class TestObjectArray {

	static {
		System.loadLibrary("native_c");
	}

	// double[] array --> array[i]=0.0
	// boolean[] array --> array[i]=false
	// a matrix: a_ij = 1.0
	public native double[][] ones(int rows, int columns) ;
//	public native double[][] ones(int rows, int columns, double[][] args) ;
	// Java_test5_TestObjectArray_ones__II_3_3D
	// Java_test5_TestObjectArray_ones__II_3_3D

	private native double max0(double[] x) ;

	public double max(double[][] x) {
		double max = 0 ;
		for(int i=0; i<x.length; i++) {
			double maxRow = max0(x[i]) ;
			if(max < maxRow)
				max = maxRow ;
		}
		return max ;
	}

	public static void main(String[] args) {
		TestObjectArray test = new TestObjectArray() ;
		double[][] result = test.ones(5, 4) ;
		System.out.println(Arrays.deepToString(result));
		double[][] array = {{1.1, 15.0, -2.0}, {-2.0, 13.1}} ;
		double max = test.max(array) ;
		System.out.println(max);
	}

}
