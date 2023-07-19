package test22;

public class Person {

	public String name ;
	public int age ;
	public static int phoneNumber = 111 ;

	public Person(String name, int age) {
		this.name = name ;
		this.age = age ;
	}

	// inner class
	public class Book {
		String title ;

		public Book(String title) {// (Ltest22/Person;Ljava/lang/String;)V
								  // Book(Person person, String title)
			this.title = name + "'s book = " + title ;
		}

		public native void printTitle() ;
		// Java_test22_Person_00024Book_printTitle: $ --> _00024
		// Java_test22_Person_00024Book_printTitle

		@Override
		public String toString() {
			return title ;
		}

	}

	// static inner class
	public static class Bag {
		int size ;

		public Bag(int size) {
			this.size =size ;
		}

		public native void printSize() ; // $ --> _00024
		// Java_test22_Person_00024Bag_printSize__
		// Java_test22_Person_00024Bag_printSize__

		public static native void printSize(Bag bag) ;
		// Java_test22_Person_00024Bag_printSize__Ltest22_Person_00024Bag_2
		// Java_test22_Person_00024Bag_printSize__Ltest22_Person_Bag_2

		@Override
		public String toString() {
			return "Bag size = " + size ;
		}
	}

}
