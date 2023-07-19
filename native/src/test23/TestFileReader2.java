package test23;

public class TestFileReader2 {

	public static void test1() {
		String fileName = "./resources/sample.txt" ;
		FileReader2 freader = new FileReader2(fileName) ;
		while(!freader.eof()) {
			System.out.print(freader.next() + "  ");
		}
		System.out.println();


		System.out.println("=============================");

		String fileName2 = "./resources/sample2.txt" ;
		FileReader2 freader2 = new FileReader2(fileName2) ;
		while(!freader2.eof()) {
			System.out.print(freader2.next() + "  ");
		}
		System.out.println();

		System.out.println("=============================");


		freader2.close();
		freader.close();

		System.out.println("=============================");
	}

	public static void main(String[] args) {
		test1() ;
	}

}
