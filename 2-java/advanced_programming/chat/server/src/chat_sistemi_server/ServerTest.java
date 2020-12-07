package chat_sistemi_server;

import javax.swing.JFrame;

public class ServerTest {

	public static void main(String[] args) {
		Server app = new Server();
		app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		app.runServer();

	}

}
