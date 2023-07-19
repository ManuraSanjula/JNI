package test23;

public class TestFileReader {

	public static void test1() {
		String fileName = "./resources/sample.txt" ;
		FileReader freader = new FileReader(fileName) ;
		String firstWord = freader.next() ;
		System.out.println(firstWord);
		System.out.println(freader.next());
		freader.close();
	}

	public static void test2() {
		String fileName = "./resources/sample.txt" ;
		try(FileReader freader = new FileReader(fileName)) {
			String firstWord = freader.next() ;
			System.out.println(firstWord);
		}
	}

	public static void test3() {
		String fileName = "./resources/sample.txt" ;
		String word = null ;
		try(FileReader freader = new FileReader(fileName)) {
			while(!freader.eof()) {
				word = freader.next() ;
				System.out.println(word);
			}
		}
	}

	public static void main(String[] args) {
		test1() ;
//		test2() ;
//		test3() ;
	}

}
