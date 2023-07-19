package test10;

public class TestMethodCatching {

	static {
		System.loadLibrary("native_c");
	}

	public static native void setAge(Person person, int age) ;
	public static native void setName(Person person, String name) ;

	// with no caching --> 600 msec, 1200 msec
	// with method caching (local caching) --> 150 msec (x4 reduction), 250 msec (x5)
	public static void test1() {
		long start = System.currentTimeMillis() ;
		Person[] people = new Person[1_000_000] ;
		for(int i=0; i<people.length; i++) {
			people[i] = new Person("Bob " + i) ;
			setName(people[i], "James "+i) ;
			setAge(people[i], i) ;
		}
		long end = System.currentTimeMillis() ;
		long duration = end - start ;
		System.out.println("time (msec) = " + duration);
	}

	public static void main(String[] args) {
		test1() ;
	}

}
