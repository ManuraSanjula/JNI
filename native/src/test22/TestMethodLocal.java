package test22;

public class TestMethodLocal {

	static {
		System.loadLibrary("native_c");
	}

	public static void test1() {
		// Outerclass$1Student  --> Outerclass_000241Student
		class Student { // method-local inner class,
			String name ;
			int age ;
			public Student(String name, int age) {
				this.name = name ;
				this.age = age ;
			}
			@Override
			public String toString() {
				return "Student [name=" + name + ", age=" + age + "]";
			}
			public native void printInfo() ; // $ --> _00024
			// Java_test22_TestMethodLocal_000241Student_printInfo
		}

		Student student1 = new Student("Bob", 21) ;
		System.out.println(student1);
		System.out.println(Student.class);
		student1.printInfo();

	}

	public static void main(String[] args) {
		test1() ;
	}

}
