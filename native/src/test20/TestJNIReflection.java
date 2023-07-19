package test20;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.List;
import java.util.Map;

public class TestJNIReflection {

	static {
		System.loadLibrary("native_c");
	}

	public static native void callNameField(Person person, Field field) ;
	public static native void callMethod(Person person, Method method) ;

	public static void test1() throws NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException, NoSuchMethodException {
		Person person = new Person("Bob", 21) ;
		Class<?> clazz = person.getClass() ;
		Field fName = clazz.getDeclaredField("name") ;
		Field fAge = clazz.getDeclaredField("age") ;
		// get the actual value of the field
		int age = fAge.getInt(person) ;
		System.out.println(age);
		String name = (String) fName.get(person) ;
		System.out.println(name);
		// JNI field
		callNameField(person, fName);
		// JNI method
		callMethod(person, person.getClass().getDeclaredMethod("calculate", int.class, int.class, double.class, Person.class, List.class, Map.class));
	}

	public static void main(String[] args) throws NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException, NoSuchMethodException {
		test1() ;
	}

}
