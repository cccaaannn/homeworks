package furkanin_odevi;

public class Calc {
	
	private int value1 = 0;
	private int value2 = 0;
	
	
	public void calc1(){
		this.value1++;
		System.out.println("value1 :" + value1);
	}
	
	public void calc2(){
		this.value2++;
		System.out.println("value1 :" + value1 + " value2 :" + value2 + " value1 + value2 :" + (value1+value2));
	}
	
}
