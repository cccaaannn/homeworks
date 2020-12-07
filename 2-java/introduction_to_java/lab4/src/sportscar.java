package lab6;

public class sportscar extends car {
static int sportscarcount=0;
	
	sportscar(){
		super();
		sportscarcount++;
	}
	
	sportscar(int tekerlek,double hiz){
		super(hiz);
		sportscarcount++;
	}
	

	 double calculateconsumption(int kilo) {
	return 	(kilo*7);
	}
	
	 
	 String ToString() {
			
			return ("sportscar "+super.ToString()+" sportscarcount "+sportscarcount );
				
			}
	 
}
