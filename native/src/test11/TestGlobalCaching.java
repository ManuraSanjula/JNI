package test11;

public class TestGlobalCaching {

	static {
		System.loadLibrary("native_c");
		initIDs();
	}

	private static native void initIDs() ;

	public static native void setProperties(Person person, String eyeColor, String nationality, int age, double height) ;
	public static native void setFirstName(Person person, String firstName) ;
	public static native void setLastName(Person person, String lastName) ;

	public static void test1() {
		Person[] people = new Person[1_0] ;
		for(int i=0; i<people.length; i++) {
			people[i] = new Person("Bob "+i, "Smith "+i) ;
//			setProperties(people[i], "blue "+i, "American "+i, i, 2.1*i/3.1);
			setFirstName(people[i], "JamesC++ "+i);
			System.out.println(people[i]);
		}
	}

	public static void main(String[] args) {
		test1() ;
	}

}
