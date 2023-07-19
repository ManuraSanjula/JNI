package test16;

import java.util.List;

public class AiryFunction {

	private AiryFunction() {

	}

//	public static native double ai(double x) ; // Ai(x)
	public static native double bi(double x) ; // Bi(x)

//	public static native double ai(Double x) ; // wrapper class or boxed value
	public static native double[] ai(List<Double> x) ; // java type eraser
//	public static native double ai(double[] x) ;

}
