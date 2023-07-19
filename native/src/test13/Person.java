package test13;

public class Person {

	String name ;
	int age ;

	public Person(String name, int age) {
		this.name = name ;
		this.age = age ;
	}

	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + "]";
	}

	public static void printInfo(Person person) {
		System.out.println(person);
	}

	public static void setInfo(Person person, String name, int age) {
		person.name = name ;
		person.age = age ;
	}

}
