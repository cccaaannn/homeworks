package busranin_analiz_projesi;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;

public class Functions {



	public void WriteToFile(String s,String filename) {
		try {
			PrintWriter outputStream = new PrintWriter(filename);  
			outputStream.println(s);
			outputStream.close(); 

			System.out.println("write successful");
		}

		catch(FileNotFoundException e){		    	
			System.out.println("write failed");
			//e.printStackTrace();
		}
	}



	public ArrayList<ArrayList<String>> Seperate_sentences(String s,String p,ArrayList<ArrayList<String>> l) {
		String temp = "";
		int counter = 0;
		boolean flag = false;
		for (int i = 1; i < s.length(); i++) {

			if((s.charAt(i) != ' ') && (s.charAt(i) != '.')) {

				temp += s.charAt(i);

			}
			else {

				if(temp.equals(p)) {
					flag = true;
				}

				l.get(counter).add(temp);
				temp = "";

			}


			if(s.charAt(i) == '.'){

				if(flag) {
					l.add(new ArrayList<String>());		
					counter++;
					flag = false;
				}

				else {
					l.get(counter).clear();
					temp = "";
				}

			}


		}

		l.remove(l.size() - 1);

		return l;
	}





	public ArrayList<ArrayList<String>> Seperate_LineBy_Line(String s,ArrayList<ArrayList<String>> l) {
		String temp = "";
		int counter = 0;
		for (int i = 1; i < s.length(); i++) {
			if(s.charAt(i) == '\n' && i !=  s.length()-1){
				l.add(new ArrayList<String>());		
				counter++;
			}
			else if(s.charAt(i) != ' ') {
				temp += s.charAt(i);
			}
			else {
				l.get(counter).add(temp);
				temp = "";
			}
		}
		return l;
	}


	public ArrayList<ArrayList<String>> Remove_Duplicate(ArrayList<ArrayList<String>> l) {

			for (int k = 0; k < l.size(); k++) {
				for (int i = 0; i < l.get(k).size(); i++) {
					for (int j = i + 1; j < l.get(k).size() - 1; j++) {
						if (l.get(k).get(i).equals(l.get(k).get(j))) {
							l.get(k).remove(j);
						}
					}
				}
			}
			
			return l;

		}
	


	public ArrayList<ArrayList<String>> remove_empty_lines(ArrayList<ArrayList<String>> l1) {


		int counter = 0;

		ArrayList<ArrayList<String>> l2 = new ArrayList<ArrayList<String>>();
		l2.add(new ArrayList<String>());		

		for (int i = 0; i < l1.size(); i++) {
			if (!l1.get(i).isEmpty()) {
				l2.get(counter).addAll(l1.get(i));
			}
		}

		return l2;

	}




	public ArrayList<ArrayList<String>> remove_empty(ArrayList<ArrayList<String>> l) {
		for (int i = 0; i < l.size(); i++) {
			l.get(i).removeAll(Collections.singleton(""));
		}
		return l;
	}
}
