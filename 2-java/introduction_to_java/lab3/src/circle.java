package lab5;

public class circle extends shape implements area {

	int r;
	
	@Override
	public double calculatearea() {
      return Math.PI * r * r;	
		}

	@Override
	public double calculateperimater() {
	return 2 * Math.PI * r;
	}

	
	public circle() {
		super();
		r = 0;
		}

	public circle(int r) {
		this.r = r;
	}
	
	
	

	public int getR() {
		return r;
	}

	public void setR(int r) {
		this.r = r;
	}
	
	

	public circle(int x, int y,int r) {
		super(x, y);
		this.r = r; 
	}
	
	
	public String toString() {
		return super.toString() + "circle [r=" + r + "]";
	}
	
	
}
