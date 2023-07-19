package test12;

public class Person {

	String name ;

	public Person(String name) {
		this.name = name ;
	}

	public String getName() {
		return name ;
	}

	public void printName() {
		System.out.println(name);
	}

	public String printInfo(int age) {
		return name + " " + age ;
	}

	public String printInfo() {
		return name ;
	}

	public static String printPersonInfo(Person person) {
		return person.name ;
	}

}
