package test;

public class TestOverloading {

	static {
		System.loadLibrary("native_c");
	}

	//// step 1 //////
	// valid overloaidng of native methods
	public native double func(double x) ;
	public native double func(double x, double y) ;
	public native double func(double x, String text) ;

	// regular methods --> can still do a valid overload of native methods
	public double func(double x, double y, double z) {
		return x ;
	}

	public static void main(String[] args) {
		TestOverloading test = new TestOverloading() ;
		System.out.println(test.func(1.1));
		System.out.println(test.func(1.1, 2.2));
		System.out.println(test.func(1.1, "hello"));
		System.out.println(test.func(1.1, 2.2, 3.3));
	}

}
