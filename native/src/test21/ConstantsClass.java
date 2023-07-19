package test21;

public class ConstantsClass {

	static {
		System.loadLibrary("native_c");
	}

	// integer constants
	public static final byte BYTE_VALUE = 1 ;
	public static final short SHORT_VALUE = 2 ;
	public static final int INT_VALUE = 3 ;
	public static final long LONG_VALUE = 4 ;

	// float & double constants
	public static final float FLOAT_VALUE = 2.1f ; // static final --> initialization
	public static final double DOUBLE_VALUE = -10.5 ;

	// boolean
	public static final boolean TRUE_VALUE = true ;
	public static final boolean FALSE_VALUE = false ;

	// objects
	public static final String NAME = "Bob" ;


	public static native void printValues() ;

	public void printInfo() {
		System.out.println(FLOAT_VALUE);
		System.out.println(NAME);
	}

	public static void main(String[] args) {
		printValues();
	}

}
