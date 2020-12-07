package lab10;

import java.awt.*;
import java.awt.event.*;

import javax.swing.JOptionPane;

import javax.swing.*;


public class main {

	public static void main(String[] args) {

		JFrame f = new JFrame("kayýt formunu filler bastý!!!");
		f.setBounds(500,100,500,700);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		
		//layouts
		GridLayout gl1 = new GridLayout(7,1);
		GridLayout gl2 = new GridLayout(1,2);
		FlowLayout fl = new FlowLayout();
		
		//panels
		JPanel p1 = new JPanel();
		JPanel p2 = new JPanel();
		JPanel p3 = new JPanel();
		JPanel p4 = new JPanel();
		JPanel p5 = new JPanel();
		JPanel radiobutton = new JPanel();
		JPanel combobox = new JPanel();
		JPanel radiobutton2 = new JPanel();
		
		
		
		
		//labels
		JLabel name = new JLabel("name:");
		JLabel tcno = new JLabel("tcno:");
		JLabel mail = new JLabel("mail:");
		JLabel phone = new JLabel("phone:");
		JLabel gender = new JLabel("gender:");
		JLabel year = new JLabel("year:");
		JLabel contactinfo = new JLabel("contactinfo:");
		
		
		
		
		//textfields
	    JTextField name1 = new JTextField("isim ve soy isim girin");
		JTextField tcno1 = new JTextField("tc no girin");
		JTextField mail1 = new JTextField("mail girin");
		JTextField phone1 = new JTextField("telefon no girin");
	
				
		
		//buttons
		JButton save = new JButton("save");
		JButton clear = new JButton("clear");
		JButton exit = new JButton("exit");
		
		
		//image þeyi
		ImageIcon image = new ImageIcon("fil.jpg");
		
		JLabel fil = new JLabel(image,JLabel.CENTER);
		
		
		//radiobuttons
		
		JRadioButton male = new JRadioButton("male");
		JRadioButton female = new JRadioButton("female");
		
		JRadioButton sms = new JRadioButton("sms");
		JRadioButton phone2 = new JRadioButton("phone");
		JRadioButton mail2 = new JRadioButton("mail");
		
		
		//radiogroup
		ButtonGroup group = new ButtonGroup();
		
		group.add(male);
		group.add(female);
		
		
		//combobox
	
		Integer []y = {2010,2011,2012,2013,2014,2015,2016,2017,2018,2019}; //þunlarý integer tanýmlamazsan hata veriyo
		String []m = {"ocak","þubat","mart"};
		Integer  []d = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
		
		
		
		JComboBox year2 = new JComboBox(y);
		JComboBox month = new JComboBox(m);
		JComboBox day = new JComboBox(d);
		
		
		
		
		
		
		
		
		p1.setLayout(fl);
		
		p2.setLayout(gl1);
		
		p3.setLayout(gl1);
		
		p4.setLayout(fl);
		
		p5.setLayout(fl);
		
        radiobutton.setLayout(fl);
		
        combobox.setLayout(fl);
        
        radiobutton2.setLayout(fl);
		
        
        
        
        radiobutton.add(male);
        radiobutton.add(female);
        male.setSelected(true);
		
        
        
        combobox.add(year2);
		combobox.add(month);
		combobox.add(day);
		
		radiobutton2.add(sms);
		radiobutton2.add(phone2);
		radiobutton2.add(mail2);
		
        
		
		p1.add(fil);
		
		p2.add(name);
		p2.add(tcno);
		p2.add(mail);
		p2.add(phone);
		p2.add(gender);
		p2.add(year);
		p2.add(contactinfo);
		
		
		p3.add(name1);
		p3.add(tcno1);
		p3.add(mail1);
		p3.add(phone1);
		p3.add(radiobutton);
		p3.add(combobox);
		p3.add(radiobutton2);
		
		
		
		p5.add(save);
		p5.add(clear);
		p5.add(exit);
		
		
		//frame in layoutu
		
		f.add(p1,BorderLayout.NORTH);
		f.add(p2,BorderLayout.WEST);
		f.add(p3,BorderLayout.CENTER);
		f.add(p4,BorderLayout.EAST);
		f.add(p5,BorderLayout.SOUTH);
		
		
		
		
		
		
	
		//butonlar için listenerlar
		
		save.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
			
				JOptionPane.showMessageDialog(null, "KAYDEDÝLDÝ");
				
			}
		});
		
		

		clear.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
			
				name1.setText("");
				tcno1.setText("");
				mail1.setText("");
				phone1.setText("");
				
				sms.setSelected(false);
				phone2.setSelected(false);
				mail2.setSelected(false);
				
				
				JOptionPane.showMessageDialog(null, "ALANLAR SÝLÝNDÝ");
				
			}
		});

	
	   exit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
			
				int yes_no = JOptionPane.showConfirmDialog(null, "ÇIKILSIN MI?");
				if(yes_no == JOptionPane.YES_OPTION){
					System.exit(0);
				}
				else if(yes_no == JOptionPane.NO_OPTION){
										
				}
				else{
					//JOptionPane.showMessageDialog(null, "Cancelled");
				}
				
			}
		});
		
		
	
	 
		
		
		f.setVisible(true);
		
		
		
		
	}

}
