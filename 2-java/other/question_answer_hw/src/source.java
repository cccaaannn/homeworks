import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.text.DecimalFormat;

public class source extends JFrame implements ActionListener {
	 JLabel picfalse = new JLabel("");

    source() {
        super("SORULAR");
        this.setLayout(null);
        locations();
        add(btna);
        add(btnb);
        add(sonrakisorubutonu);
        add(btnc);
        add(btnd);
        add(txtsoru);
        add(dogruL);
        add(dogrus);
        add(falseL);
        add(yanliss);
        add(btne);
        add(sorusayisi);
        add(pictrue);
        add(picfalse);
        falseBtn();
        ekle();
        textarea();
        setSorusayisi();
        fontsize();
        pic1();
        pic2();
        ImageIcon img2 = new ImageIcon("images/icon2.png");
       // this.setIconImage(new ImageIcon(getClass().getResource("images/icon2.png")));

        
        this.setIconImage(img2.getImage());
    }




    void locations() {
        btna.setBounds(30, 350, 200, 70);
        btnb.setBounds(250, 350, 200, 70);
        sonrakisorubutonu.setBounds(460, 530, 170, 70);
        btnc.setBounds(30, 450, 200, 70);
        btnd.setBounds(250, 450, 200, 70);
        btne.setBounds(117, 530, 250, 70);
        txtsoru.setBounds(30, 30, 420, 300);
        dogruL.setBounds(470, 50, 120, 30);
        dogrus.setBounds(600, 50, 70, 30);
        falseL.setBounds(470, 90, 120, 30);
        yanliss.setBounds(600, 90, 70, 30);
        sorusayisi.setBounds(520, 250, 50, 75);
        pictrue.setBounds(520, 400, 120, 120);
        picfalse.setBounds(520, 400, 120, 120);

    }

    void ekle() {
        btna.addActionListener(this);
        btnb.addActionListener(this);
        btnc.addActionListener(this);
        btnd.addActionListener(this);
        btne.addActionListener(this);
        sonrakisorubutonu.addActionListener(this);
    }

    JButton btna = new JButton("A");
    JButton btnb = new JButton("B");
    JButton btnc = new JButton("C");
    JButton btnd = new JButton("D");
    JButton btne = new JButton("E");
    JButton sonrakisorubutonu = new JButton("Start Questions");
    JTextArea txtsoru = new JTextArea();
    JLabel dogruL = new JLabel("True answers : ");
    JLabel dogrus = new JLabel("0");
    JLabel falseL = new JLabel("False answers : ");
    JLabel yanliss = new JLabel("0");
    JLabel sorusayisi = new JLabel("QuestionNumber");
    
    //ImageIcon za = new ImageIcon("images/true.png"); 
    //JLabel pictrue = new JLabel(za);
    
    JLabel pictrue =  new JLabel(new ImageIcon(this.getClass().getResource(("true.png"))));
    
    //ImageIcon zaa = new ImageIcon("images/false.png");
   

    void falseBtn() {
        btna.setEnabled(false);
        btnb.setEnabled(false);
        btnc.setEnabled(false);
        btnd.setEnabled(false);
        btne.setEnabled(false);
    }

    void trueBtn() {
        btna.setEnabled(true);
        btnb.setEnabled(true);
        btnc.setEnabled(true);
        btnd.setEnabled(true);
        btne.setEnabled(true);
    }

    void textarea() {
        txtsoru.setLineWrap(true);
        txtsoru.setEditable(false);
        txtsoru.setMargin( new Insets(10,10,10,10) );


    }

    void fontsize() {
        txtsoru.setFont(new Font("Serif", Font.PLAIN, 20));
        btna.setFont(new Font("Serif", Font.PLAIN, 18));
        btnb.setFont(new Font("Serif", Font.PLAIN, 18));
        btnc.setFont(new Font("Serif", Font.PLAIN, 18));
        btnd.setFont(new Font("Serif", Font.PLAIN, 18));
        btne.setFont(new Font("Serif", Font.PLAIN, 18));
        sonrakisorubutonu.setFont(new Font("Serif", Font.PLAIN, 20));
        dogruL.setFont(new Font("Serif", Font.PLAIN, 18));
        falseL.setFont(new Font("Serif", Font.PLAIN, 18));
        dogrus.setFont(new Font("Serif", Font.PLAIN, 18));
        yanliss.setFont(new Font("Serif", Font.PLAIN, 18));
    }

