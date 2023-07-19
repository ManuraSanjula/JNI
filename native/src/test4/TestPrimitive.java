package test4;

public class TestPrimitive {

	static {
		System.loadLibrary("native_c");
	}

	// always use JNI defined types
	public native boolean isOdd(int x) ;
	public native double func1(double x) ;
	public native float func2(byte x) ;



	public static void main(String[] args) {
		TestPrimitive test = new TestPrimitive() ;
		System.out.println(test.isOdd(8));
		System.out.println(test.func1(2.2));
		System.out.println(test.func2((byte)3));
	}

}
