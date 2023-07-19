package test19;

public class TestGenericClass {

	static {
		System.loadLibrary("native_c");
	}

	public static native void callPrintMembers(Group<Person> group) ;
	public static native <T> void callPrintMembersParameterized(Group<T> group) ;

	public static void test2() {
		Person person1 = new Person("Bob", 21) ;
		Person person2 = new Person("James", 32) ;
		Person[] people = {person1, person2} ;
		Group<Person> group = new Group<>(people) ;

		callPrintMembers(group);
//		callPrintMembersParameterized(group);

		Group<Number> group2 = new Group<>(new Number[] {1.1, 3}) ;
		callPrintMembersParameterized(group2);
	}

	public static void test1() {
		Person person1 = new Person("Bob", 21) ;
		Person person2 = new Person("James", 32) ;
		Person[] people = {person1, person2} ;
		Group<Person> group = new Group<>(people) ;
		group.printMembers();
	}

	public static void main(String[] args) {
//		test1() ;
		test2() ;
	}

}
