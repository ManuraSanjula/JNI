package test8;

import java.lang.reflect.Field;

public class TestStaticFields {

	static {
		System.loadLibrary("native_c");
	}

	public native void printPersonInfo() ;

	public static void test2() {
		TestStaticFields test = new TestStaticFields() ;
		test.printPersonInfo();
	}

	public static void test1() throws NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException {
		// use class that is associated with Person
		Class<?> clazz = Person.class ;
		Field f1 = clazz.getDeclaredField("name") ;
		Field f2 = clazz.getDeclaredField("age") ;
		System.out.println(f1);
		System.out.println(f2);
		Object nameObj = f1.get(Person.class) ;
		String name = (String) nameObj ;
		System.out.println(name);
		int age = f2.getInt(Person.class) ;
		System.out.println(age);
	}

	public static void main(String[] args) throws NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException {
//		test1() ;
		test2() ;
	}

}
