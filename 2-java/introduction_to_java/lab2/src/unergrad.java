package lab4;

public class undergrad extends student {

	
	protected String school;
	protected String department;
	
	
	public undergrad() {
		super();
	school = "no school";
	department = "no department";
	
	}


	public undergrad(String fname, String lname, int stno, double gpa, int numofpaper,String sch,String dep) {
		super(fname, lname, stno, gpa, numofpaper);
	 school = sch;
	 department = dep;
		}


	
	
	
	public String getSchool() {
		return school;
	}


	public void setSchool(String school) {
		this.school = school;
	}


	public String getDepartment() {
		return department;
	}


	public void setDepartment(String department) {
		this.department = department;
	}


	@Override
	public double sutdentpoint() {
		// TODO Auto-generated method stub
		return ((getGpa()*1.5)*getNumofpaper());
	
	}
	
	
	public String toString() {
		return super.toString() + "aaa";
		
	}
	
	
	
	
	
	
}
