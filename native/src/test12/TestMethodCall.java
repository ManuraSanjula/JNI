package test12;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class TestMethodCall {

	static {
		System.loadLibrary("native_c");
	}

	public static void test1() throws NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		// create a person
		Person person = new Person("Bob") ;
		// practice reflection API
		Class<?> clazz = person.getClass() ;
		// case 1: method does not have any parameters
		Method m1 = clazz.getDeclaredMethod("getName") ;
		Object obj = m1.invoke(person) ;
		System.out.println(obj);
		System.out.println(obj.getClass());
		String name = (String) obj ;
		System.out.println(name);
		// case 2: when we have some parameters
		Method m2 = clazz.getDeclaredMethod("printInfo", int.class) ;
		Object obj2 = m2.invoke(person, 21) ;
		System.out.println(obj2);
		System.out.println(obj2.getClass());
		// case 3: overloaded methods
		Method m3 = clazz.getDeclaredMethod("printInfo") ;
		Object obj3 = m3.invoke(person) ;
		System.out.println(obj3);
		System.out.println(obj3.getClass());
		// case 4: static methods
		System.out.println("-----------------------");
		// Person.printPersonInfo(person)
		Method m4 = Person.class.getDeclaredMethod("printPersonInfo", Person.class) ;
		Object obj4 = m4.invoke(null, person) ;
		System.out.println(obj4);
		System.out.println("-----------------------");
	}

	public static native void printPersonName(Person person) ;

	public static void test2() {
		Person person = new Person("Bob") ;
		printPersonName(person);
	}

	public static void main(String[] args) throws NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
//		test1() ;
		test2() ;
	}

}
