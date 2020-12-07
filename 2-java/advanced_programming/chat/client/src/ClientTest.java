import javax.swing.JFrame;

public class ClientTest {

	public static void main(String[] args) {
		Client app = new Client("127.0.0.1");
		app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		app.runClient();
	}

}
