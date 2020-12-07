package lab6;

public class truck extends vehicle {

	static int truckcount=0;
	
	double capacity;
	
	truck(){
		super(8);
		capacity = 100;
		truckcount++;
	}
	
	truck(int tekerlek,double capacity){
		super(tekerlek);
		this.capacity = capacity;
		truckcount++;
	}
	

	 double calculateconsumption(int kilo) {
	return 	(kilo*10);
	}
	
	 String ToString() {
			
			return ("truck "+super.ToString()+ " capacity " +capacity+" truckcount " +truckcount);
				

			}
}
