package test3;

public class Cat extends Mammal {

	// static initializer
	static {
		System.out.println("Inside Cat static initializer");
	}

	// instance initializer --> a simple code block { ...  }
	{
		System.out.println("Inside Cat instance initializer");
	}

	public static int ID = 1 ;

	public static void func() {
		System.out.println("Inside Cat static method");
	} ;

	public Cat() {
		// super() --> constructor call to super class Animal()
		// instance initializer for mammal
		System.out.println("Inside Cat constructor");
	}

}
