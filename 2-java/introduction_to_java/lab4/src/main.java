package lab6;

import java.util.Random;

public class main {

	public static void main(String[] args) {
		
		Random r = new Random(); 
         int rr;
		
		vehicle []v = new vehicle[5]; 
		
for (int i = 0; i < v.length; i++) {
	rr = r.nextInt(4)+1;
	if(rr == 1) {
		v[i] = new familycar();
	}
	if(rr == 2) {
		v[i] = new sportscar();
	}
	if(rr == 3) {
		v[i] = new truck();
	}
	if(rr == 4) {
		v[i] = new bus();
	}
	
}
		


for (int i = 0; i < v.length; i++) {
	
	System.out.println(v[i].ToString());
	
}







		
		
	}

}
