package lab5;

import java.util.Random;

import javafx.scene.shape.Circle;

public class shapecreator {

	public static shape create() {
		shape s = null;
		int x;
		int y;
		Random rand = new Random();
	int c = rand.nextInt(2)+1;
	
	
	switch(c){
		
		case 1:
			x = rand.nextInt(100);
			y = rand.nextInt(100);
	        int rad = rand.nextInt(10); 		
			s = new Circle(x,y,rad);
		break;
		case 2:
			x = rand.nextInt(100);
			y = rand.nextInt(100);
			int w = rand.nextInt(10);
			int h = rand.nextInt(10);
			s = new rectangle(x,y,w,h);
			break;
		default:
			break;
			
	}
	
	}
	
}
