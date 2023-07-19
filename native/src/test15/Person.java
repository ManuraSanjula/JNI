package test15;

public class Person {

	String name ;
	int age ;

	public Person(String name, int age) {
		this.name = name ;
		this.age = age ;
	}

	public Person(String name) {
		this.name = name ;
		this.age = 21 ;
	}

	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + "]";
	}

}
