package lab6;

public abstract class vehicle {

//static int vehiclecount = 0 ;

int tekerlek;

	vehicle(){
		tekerlek = 4;
	}
	
	vehicle(int tekerlek){
		this.tekerlek = tekerlek;
	}
	
	

	public int getTekerlek() {
		return tekerlek;
	}



	public void setTekerlek(int tekerlek) {
		this.tekerlek = tekerlek;
	}

	String ToString() {
		
	return (" tekerlek " + tekerlek);	
		

	}

	abstract double calculateconsumption(int kilo);
	
}
