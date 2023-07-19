package test18;

public class TestInternalLinking {

	static {
		System.loadLibrary("native_c");
	}

	public static native double callFunc(double x, double y) ;

	public static void test1() {
		double result = callFunc(1.1, 2.2) ;
		System.out.println(result);
	}

	public static void main(String[] args) {
		test1() ;
	}

}
