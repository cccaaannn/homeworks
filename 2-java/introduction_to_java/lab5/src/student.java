package lab8;

public class student {

	static int ogrencisayisi=0;
	int id;
   protected int grade;
   
    
    
    student(){
    	id = ogrencisayisi + 1;
    	grade = 0;
    ogrencisayisi++;
    }
   
    student(int id,int grade){
      	this.id=id;
    	setGrade(grade);
    	ogrencisayisi++;
    }

    
    
    
	public static int getOgrencisayisi() {
		return ogrencisayisi;
	}

	public static void setOgrencisayisi(int ogrencisayisi) {
		student.ogrencisayisi = ogrencisayisi;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public int getGrade() {
		return grade;
	}

	public void setGrade(int grade) {
		
			if(grade > -1 && grade < 101) {
				this.grade = grade;
			}
			else {
				throw new IllegalArgumentException("düzgün yaz");
			}
	}
	
   
    
    public void print() {
    	System.out.println("grade: "+grade+" id: "+id);
    }
    
	
	
}
