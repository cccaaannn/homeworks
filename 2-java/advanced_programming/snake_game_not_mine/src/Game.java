import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;
import java.util.Random;
import javax.swing.*;

public class Game extends JPanel implements ActionListener{

	protected static int S2x;
	protected static int S2y;
	protected static int S3x;
	protected static int S3y;
	protected static int S4x;
	protected static int S4y;
	protected static int S5x;
	protected static int S5y;
	protected static int speed=90;
	protected final int speed2=250;

	Color c= new Color(new Random().nextInt(200), new Random().nextInt(200), new Random().nextInt(250));

	ArrayList<Rectangle2D.Float> foods = new ArrayList<Rectangle2D.Float>();
	ArrayList<Rectangle2D.Float> nfoods = new ArrayList<Rectangle2D.Float>();

	Random rnd1=new Random();
	Random rnd2 = new Random();
	public Game(){
		mover.start();
		mover2.start();
		for (int i = 0; i < 20; i++) {
			Rectangle2D.Float r = new Rectangle2D.Float(rnd1.nextInt(66)*10,rnd1.nextInt(64)*10,10,10);
			foods.add(r);
			//System.out.println("YEMÝN YERÝ");
			//System.out.println(foods.get(i).getX()+" "+foods.get(i).getY());
		}
		for (int i = 0; i < 20; i++) {
			Rectangle2D.Float r = new Rectangle2D.Float(rnd1.nextInt(66)*10,rnd1.nextInt(64)*10,10,10);
			nfoods.add(r);
			//System.out.println("ZEHÝRÝN YERÝ");
			//System.out.println(nfoods.get(i).getX()+" "+nfoods.get(i).getY());

		}

	}
	public void paint(Graphics g){
		
		int size=Snake.snake.size();
		int size2=Snake.snake2.size();
		int size3=Snake.snake3.size();
		int size4=Snake.snake4.size();
		int size5=Snake.snake5.size();
		super.paint(g);

		g.setColor(c);
		g.setFont(new Font("Serif",Font.BOLD,20));
		g.drawString("Snake2 size = " + (Snake.snake2.size()), 500,520);
		g.drawString("Snake3 size = " + (Snake.snake3.size()), 500,540);
		g.drawString("Snake4 size = " + (Snake.snake4.size()), 500,560);
		g.drawString("Snake5 size = " + (Snake.snake5.size()), 500,580);
		g.drawString("Score = " + (Snake.score), 500, 600);
		g.drawString("Snake size = " + (Snake.snake.size()), 500,620);

		if(Snake.t2.isRunning()){
			g.drawString("High Speed ="+ speed2 ,500,660);
		}
		else if(Snake.t.isRunning()){
			g.drawString("Speed = "+ speed ,500,640);
		}
		else if (!Snake.t.isRunning()){
			g.setFont(new Font("Serif",Font.BOLD,80));
			g.drawString("GAME OVER", 100, 350);
			g.setFont(new Font("Serif",Font.BOLD,50));
			g.drawString("HIGH SCORE = "+Snake.score,100,400);

		}

		Graphics2D g2 = (Graphics2D) g;
		g2.setStroke(new BasicStroke(10));
		g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);


		for (Rectangle2D.Float r : Snake.snake) {

			g2.fillRect((int)r.x, (int)r.y, (int)r.width, (int)r.height);
		}
		g2.setColor(Color.darkGray);
		for (Rectangle2D.Float r : Snake.snake2) {

			g2.fillRect((int)r.x, (int)r.y, (int)r.width, (int)r.height);
		}
		g2.setColor(Color.LIGHT_GRAY);
		for (Rectangle2D.Float r : Snake.snake3) {

			g2.fillRect((int)r.x, (int)r.y, (int)r.width, (int)r.height);
		}
		g2.setColor(Color.ORANGE);
		for (Rectangle2D.Float r : Snake.snake4) {

			g2.fillRect((int)r.x, (int)r.y, (int)r.width, (int)r.height);
		}
		g2.setColor(Color.MAGENTA);
		for (Rectangle2D.Float r : Snake.snake5) {

			g2.fillRect((int)r.x, (int)r.y, (int)r.width, (int)r.height);
		}

