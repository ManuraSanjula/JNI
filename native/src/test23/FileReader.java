package test23;

public class FileReader implements AutoCloseable {

	static {
		System.loadLibrary("native_c");
		initIDs();
	}

	private static native void initIDs() ;

	private native void open0() ; // opens the native file stream
	private native void close0() ; // closes the native file stream

	String file ;
	boolean isClosed = false ;

	public FileReader(String file) {
		this.file = file ;
		// immediately open the native file stream
		open0();
	}

	// I want to be able to do read operations on the file
	// reading word by word
	private native String next0() ;
	// checking end of file (eof)
	public native boolean eof() ;

	public String next() {
		if(isClosed)
			throw new IllegalStateException("file stream has been closed.") ;
		else
			return next0() ;
	}

	@Override
	public void close() {
		close0() ;
		isClosed = true ;
		System.out.println("closing file reader in 'close()'");
	}

	@Override
	protected void finalize() throws Throwable { // bad practice for resource management
		close0() ;
		isClosed = true ;
		System.out.println("closing file reader in 'finalize()'");
	}



}
