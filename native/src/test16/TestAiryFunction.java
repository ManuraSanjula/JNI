package test16;

import java.util.ArrayList;
import java.util.List;

public class TestAiryFunction {

	static {
		System.loadLibrary("native_c");
	}

//	public static void test1() {
//		double x = -1.1 ;
//		double result = AiryFunction.ai(x) ;
//		System.out.println(result);
//		System.out.println(AiryFunction.bi(x));
//	}
//
//	public static void test2() {
//		Double x = -1.1 ; // auto boxing
////		double y = x ; // auto unboxing
//		double y = x.doubleValue() ;
//		System.out.println(y);
//		System.out.println(AiryFunction.ai(y));
//
//	}


	public static void test3() {
		List<Double> x = new ArrayList<>() ;
		x.add(1.1) ;
		x.add(-1.1) ;
		x.add(3.1) ;
//		double y = x.get(0).doubleValue() ;
		AiryFunction.ai(x) ;
	}

	public static void main(String[] args) {
//		test1() ;
//		test2() ;
		test3() ;
	}

}
