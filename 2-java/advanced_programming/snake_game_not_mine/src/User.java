
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Scanner;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;


public class User extends JFrame implements MouseListener,KeyListener{
	Scanner input = new Scanner(System.in);

	BorderLayout bl ; 
	GridLayout gl; 
	FlowLayout fl;
	JPanel jpCenter;
	JPanel jpNorth;  
	JPanel jpSouth; 
	JLabel lblName; 
	JLabel lblslitherio;
	JTextField txtName;
	JButton jb;
	JCheckBox singlecb;  
	JCheckBox multiplecb;
	ImageIcon imgslitherio;
	String name;


	public User() {
		super("Username");

		bl = new BorderLayout();
		setLayout(bl);
		addKeyListener(this);
		addMouseListener(this);
		
		setFocusable(true);

		fl= new FlowLayout();
		gl=new GridLayout();

		jpNorth = new JPanel();
		add(jpNorth,BorderLayout.NORTH);
		north();

		jpSouth = new JPanel();
		add(jpSouth,BorderLayout.SOUTH);
		south();

		jpCenter = new JPanel();
		add(jpCenter,BorderLayout.CENTER);
		center(); 

	}

	public void north() {


		jpNorth.setLayout(fl);
		imgslitherio = new ImageIcon("slither.io.jpg");
		lblslitherio = new JLabel(imgslitherio,JLabel.CENTER);
		jpNorth.add(lblslitherio);

	}

	public void center() {

		//jpCenter.setLayout(gl);
		lblName= new JLabel();
		lblName.setText("Enter an username : ");
		lblName.setHorizontalAlignment(SwingConstants.CENTER);
		jpCenter.add(lblName);
		txtName = new JTextField();
		txtName.setPreferredSize(new Dimension(150,50));
		jpCenter.add(txtName);

	}


	public void south() {
		 
		  jpSouth.setLayout(fl);
		  
		  singlecb = new JCheckBox("Single Player");
		  multiplecb = new JCheckBox("Multiple Player");
		  
		  jpSouth.add(singlecb, BorderLayout.CENTER);
		  jpSouth.add(multiplecb, BorderLayout.CENTER);
		  
		  CheckBoxHandler handler = new CheckBoxHandler();
		  singlecb.addItemListener(handler);
		  multiplecb.addItemListener(handler);
		  

		  jb = new JButton("Play");
		  jb.addActionListener(new ActionListener() {

		   @Override
		   public void actionPerformed(ActionEvent e) {
		    printInfo();


		   }

		  });
		  jpSouth.add(jb, FlowLayout.CENTER);
		 }

		 public void printInfo() {
		  name = txtName.getText();
		  
		  if(txtName.getText().equals("")) {
		   JOptionPane.showMessageDialog(null, "Enter your name PLEASE");   
		  }
		  else {
		   
		  System.out.println(name);

		  setVisible(false);
		  Snake s =new Snake();
		  s.setSize(700,700);
		  s.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		  s.setLocationRelativeTo(null);
		  s.setTitle("SNAKE GAME");
		  s.setVisible(true);
		  s.setResizable(false);
		  }
		  
		 }
		 
		 public class CheckBoxHandler implements ItemListener{

		  @Override
		  public void itemStateChanged(ItemEvent e) {
		    
		   if(singlecb.isSelected()){
		             
		             multiplecb.setSelected(false);
		         }
		   else {
		    singlecb.setSelected(false);
		   }
		   
		  }
		  
		 }
	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void keyPressed(KeyEvent e) {
		if(e.getKeyCode() == KeyEvent.VK_ESCAPE) {
			System.exit(0);
		}
		if(e.getKeyCode() == KeyEvent.VK_ENTER){
			printInfo();
		}
	}
	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseClicked(MouseEvent e) {

		if(e.getSource() == txtName) {
			txtName.setText(" ");
		}

	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub

	}


}

