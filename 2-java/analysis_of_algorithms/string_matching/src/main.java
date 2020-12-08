package busranin_analiz_projesi;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;


public class main {

	public static void main(String[] args){
		
		double start = System.nanoTime();
	
		ArrayList<ArrayList<String>> questions = new ArrayList<ArrayList<String>>();
		questions.add(new ArrayList<String>());


		Stopwords stopwords = new Stopwords();
		Functions functions = new Functions();


	
		//read questions
		String st = ""; 
		

		try {
			File file = new File("questions.txt"); 

			BufferedReader br = new BufferedReader(new FileReader(file)); 

			int count = 8;

			while (count > 0) {
				count--;
				st += " ";
				st += br.readLine();
				st += " ";
				st += "\n";
				//System.out.println(st); 
			}
			br.close();
		}
		catch (Exception e) {
			System.out.println("patladý");
		}

		//read truman
		String st2 = "";
		File file2 = new File("the_truman_show_script.txt");
		try {
			BufferedReader br2 = new BufferedReader(new FileReader(file2));
			st2 = " ";
			st2 += br2.readLine();
			br2.close(); 
		}
		catch (Exception e) {
			System.out.println("patladý");
		}









		st = st.toLowerCase();
		st = stopwords.noktalama(st);
		//st = stopwords.Stopword_remover(st);
		questions = functions.Seperate_LineBy_Line(st,questions);
		questions = stopwords.Stopword_remover2(questions);
		questions = functions.remove_empty(questions);


		st2 = st2.toLowerCase();
		st2 = stopwords.noktalama(st2);
		//st2 = stopwords.Stopword_remover(st2);




		//functions.WriteToFile(st2,"fileName.txt");





		for (int x = 0; x < questions.size(); x++) {


			ArrayList<ArrayList<String>> sentences = new ArrayList<ArrayList<String>>();
			sentences.add(new ArrayList<String>());		

			
			
			sentences = functions.Seperate_sentences(st2,questions.get(x).get(0),sentences);
			sentences = functions.Remove_Duplicate(sentences);
			sentences = stopwords.Stopword_remover2(sentences);
			sentences = functions.remove_empty(sentences);


			
			
			/*
		for (int i = 0; i < sentences.size(); i++) {
			System.out.println(i + "-" + sentences.get(i));
		}
			 */


	


			int counter = 0;
			for (int i = 0; i < sentences.size(); i++) {
				for (int j = 0; j < sentences.get(i).size(); j++) {
					for (int k = 0; k < questions.get(x).size(); k++) {
						if (sentences.get(i).get(j).equals(questions.get(x).get(k))) {
							Collections.replaceAll(sentences.get(i), questions.get(x).get(k), "0");
							counter++;
							break;
						}
					}
				}
				if (counter < questions.get(x).size()) {
					sentences.get(i).clear();
				}
				counter = 0;
			}


			
			

			sentences = functions.remove_empty_lines(sentences);


			

			System.out.println();
			try {
				sentences.get(0).get(0);
				System.out.print(x + "- answer ");
			}
			catch(Exception e) {
				System.out.print(x + "- no answer");
			}




			
			

			System.out.println("----------------------------");


			for (int i = 0; i < sentences.size(); i++) {
				System.out.println(sentences.get(i));
			}


			System.out.println("----------------------------------------");
			System.out.println();

		}


		






		double finish = System.nanoTime();
		double timeElapsed = finish - start;
		System.out.println("");
		System.out.println("Total time: " + (timeElapsed/1000000000) + " seconds");


	


	}

}





