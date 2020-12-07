package lab4;

public class grad extends undergrad {

	
	protected String advisor;
	
	public grad() {
		super();
		advisor = "no advisor";
	}

	public grad(String advisor) {
		super();
		this.advisor = advisor;
	}

	public String getAdvisor() {
		return advisor;
	}

	public void setAdvisor(String advisor) {
		this.advisor = advisor;
	}

	@Override
	public double sutdentpoint() {
		// TODO Auto-generated method stub
		return ((getGpa()*2)*getNumofpaper());
	}
	
	
	
	
	
}
