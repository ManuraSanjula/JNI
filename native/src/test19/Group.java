package test19;

public class Group<T> {

	T[] members ;

	public Group(T[] people) {
		this.members = people ;
	}

	public void printMembers() {
		for (T member : members)
			System.out.println(member);
	}

}
