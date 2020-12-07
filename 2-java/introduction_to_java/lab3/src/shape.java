package lab5;

public abstract class  shape {
 
	int x;
	int y;
	
	public static int shapecount = 0;

	public shape() {
		x = 0;
		y = 0;
		shapecount++;
	}

	public shape(int x, int y) {
		
		this.x = x;
		this.y = y;
	    shapecount++;
	}

	
	
	
	
	
	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public static int getShapecount() {
		return shapecount;
	}

	public static void setShapecount(int shapecount) {
		shape.shapecount = shapecount;
	}
	
	public String toString() {
		return "shape [x=" + x + ",y=" + y + "]";
	}
	
	public abstract double calculateperimater();                           //biyerde içini yazmak lazım

	
	
}
