
import javax.swing.JFrame;
public class Test {
	
	public static void main(String[] args) {

		User u = new User();
		u.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		u.setLocation(500, 250);
		u.setSize(500,300);
		u.setVisible(true);
		u.setResizable(false);
		 	
	}
}
