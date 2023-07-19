package test9;

import java.lang.reflect.Field;

public class TestSetFields {

	static {
		System.loadLibrary("native_c");
	}

	public native void setNameAndAge(Person person, String name, int age) ;

	public static void test2() {
		// create an instance of the class
		Person person = new Person("Bob") ;
		System.out.println(person);
		System.out.println(Person.phoneNumber);
		// use c++
		TestSetFields test = new TestSetFields() ;
		test.setNameAndAge(person, "James C++", 31);
		System.out.println(person);
		System.out.println(Person.phoneNumber);
	}

	public static void test1() throws NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException {
		// create an instance of the class
		Person person = new Person("Bob") ;
		System.out.println(person);
		// practice java reflection API
		Class<?> clazz = person.getClass() ;
		Field f1 = clazz.getDeclaredField("name") ;
		f1.setAccessible(true);
		Field f2 = clazz.getDeclaredField("age") ;
		f2.setAccessible(true);
		f1.set(person, "James");
		f2.setInt(person, 31);
		System.out.println(person);
	}

	public static void main(String[] args) throws NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException {
//		test1() ;
		test2() ;
	}

}
