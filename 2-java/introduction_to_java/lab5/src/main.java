package lab8;

import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		classroom d505,d504;
		
		d505 = new classroom(7);
	    d504 = new classroom(3);
				
		
	    
		
      student []can = new student[10];
  
      int a;
      
      
      for (int i = 0; i < 10; i++) {
      try {
				a = s.nextInt();
				can[i] = new student(i,a);
			} 
      catch (IllegalArgumentException e) {
			System.out.println(e.getMessage());
			System.out.println("not otomatik olarak 0 yapýldý");
			can[i] = new student();
				}
      }
		
		
      student temp;
      for (int j = 0; j < 10; j++) {
    	  for (int i = 0; i < 10; i++) {
	     if(can[i].getGrade()>can[j].getGrade()) {
	    	 temp = can[j];
	    	 
	    	 can[j] = can[i];
	    	 can[i] = temp;
	  }
      }
      }
    	  
    	for (int i = 0; i < d505.getCapacity(); i++) {
			d505.st[i]=can[i];
		}  
    	for (int i = 0; i < d504.getCapacity(); i++) {
			d504.st[i]=can[i+d505.getCapacity()];
		}
    	
    	
    	/*  
      for (int i = 0; i < 10; i++) {
    	  can[i].print();
      }
      */
     
    	d505.print();
      d504.print();
      
      
		
	}

}
