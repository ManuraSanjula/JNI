package test22;

import test22.Person.Bag;

public class TestInnerClass {

	static {
		System.loadLibrary("native_c");
	}

	public static native Person.Bag createBag() ;
	public static native Person.Book createBook(Person person) ;

	public static void test3() {
		Person bob = new Person("Bob", 21) ; // instance person
		Person.Book book = createBook(bob) ;
		System.out.println(book);
		book.printTitle();
	}

	public static void test2() {
		Person.Bag bag = createBag() ;
		System.out.println(bag);
		bag.printSize();
		Person.Bag.printSize(bag);
	}

	public static void test1() {
		Person person = new Person("Bob", 21) ;
		Person.Book book = person.new Book("War and Peace") ; // nested inner class
		System.out.println(book);

		// static inner class: Bag --> inside Person : type --> Person.Bag
		Bag bag = new Bag(5) ;
		System.out.println(bag);
	}

	public static void main(String[] args) {
		test1() ;
//		test2() ;
//		test3() ;
	}

}
