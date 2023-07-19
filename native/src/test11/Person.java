package test11;

public class Person {

	String firstName ;
	String lastName ;
	String eyeColor ;
	String nationality ;
	int age ;
	double height ;

	public Person(String firstName, String lastName) {
		this.firstName = firstName ;
		this.lastName = lastName ;
	}

	@Override
	public String toString() {
		return "Person [firstName=" + firstName + ", lastName=" + lastName + ", eyeColor=" + eyeColor + ", nationality="
				+ nationality + ", age=" + age + ", height=" + height + "]";
	}



}
