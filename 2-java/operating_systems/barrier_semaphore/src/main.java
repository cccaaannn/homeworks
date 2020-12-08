package furkanin_odevi;
public class main {
	
	public static void main(String[] args){

		barrier_init barrier = new barrier_init(5);
		
		Thread a = new Thread(barrier);
		Thread b = new Thread(barrier);
		Thread c = new Thread(barrier);
		Thread d = new Thread(barrier);
		Thread e = new Thread(barrier);
		


		a.start();
		b.start();
		c.start();	
		d.start();	
		e.start();	
		
	
	}

}
