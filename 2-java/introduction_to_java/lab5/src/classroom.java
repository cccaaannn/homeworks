package lab8;

public class classroom {

	int capacity;
	public student []st;
	
	
	
	classroom(){
		capacity = 10;
		st = new student[10];
	}
	
	classroom(int capacity){
		this.capacity = capacity;
		st = new student[capacity];
	}

	
	
	
	
	public int getCapacity() {
		return capacity;
	}

	public void setCapacity(int capacity) {
		this.capacity = capacity;
	}

	public student[] getSt() {
		return st;
	}

	public void setSt(student[] st) {
		this.st = st;
	}
	
	
	public void print() {
		System.out.println("sýnýf: ");
		for (int i = 0; i < capacity; i++) {
			st[i].print();
		}
	}
	
	
}
