
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;
import java.util.Random;

import javax.swing.*;



public class Snake extends JFrame implements KeyListener{
	protected  static JPanel jp;
	protected  static JPanel jpCenter;
	protected  int a=5;
	protected static int Vx;
	protected static int Vy;
	protected static int score = 0;
	protected static ArrayList<Rectangle2D.Float> snake = new ArrayList<Rectangle2D.Float>();
	protected static ArrayList<Rectangle2D.Float> snake2 = new ArrayList<Rectangle2D.Float>();
	protected static ArrayList<Rectangle2D.Float> snake3 = new ArrayList<Rectangle2D.Float>();
	protected static ArrayList<Rectangle2D.Float> snake4 = new ArrayList<Rectangle2D.Float>();
	protected static ArrayList<Rectangle2D.Float> snake5 = new ArrayList<Rectangle2D.Float>();
	protected static Timer t;
	protected static Timer t2;
	Timer t3;
	protected static int delay=100;
	protected static int delay2=10;
	public Snake(){

		Vx=10;
		Vy=0;


		jp = new Game();
		add(jp);
		
        
		t =new Timer (delay,  (ActionListener) jp);
		t.start();
		t2= new Timer(delay2,(ActionListener) jp);

		setFocusable(true); 
		addKeyListener(this);

		for (int i = 0; i < 10; i++) {
			Rectangle2D.Float r =new Rectangle2D.Float(i*10, 20, 10, 10);
			snake.add(r);
		}
		for (int i = 1; i < 22; i++) {
			Rectangle2D.Float r =new Rectangle2D.Float(i*10, 200, 10, 10);
			snake2.add(r);
		}
		for (int i = 1; i < 15; i++) {
			Rectangle2D.Float r =new Rectangle2D.Float(i*10, 450, 10, 10);
			snake3.add(r);

		}
		for (int i = 1; i < 28; i++) {
			Rectangle2D.Float r =new Rectangle2D.Float(i*10, 550, 10, 10);
			snake4.add(r);

		}
		for (int i = 1; i < 18; i++) {
			Rectangle2D.Float r =new Rectangle2D.Float(i*10, 150, 10, 10);
			snake5.add(r);

		}
	}

	@Override
	public void keyPressed(KeyEvent e) {

		switch(e.getKeyCode()) {
		case KeyEvent.VK_UP:
			Vy= -10;
			Vx = 0;
			break;

		case KeyEvent.VK_DOWN:
			Vy = 10;
			Vx = 0;
			break;
		case KeyEvent.VK_LEFT:
			Vx=-10;
			Vy=0;
			break;
		case KeyEvent.VK_RIGHT:
			Vx=10;
			Vy=0;
			break;
		}

		
		
		t3  = new Timer(3000, new ActionListener() {
		    public void actionPerformed(ActionEvent evt) {

		    	t2.stop();
		    	t.start();
		   
		    }
		});
		
		
		
		if(e.getKeyCode()==KeyEvent.VK_SPACE ){
		
            score-=10;
			t.stop();
			t2.start();
			
			t3.restart();
			
			//t2.setDelay(t2.getDelay());

		
		}	
		if(e.getKeyCode()==KeyEvent.VK_0 ){
				Color bg= new Color(new Random().nextInt(255), new Random().nextInt(255), new Random().nextInt(255));
				jp.setBackground(bg); 
				repaint();
		}		
		repaint();
	}
	@Override
	public void keyReleased(KeyEvent e) {

		if(e.getKeyCode()==KeyEvent.VK_SPACE ){
			snake.remove(new Rectangle2D.Float(Snake.snake.get(0).x,Snake.snake.get(0).y,10,10));
			t2.stop();
			t.start(); 
			t.setDelay(Snake.t.getDelay());

	    	t3.stop();
		} 
		repaint();
	}

	@Override
	public void keyTyped(KeyEvent arg0) {


	}

}
