package test10;

public class Person {

	String name ;
	int age = 21 ;

	public Person(String name) {
		this.name = name ;
	}

	@Override
	public String toString() {
		return "Person [age=" + age + "]";
	}



}
