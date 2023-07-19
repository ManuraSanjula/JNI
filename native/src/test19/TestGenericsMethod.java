package test19;

public class TestGenericsMethod {

	static {
		System.loadLibrary("native_c");
	}

	public static native <T extends Number> void printInfoNative(T arg) ;

	public static <T extends Number> void printInfo(T arg) {
		System.out.println((arg instanceof Integer));
		System.out.println((arg instanceof Double));
		System.out.println(arg);
	}

	public static void test2() {
		printInfoNative(2.1);
	}

	public static void test1() {
		printInfo(2); // 2.1 = double --> Double.valueOf(2.1) : static factory method
	}

	public static void main(String[] args) {
//		test1() ;
		test2() ;
	}

}
