package test;

public class TestOverrideSubClass extends TestOverrideSuperClass {

	static {
		System.loadLibrary("native_c");
	}

	// override with non-native (regular) method
//	@Override
//	public double func(double x) {
//		return x ;
//	}

	// override with native method
	@Override
	public native double func(double x) ;

	public static void main(String[] args) {
		TestOverrideSuperClass test1 = new TestOverrideSuperClass() ;
		System.out.println(test1.func(1.1));

		TestOverrideSuperClass test2 = new TestOverrideSubClass() ;
		System.out.println(test2.func(1.1));
	}


}
