package test20;

import java.util.List;
import java.util.Map;

public class Person {

	String name ;
	int age ;

	public Person(String name, int age) {
		this.name = name ;
		this.age = age ;
	}

	public int calculate(int age1, int age2, double height, Person person, List<Double> values, Map<Integer, Person> map) {
		return 2*age ;
	}


	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + "]";
	}

}
