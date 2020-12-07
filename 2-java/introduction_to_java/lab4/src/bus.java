package lab6;

public class bus extends vehicle {

	
	static int buscount=0;
	
double personcount;
	
	bus(){
		super(6);
		personcount= 100;
		buscount++;
	}
	
	bus(int tekerlek,double personcount){
		super(tekerlek);
		this.personcount = personcount;
		buscount++;
	}
	

	 double calculateconsumption(int kilo) {
	return 	(kilo*9);
	}
	
	
	 String ToString() {
			
			return ("bus "+super.ToString()+ " personcaount " +personcount+" buscount "+ buscount);
				

			}
	
	
	
	
	
}
