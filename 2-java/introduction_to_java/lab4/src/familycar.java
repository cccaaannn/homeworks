package lab6;

public class familycar extends car {

	static int familycarcount = 0;
	boolean childseat;
	
	familycar(){
		super();
	childseat = true;
	familycarcount++;
	}
	
	familycar(int tekerlek,double hiz,boolean childseat){
		super(hiz);
		this.childseat = childseat;
		familycarcount++;
	}
	
	
	 double calculateconsumption(int kilo) {
	return 	(kilo*5);
	}
	
	 
	 public static int getFamilycarcount() {
		return familycarcount;
	}

	public static void setFamilycarcount(int familycarcount) {
		familycar.familycarcount = familycarcount;
	}

	public boolean isChildseat() {
		return childseat;
	}

	public void setChildseat(boolean childseat) {
		this.childseat = childseat;
	}

	String ToString() {
		 return ("familycar "+super.ToString()+ " childseat " +childseat+ " familycarcount " +familycarcount );
	 }
	 
}
