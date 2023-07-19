package test9;

public class Person {

	private String name ;
	private int age = 21 ;
	static int phoneNumber = 999 ;

	public Person(String name) {
		this.name = name ;
	}

	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + "]";
	}


}