    void setSorusayisi() {
        sorusayisi.setFont(new Font("Serif", Font.PLAIN, 70));
    }

    void pic1() {
    	
        //pictrue.setIcon(new ImageIcon(new ImageIcon("images/true.png").getImage().getScaledInstance(100, 100, Image.SCALE_DEFAULT)));
        pictrue.setVisible(false);
    }
    void pic2(){
    	picfalse.setIcon(new ImageIcon(new ImageIcon("images/false.png").getImage().getScaledInstance(100, 100, Image.SCALE_DEFAULT)));
        picfalse.setVisible(false);
        
    }


    int soru = 0, dogru = 0, yanlis = 0, sonrakisorusayac = 0, count = 0;

    void yanliscevap() {
        pictrue.setVisible(false);
        picfalse.setVisible(true);
        falseBtn();
        sonrakisorubutonu.setEnabled(true);
        yanlis++;
        yanliss.setText(yanlis + "");
    }

    void dogrucevap() {
        pictrue.setVisible(true);
        picfalse.setVisible(false);
        falseBtn();
        sonrakisorubutonu.setEnabled(true);
        dogru++;
        dogrus.setText(dogru + "");
    }


    @Override
    public void actionPerformed(ActionEvent e) {

        if (e.getSource() == sonrakisorubutonu) {
            sonrakisorusayac++;

            /////////////////////////Soru 1\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
            if (sonrakisorusayac == 1) {
                pictrue.setVisible(false);
                picfalse.setVisible(false);
                trueBtn();
                soru = soru + 1;
                sorusayisi.setText(soru + "");
                txtsoru.setText(" As part of a test preparation course, students areasked to take a practice version of the Graduate Record Examination (GRE). This is a \nstandardized test. Scores can range from 200 to 800 with a population mean of 500 and a \npopulation standard deviation of 100.\n");
                sonrakisorubutonu.setEnabled(false);
                btna.setText("Nominal");
                btnb.setText("Ordinal");
                btnc.setText("Interval");
                btnd.setText("Ratio");
                btne.setText("Approximately Interval");
                sonrakisorubutonu.setText("Next Question");
                count++;
            }

            /////////////////////////Soru 2\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

            if (sonrakisorusayac == 2) {
                pictrue.setVisible(false);
                picfalse.setVisible(false);
                trueBtn();
                soru++;
                sorusayisi.setText(soru + "");
                txtsoru.setText(" Children in elementary school are evaluated and classified as non-readers (0), beginning readers (1), grade level readers (2), or advanced readers \n(3). The classification is done in order to place \nthem in reading groups.\n");
                sonrakisorubutonu.setEnabled(false);
                count++;
            }

            /////////////////////////Soru 3\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

            if (sonrakisorusayac == 3) {
                pictrue.setVisible(false);
                picfalse.setVisible(false);
                trueBtn();
                soru++;
                sorusayisi.setText(soru + "");
                txtsoru.setText(" During a clinical interview, survivors of a \ntornado are asked to state â€œnoâ€� or â€œyesâ€� to \nwhether they have experienced specific \nsymptoms of Post-Traumatic Stress Disorder \n(PTSD) inthe past week.  The number â€œ0â€� is \nassigned to â€œnoâ€� and the number â€œ1â€� is assigned to â€œyesâ€�.\n");
                sonrakisorubutonu.setEnabled(false);
                count++;
            }


            /////////////////////////Soru 4\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

            if (sonrakisorusayac == 4) {
                pictrue.setVisible(false);
                picfalse.setVisible(false);
                trueBtn();
                soru++;
                sorusayisi.setText(soru + "");
                txtsoru.setText(" Emory University wants to know which \ndormitories the students prefer. The \nadministration counts the number of \napplications for each dorm. Administrators \nassign a rank to each dorm based on the number of applications received.\n");
                sonrakisorubutonu.setEnabled(false);
                count++;
            }


            //////////////////////////Soru 5\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

            if (sonrakisorusayac == 5) {
                pictrue.setVisible(false);
                picfalse.setVisible(false);
                trueBtn();
                soru++;
                sorusayisi.setText(soru + "");
                txtsoru.setText(" During a clinical interview, survivors of a \ntornado are asked to state â€œnoâ€� or â€œyesâ€� to \nwhether they have experienced specific \nsymptoms of Post-Traumatic Stress Disorder \n(PTSD) in the past week. The interviewer \nadds up the total number of â€œyesâ€� responses to \ncreate a Total PTSD Symptoms scale.\n");
                sonrakisorubutonu.setEnabled(false);
                count++;
            }


            /////////////////////////Soru 6\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

            if (sonrakisorusayac == 6) {
                pictrue.setVisible(false);
                picfalse.setVisible(false);
                trueBtn();
                soru++;
                sorusayisi.setText(soru + "");
                txtsoru.setText(" Interviewers ask research subjects to describe insome detail their relationships with important \npeople in their lives. Using established criteria, \nraters review these personal descriptions and \nassign a dominant attachment category \n(Secure - 1, Preoccupied - 2, Fearful - 3, \nDismissing - 4).\n");
                sonrakisorubutonu.setEnabled(false);
                count++;
                sonrakisorubutonu.setText("Result");

            }

            double rate = dogru * 16.666666666666667;


            if (sonrakisorusayac == 7) {
                pictrue.setVisible(false);
                picfalse.setVisible(false);
                falseBtn();
                JOptionPane.showMessageDialog(null,"True Answers : " + dogru + "\nFalse Answers : " + yanlis + "\nSuccess Rate : " + new DecimalFormat("##.##").format(rate)+"%","RESULT",1);

            }
        }

        ////////////////////////CEVAP 1\\\\\\\\\\\\\\\\\\\\\\\\\\\
        if (e.getSource() == btna && count == 1) {
            yanliscevap();
            JOptionPane.showMessageDialog(null, "Sorry, this is incorrect. \n No groupings or classifications were described.","WRONG",2);
        }

        if (e.getSource() == btnb && count == 1) {
            yanliscevap();
            JOptionPane.showMessageDialog(null, "Sorry, this is incorrect.  \nGRE scores have the property of identity and magnitude, so they do tell us lower or higher probability of success in graduate school. \nHowever, they also have the property of equal intervals between scale points.", "WRONG", 2);
        }
        if (e.getSource() == btnc && count == 1) {
            dogrucevap();
            JOptionPane.showMessageDialog(null, "Correct.  \nGRE scores have the properties of identity, magnitude and equal intervals between scale points.", "CORRECT", 1);
        }
        if (e.getSource() == btnd && count == 1) {
            yanliscevap();
            JOptionPane.showMessageDialog(null, "Sorry, this is incorrect.  \nGRE scores have the properties of identity, magnitude and equal intervals between scale points. \nThey do not have a zero score; they range from 200 to 800.", "WRONG", 2);
        }
        if (e.getSource() == btne && count == 1) {
            yanliscevap();
            JOptionPane.showMessageDialog(null, "Sorry, this is incorrect. \nWe create GRE scores by combining responses across items.  \nThe items, however, are not rank or likert items.", "WRONG", 2);
        }

        /////////////////////CEVAP 2\\\\\\\\\\\\\\\\\\\\\\\\
        if (e.getSource() == btna && count == 2) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nReading levels are identified but they are also ordered by skill level.","WRONG",2);
        }
        if (e.getSource() == btnb && count == 2){
            dogrucevap();
            JOptionPane.showMessageDialog(null,"Correct.  \nThe numbers identify and order the level of reading skill. \nThey have the properties of identity and magnitude.","CORRECT",1);
        }
        if (e.getSource() == btnc && count == 2) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nThe reading level scores have the property of identity and magnitude/order but there is not equal distance between scale points.","WRONG",2);
        }
        if (e.getSource() == btnd && count == 2) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect. \nEven though the zero score may represent no reading skill (and thus is a true zero point),\n the ratio scale of measurement requires both equal intervals and a true zero point.","WRONG",2);
        }
        if (e.getSource() == btne && count == 2) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nThis measurement is based on only one ordinal rating. \nApproximately interval scales require that multiple ordinal ratings are added together or averaged.","WRONG",2);
        }

        /////////////////////Cevap 3\\\\\\\\\\\\\\\\\\\\\\\\
        if (e.getSource() == btna && count == 3) {
            dogrucevap();
            JOptionPane.showMessageDialog(null,"Correct.  \nThe numbers in this rating system identify the presence or absence of a symptom in the past week. \nThe only numerical property of this scale is identity.","CORRECT",1);
        }
        if (e.getSource() == btnb && count == 3) {
            yanliscevap();
            JOptionPane.showMessageDialog(null, "Sorry, this is not correct.  \nThe numbers in this rating system represent only the presence or absence of a symptom in the past week.  \nThey do not order the level of symptoms.","WRONG",2);
        }
        if (e.getSource() == btnc && count == 3) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is not correct.  \nThis scale is simply classifying the presence or absence of a symptom in the past week.  \nScale points are not ordered and we do not have a fixed interval between no and yes.\n","WRONG",2);
        }
        if (e.getSource() == btnd && count == 3) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is not correct.  \nEven though \"0\" represents the absence of a symptom in the past week, \nthe ratio scale of measurement requires both equal intervals and a true zero point.\n","WRONG",2);
        }
        if (e.getSource() == btne && count == 3) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nThis measurement is based on only one nominal rating.  \nApproximately interval scales require that multiple ordinal ratings are added together or averaged.\n","WRONG",2);
        }

        /////////////////////Cevap 4\\\\\\\\\\\\\\\\\\\\\
        if (e.getSource() == btna && count == 4) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nThe dorms are identified in this number system and thus it has the property of identity. \nBut the dorms are also ordered giving the number system the property of magnitude.\n","WRONG",2);
        }
        if (e.getSource() == btnb && count == 4) {
            dogrucevap();
            JOptionPane.showMessageDialog(null,"Correct. \nThis ranking system has the properties of identity and magnitude.\n","CORRECT",1);
        }
        if (e.getSource() == btnc && count == 4) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nThis ranking system identifies and orders student preferences but the interval between each rank is not equal.  \nIt does not tell us how much each dorm is preferred (or not) over the others.\n","WRONG",2);
        }
        if (e.getSource() == btnd && count == 4) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect. \nThis ranking system identifies and orders student preferences but the interval between each rank is not equal.  \nIt does not tell us how much each dorm is preferred (or not) over the others.  There is also no true zero point on this scale.\n","WRONG",2);
        }
        if (e.getSource() == btne && count == 4) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nThis measurement is based on only one ordinal rating.  \nApproximately interval scales require that multiple ordinal ratings are added together or averaged. \n","WRONG",2);
        }

        /////////////////////Cevap 5\\\\\\\\\\\\\\\\\\\\\\\\
        if (e.getSource() == btna && count == 5) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nThe yes/no responses to each symptom are measured on a nominal scale, but the total score counts of the number of yes responses.\n","WRONG",2);
        }
        if (e.getSource() == btnb && count == 5) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nThe yes/no responses to each symptom are measured on a nominal scale. \nThe total score counts the number of yes responses.\n","WRONG",2);
        }
        if (e.getSource() == btnc && count == 5) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nCounting the number of \"yes\" responses creates a scale with equal intervals between scale points, but it also has a true zero.  \nA score of \"0\" means that the person interviewed stated that they did not experience any of the specific symptoms of PTSD in the past week.\n","WRONG",2);
        }
        if (e.getSource() == btnd && count == 5) {
            dogrucevap();
            JOptionPane.showMessageDialog(null,"Correct.  \nCounting the number of \"yes\" responses creates a scale with the properties of identity, magnitude, equal interval, and true zero.  \nThe \"0\" score is a true zero indicating that the person interviewed reported experiencing no symptoms of PTSD in the past week.\n","CORRECT",1);
        }
        if (e.getSource() == btne && count == 5) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nWe are adding scores across items, but the original items are not measured on an ordinal scale.  \nThis scale is based on counting responses, which yields a scale with identity, magnitude, equal intervals and a true zero.\n","WRONG",2);
        }

        ////////////////////Cevap 6\\\\\\\\\\\\\\\\\\\\\\\\
        if (e.getSource() == btna && count == 6) {
            dogrucevap();
            JOptionPane.showMessageDialog(null,"Correct.  \nThe numbers on this rating scale name the dominant attachment style.  \nThis scale only has the numerical property of identity.\n","CORRECT",1);

        }
        if (e.getSource() == btnb && count == 6) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nThe numbers in this rating system only identify the attachment style.  \nThere is no inherent order in the styles.\n","WRONG",2);

        }
        if (e.getSource() == btnc && count == 6) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nThis scale is simply classifying the dominant attachment style.  \nScale points are not ordered and we do not have a fixed interval between the styles.\n","WRONG",2);

        }
        if (e.getSource() == btnd && count == 6) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nThere is no \"0\" score on this scale.\n","WRONG",2);

        }
        if (e.getSource() == btne && count == 6) {
            yanliscevap();
            JOptionPane.showMessageDialog(null,"Sorry, this is incorrect.  \nThis measurement is based on only one nominal rating.  \nApproximately interval scales require that multiple ordinal ratings are added together or averaged.\n","CORRECT",1);

        }
    }
}







