package test17;

public class TestInheritance {

	static {
		System.loadLibrary("native_c");
	}

	public static native void callSpeak(Object animal) ;

	public static void test2() {
		Animal animal = new Animal() ;
		callSpeak(animal);

		Animal dog = new Dog() ;
		callSpeak(dog);

		Animal cat = new Cat() ;
		callSpeak(cat);

		Dummy dummy = new Dummy() ;
		callSpeak(dummy);
	}

	public static void test1() {
		// subtype polymorphism
		Animal animal = new Animal() ;
		animal.speak();

		Animal dog = new Dog() ;
		dog.speak();

		Animal cat = new Cat() ;
		cat.speak();
	}

	public static void main(String[] args) {
//		test1() ;
		test2() ;
	}

}
