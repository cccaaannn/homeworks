package furkanin_odevi;

import java.util.concurrent.Semaphore;

public class barrier_init extends Thread{


	Calc calc = new Calc();
	Semaphore barrier = new Semaphore(0);
	Semaphore mutex = new Semaphore(1);
	int thread_count = 0;
	int wait = 0;
	
	
	
	public barrier_init(int thread_count) {
		this.thread_count = thread_count;
	}




	public void run() {
		try {
			
			
			Thread.sleep(100);
			calc.calc1();
			
			
			mutex.acquire();  
			wait++;
	        System.out.println(Thread.currentThread().getName() + " = DONE");
	        mutex.release();
			
	        
	        
			if (wait == thread_count){
				barrier.release();
				System.out.println();
				System.out.println("barrier is now open");
				System.out.println();
			}
	        
		
			barrier.acquire();
			barrier.release();
		
			
			Thread.sleep(100);
			calc.calc2();
			
			
		} 
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}