		for (int i = 0; i <foods.size(); i++) {

			//	if(Snake.snake.get(size-1).intersects(foods.get(i)))
			if (Snake.snake.get(size-1).x==foods.get(i).getX() && Snake.snake.get(size-1).y==foods.get(i).getY()){
				foods.remove(i); 

				Snake.snake.add(new Rectangle2D.Float(Snake.snake.get(size-1).x, Snake.snake.get(size-1).y, 10, 10));

				Snake.t.setDelay(Snake.t.getDelay()+5);
			
				foods.add(new Rectangle2D.Float(rnd1.nextInt(66)*10,rnd1.nextInt(64)*10, 10, 10) );
				Snake.score +=20;
				while(speed==2){
					speed-=2;
					Snake.t.stop();
				}
				speed-=2;
			}
			
		}
		for (int i = 0; i < nfoods.size()-1; i++) {
			for (int j = 0; j < nfoods.size(); j++) {
				if(Snake.snake.get(0).intersects(nfoods.get(j))){
					System.out.println("lololo");
					nfoods.remove(j);
					Snake.t.stop();
					
				}
			}
			if (Snake.snake.get(size-1).x==nfoods.get(i).getX() && Snake.snake.get(size-1).y==nfoods.get(i).getY()){

				nfoods.remove(i);  
				//Snake.snake.remove(size-2); 
				Snake.snake.remove(new Rectangle2D.Float(Snake.snake.get(0).x,Snake.snake.get(0).y,10,10));
				Snake.t.setDelay(Snake.t.getDelay()-5);
				speed+=2;
				nfoods.add(new Rectangle2D.Float(rnd1.nextInt(66)*10,rnd1.nextInt(64)*10, 10, 10) );
				Snake.score -=20;

			}


		}
		///////////2
		for (int i = 0; i <foods.size(); i++) {

			//	if(Snake.snake.get(size-1).intersects(foods.get(i)))
			if (Snake.snake2.get(size2-1).x==foods.get(i).getX() && Snake.snake2.get(size2-1).y==foods.get(i).getY()){
				foods.remove(i); 
				Snake.snake2.add(new Rectangle2D.Float(Snake.snake2.get(size2-1).x, Snake.snake2.get(size2-1).y, 10, 10));
				foods.add(new Rectangle2D.Float(rnd1.nextInt(66)*10,rnd1.nextInt(64)*10, 10, 10) );

			}

		}
		for (int i = 0; i < nfoods.size(); i++) {
			for (int j = 0; j < nfoods.size(); j++) {
				if(Snake.snake2.get(0).intersects(nfoods.get(j))){
					System.out.println("lololo");
					nfoods.remove(j);
				
				}
			}
			if (Snake.snake2.get(size2-1).x==nfoods.get(i).getX() && Snake.snake2.get(size2-1).y==nfoods.get(i).getY()){
				nfoods.remove(i);  
				Snake.snake2.remove(new Rectangle2D.Float(Snake.snake2.get(0).x,Snake.snake2.get(0).y,10,10));
				nfoods.add(new Rectangle2D.Float(rnd1.nextInt(66)*10,rnd1.nextInt(64)*10, 10, 10) );
			}

		}

		/////3
		for (int i = 0; i <foods.size(); i++) {

			//	if(Snake.snake.get(size-1).intersects(foods.get(i)))
			if (Snake.snake3.get(size3-1).x==foods.get(i).getX() && Snake.snake3.get(size3-1).y==foods.get(i).getY()){
				foods.remove(i); 
				Snake.snake3.add(new Rectangle2D.Float(Snake.snake3.get(size3-1).x, Snake.snake3.get(size3-1).y, 10, 10));
				foods.add(new Rectangle2D.Float(rnd1.nextInt(66)*10,rnd1.nextInt(64)*10, 10, 10) );

			}

		}
		for (int i = 0; i < nfoods.size(); i++) {
			for (int j = 0; j < nfoods.size(); j++) {
				if(Snake.snake3.get(0).intersects(nfoods.get(j))){
					System.out.println("lololo");
					nfoods.remove(j);
				
				}
			}
			if (Snake.snake3.get(size3-1).x==nfoods.get(i).getX() && Snake.snake3.get(size3-1).y==nfoods.get(i).getY()){
				nfoods.remove(i);  
				Snake.snake3.remove(new Rectangle2D.Float(Snake.snake3.get(0).x,Snake.snake3.get(0).y,10,10)); 
				nfoods.add(new Rectangle2D.Float(rnd1.nextInt(66)*10,rnd1.nextInt(64)*10, 10, 10) );
			}	

		}

