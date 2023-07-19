package test13;

public class TestCallStaticMethods {

	static {
		System.loadLibrary("native_c");
	}

	public static native void callPrintInfo(Person person) ;
	public static native void callSetInfo(Person person, String name, int age) ;
	public static native void printMemory() ;

	public static void test1() {
		Person person = new Person("Bob", 21) ;
		callPrintInfo(person);
	}

	public static void test2() {
		Person person = new Person("Bob", 21) ;
		System.out.println("Before : " + person);
		callSetInfo(person, "JamesC++", 31);
		System.out.println("After : " + person);
	}

	public static void test3() {
		long value = Runtime.getRuntime().freeMemory() ;
		System.out.println(value/(1024*1024));
		printMemory() ;
	}

	public static void main(String[] args) {
//		test1() ;
//		test2() ;
		test3() ;
	}

}
