package test3;

public class Animal {

	// static initializer
	static {
		System.out.println("Inside Animal static initializer");
		System.loadLibrary("native_c");
	}

	// instance initializer --> a simple code block { ...  }
	{
		System.out.println("Inside Animal instance initializer");
	}

	public Animal() {
		// super()
		// instance initializer
		System.out.println("Inside Animal constructor");
	}
}
