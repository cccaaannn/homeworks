package lab3;

public class student {

	public String name;
	private int number;
	protected int class_info;
	
	
	public student() {
		name = "";
		number = 0;
		class_info = 0;
	}
	
	
	public String getName() {
		return name;
	}


	public void setName(String name) {
		this.name = name;
	}


	public int getNumber() {
		return number;
	}


	public void setNumber(int number) {
		this.number = number;
	}


	public int getClass_info() {
		return class_info;
	}


	public void setClass_info(int class_info) {
		this.class_info = class_info;
	}


	public student(String name, int number, int class_info) {
		this.name = name;
		this.number = number;
		this.class_info = class_info;
	}
	
	
	public String toString() {
		return name+number+class_info;
		
	}
}

