package lab4;

public class student {

	String fname;
	String lname;
	int stno;
	double gpa;
	int numofpaper;
	
	
	
	public student() {
		fname = "no name";
		lname = "no surname";
		stno = -1;
		gpa = -1;
		numofpaper = -1;
	}	
	
	
	
	public student(String fname, String lname, int stno, double gpa, int numofpaper) {
		super();
		this.fname = fname;
		this.lname = lname;
		setStno(stno);
		setGpa(gpa);
		setNumofpaper(numofpaper);
	}



	public String getFname() {
		return fname;
	}



	public void setFname(String fname) {
		this.fname = fname;
	}



	public String getLname() {
		return lname;
	}



	public void setLname(String lname) {
		this.lname = lname;
	}



	public int getStno() {
		return stno;
	}



	public void setStno(int stno) {
		if(stno < 0) {
		throw new IllegalArgumentException("öðrenci numarasý 0 dan büyük olmaz");
		}	
		else {
			this.stno = stno;
		}
	}



	public double getGpa() {
		return gpa;
	}



	public void setGpa(double gpa) {
		
		if(gpa >= 0 && gpa <= 4)
		this.gpa = gpa;
		else
			throw new IllegalArgumentException("gpa 0 dan büyük 4.o dan küçük olmalý");
			
	}



	public int getNumofpaper() {
		return numofpaper;
	}



	public void setNumofpaper(int numofpaper) {
	if(numofpaper < 0)
		throw new IllegalArgumentException("nuofpaper ne bilmiyorum");
	else	
	  this.numofpaper = numofpaper;
	}
	
	
	
	public double sutdentpoint() {
		return (getGpa() * getNumofpaper());
	}
	
	public String toString() {
		
		return (getFname()+ " " +getLname());
		
	}
	
	
	
	
	
}
