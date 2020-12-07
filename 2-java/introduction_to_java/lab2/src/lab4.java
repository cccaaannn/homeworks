package lab4;

public class lab4 {

	public static void main(String[] args) {
		
		
		student s = null;
		
		
		try {
		s = new student("can","kurt",1505773,4,1);
		}
		catch(IllegalArgumentException e)
		{
			System.out.println(e.getMessage());
			System.out.println("gpa otomatik ayarlandý");
			s = new student("can","kurt",1505773,0,1);
		}
		finally {
			
		System.out.println("finally her zaman çalýþýr");
		System.out.println(s.toString());
		
		}

		
		undergrad ug = new undergrad("metin","kurt",124,4,1,"bau","comp");
		
		
		
		
		
		
		
		
	}

}
