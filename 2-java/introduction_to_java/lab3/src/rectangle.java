package lab5;

public class rectangle extends shape {

	int w;
	int h;
	
	@Override
	public double calculateperimater() {
		
		return w + w + h + h;
		
	}

	
	
	
	public rectangle() {
		super();
	    w = 0;
		h = 0;
	}

	public rectangle(int x, int y,int w, int h) {
		super(x,y);
		this.w = w;
		this.h = h;
	}



	
	

	public int getW() {
		return w;
	}




	public void setW(int w) {
		this.w = w;
	}




	public int getH() {
		return h;
	}




	public void setH(int h) {
		this.h = h;
	}
	
	
	


	public String toString() {
		return  "rectangle [w=" + w + "h=" + h +"]";
	}
	
	
	
	
}