		////////////4
		for (int i = 0; i <foods.size(); i++) {

			//	if(Snake.snake.get(size-1).intersects(foods.get(i)))
			if (Snake.snake4.get(size4-1).x==foods.get(i).getX() && Snake.snake4.get(size4-1).y==foods.get(i).getY()){
				foods.remove(i); 
				Snake.snake4.add(new Rectangle2D.Float(Snake.snake4.get(size4-1).x, Snake.snake4.get(size4-1).y, 10, 10));
				foods.add(new Rectangle2D.Float(rnd1.nextInt(66)*10,rnd1.nextInt(64)*10, 10, 10) );

			}

		}
		for (int i = 0; i < nfoods.size(); i++) {
			for (int j = 0; j < nfoods.size(); j++) {
				if(Snake.snake4.get(0).intersects(nfoods.get(j))){
					System.out.println("lololo");
					nfoods.remove(j);
					
				}
			}
			if (Snake.snake4.get(size4-1).x==nfoods.get(i).getX() && Snake.snake4.get(size4-1).y==nfoods.get(i).getY()){
				nfoods.remove(i);  
				Snake.snake4.remove(new Rectangle2D.Float(Snake.snake4.get(0).x,Snake.snake4.get(0).y,10,10));
				nfoods.add(new Rectangle2D.Float(rnd1.nextInt(66)*10,rnd1.nextInt(64)*10, 10, 10) );
			}	  

		}
		///////////5
		for (int i = 0; i <foods.size(); i++) {

			//	if(Snake.snake.get(size-1).intersects(foods.get(i)))
			if (Snake.snake5.get(size5-1).x==foods.get(i).getX() && Snake.snake5.get(size5-1).y==foods.get(i).getY()){
				foods.remove(i); 
				Snake.snake5.add(new Rectangle2D.Float(Snake.snake5.get(size5-1).x, Snake.snake5.get(size5-1).y, 10, 10));
				foods.add(new Rectangle2D.Float(rnd1.nextInt(66)*10,rnd1.nextInt(64)*10, 10, 10) );

			}

		}
		for (int i = 0; i < nfoods.size(); i++) {
			for (int j = 0; j < nfoods.size(); j++) {
				if(Snake.snake5.get(0).intersects(nfoods.get(j))){
					System.out.println("lololo");
					nfoods.remove(j);
					
					
				}
			}
			if (Snake.snake5.get(size5-1).x==nfoods.get(i).getX() && Snake.snake5.get(size5-1).y==nfoods.get(i).getY()){
				nfoods.remove(i);  
				Snake.snake5.remove(size5-1); 				
				nfoods.add(new Rectangle2D.Float(rnd1.nextInt(66)*10,rnd1.nextInt(64)*10, 10, 10) );
			}	  

		}
		/////////////////
		g2.setColor(Color.GREEN);
		for(Rectangle2D.Float r : foods){
			g2.fill(r);
		}
		g2.setColor(Color.RED);
		for(Rectangle2D.Float r2 : nfoods){
			g2.fill(r2);
		}
		for (int j = 0; j < Snake.snake2.size(); j++) {
			if(Snake.snake.get(size-1).intersects(Snake.snake2.get(j))){
				Snake.t.stop();
				Snake.t2.stop();
			
			}

		}
		for (int j = 0; j < Snake.snake3.size(); j++) {
			if(Snake.snake.get(size-1).intersects(Snake.snake3.get(j))){
				Snake.t.stop();
				Snake.t2.stop();
			
			}

		}
		for (int j = 0; j < Snake.snake4.size(); j++) {
			if(Snake.snake.get(size-1).intersects(Snake.snake4.get(j))){
				Snake.t.stop();
				Snake.t2.stop();
			
			}

		}
		for (int j = 0; j < Snake.snake5.size(); j++) {
			if(Snake.snake.get(size-1).intersects(Snake.snake5.get(j))){
				Snake.t.stop();
				Snake.t2.stop();
			
			}

		}

	}
	@Override

	public void actionPerformed(ActionEvent e) {

		for (int i =0; i <Snake.snake.size()-1; i++) {
			Snake.snake.get(i).x = Snake.snake.get(i+1).x;
			Snake.snake.get(i).y = Snake.snake.get(i+1).y;
		}
		Snake.snake.get(Snake.snake.size()-1).x += Snake.Vx;
		Snake.snake.get(Snake.snake.size()-1).y += Snake.Vy;
		repaint();

	}

	Timer mover = new Timer(900,new ActionListener() {

		public void actionPerformed(ActionEvent e) {

			int s2 = rnd2.nextInt(64)*10;
			int s3 = rnd2.nextInt(64)*10;
			int s4 = rnd2.nextInt(64)*10;
			int s5 = rnd2.nextInt(64)*10;

			if(s2 >0 && s2 <= 160) {
				S2x=10;
				S2y=0;

			}
			if(s2 >160 && s2 <= 320) {
				S2x= -10;
				S2y=0;

			}
			if(s2 >320 && s2 <480) {
				S2x=0;
				S2y=10;

			}
			if(s2 >480 && s2 <= 640) {
				S2x=0;
				S2y=-10;


			}
			/////// 3rd snake
			if(s3 >0 && s3 <= 160) {
				S3x=10;
				S3y=0;

			}
			if(s3 >160 && s3 <= 320) {
				S3x= -10;
				S3y=0;

			}
			if(s3 >320 && s3 <=480) {
				S3x=0;
				S3y=10;

			}
			if(s3 >480 && s3 <= 640) {
				S3x=0;
				S3y=-10;

			}
			/// 4th snake
			if(s4 >0 && s4 <= 160) {
				S4x=10;
				S4y=0;

			}
			if(s4 >160 && s4 <= 320) {
				S4x= -10;
				S4y=0;

			}
			if(s4 >320 && s4 <= 480) {
				S4x=0;
				S4y=10;

			}
			if(s4 >480 && s4 <=640) {
				S4x=0;
				S4y=-10;

			}
			/// 5th snake
			if(s5 >0 && s5 <= 160) {
				S5x=10;
				S5y=0;

			}
			if(s5 >160 && s5 <=320) {
				S5x= -10;
				S5y=0;

			}
			if(s5 >320 && s5 <= 480) {
				S5x=0;
				S5y=10;

			}
			if(s5 >480 && s5 <=640) {
				S5x=0;
				S5y=-10;

			}

		}});

	Timer mover2 = new Timer(100,new ActionListener() {

		public void actionPerformed(ActionEvent e) {

			for (int i =0; i <Snake.snake2.size()-1; i++) {
				Snake.snake2.get(i).x = Snake.snake2.get(i+1).x;
				Snake.snake2.get(i).y = Snake.snake2.get(i+1).y;
			}
			Snake.snake2.get(Snake.snake2.size()-1).x += S2x;
			Snake.snake2.get(Snake.snake2.size()-1).y += S2y;
			repaint();


			for (int i =0; i <Snake.snake3.size()-1; i++) {
				Snake.snake3.get(i).x = Snake.snake3.get(i+1).x;
				Snake.snake3.get(i).y = Snake.snake3.get(i+1).y;
			}
			Snake.snake3.get(Snake.snake3.size()-1).x += S3x;
			Snake.snake3.get(Snake.snake3.size()-1).y += S3y;
			repaint();


			for (int i =0; i <Snake.snake4.size()-1; i++) {
				Snake.snake4.get(i).x=Snake.snake4.get(i+1).x;
				Snake.snake4.get(i).y=Snake.snake4.get(i+1).y;
			}
			Snake.snake4.get(Snake.snake4.size()-1).x += S4x;
			Snake.snake4.get(Snake.snake4.size()-1).y += S4y;
			repaint();

			for (int i =0; i <Snake.snake5.size()-1; i++) {
				Snake.snake5.get(i).x=Snake.snake5.get(i+1).x;
				Snake.snake5.get(i).y=Snake.snake5.get(i+1).y;
			}
			Snake.snake5.get(Snake.snake5.size()-1).x += S5x;
			Snake.snake5.get(Snake.snake5.size()-1).y += S5y;
			repaint();
		}});

}




