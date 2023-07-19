package test15;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

public class TestConstructorCall {

	static {
		System.loadLibrary("native_c");
	}

	public static native Person createPerson(String name, int age) ;

	public static void test2() {
		Person person = createPerson("JamesC++", 31) ;
		System.out.println(person);
	}

	public static void test1() throws NoSuchMethodException, SecurityException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		// use Java reflection API
		Constructor<Person> constructor = Person.class.getDeclaredConstructor(String.class, int.class) ;
		Person person = constructor.newInstance("Bob", 21) ;
		System.out.println(person);
	}

	public static void main(String[] args) throws NoSuchMethodException, SecurityException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
//		test1() ;
		test2() ;
	}

}
