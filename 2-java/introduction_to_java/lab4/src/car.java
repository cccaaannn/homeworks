package lab6;

public abstract class car extends vehicle {

	
	
	double hiz;
	
	car(){
		super.setTekerlek(4);
	hiz = 100;
	}
	
	car(double hiz){
		super();
		this.hiz = hiz;		
	}
		
	
	public double getHiz() {
		return hiz;
	}

	public void setHiz(double hiz) {
		this.hiz = hiz;
	}


	abstract double calculateconsumption(int kilo);
	
	String ToString() {
		
	return (super.ToString()+ " hiz " +hiz);
		

	}

}

