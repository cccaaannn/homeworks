package furkanin_foto_seyi;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.attribute.BasicFileAttributeView;
import java.nio.file.attribute.BasicFileAttributes;
import java.nio.file.attribute.FileTime;
import java.text.SimpleDateFormat;

import javax.imageio.ImageIO;
import javax.swing.filechooser.FileSystemView;

public class seperate_fotos {



	void seperate(String files_will_come_from_here, String files_will_move_here) {

		//folder for taking files
		File folder = new File(files_will_come_from_here);

		//folder for moving files
		File main_folder = new File(files_will_move_here);

		//create main folder if not exits
		if (!main_folder.exists()) {
			System.out.println("creating directory: " + main_folder.getName());
			try{
				main_folder.mkdir();
				System.out.println("DIR created"); 
			} 
			catch(SecurityException se){
				System.out.println("DIR is not created"); 
			}        
		}



		File[] listOfFiles = folder.listFiles(); 
		
		//loop all the files inside of the folder
		for (int i = 0; i < listOfFiles.length; i++) {

			//progress info for user
			System.out.println((i + 1) + "/" + listOfFiles.length);

			
			//needed types
			boolean is_needed = false;
			String ext = listOfFiles[i].getName().substring(listOfFiles[i].getName().indexOf(".") + 1);
			if (ext.equalsIgnoreCase("jpg") || ext.equalsIgnoreCase("png") || ext.equalsIgnoreCase("jpeg") || ext.equalsIgnoreCase("MOV")) {
				is_needed = true;
			}


			//control if the file is a file and needed type
			if (listOfFiles[i].isFile() && is_needed) {

				//get year information from file
				String year_of_the_file = get_file_creation_year(listOfFiles[i]);

				//combine main folder and year
				File main_folder_and_year = new File(files_will_move_here + File.separator + year_of_the_file);

				//create year folder inside main folder
				if (!main_folder_and_year.exists()) {

					try{
						main_folder_and_year.mkdir();
					} 
					catch(SecurityException se){
						System.out.println("DIR is not created"); 
					}

				}



				//get month and day information from file
				String month_day_of_the_file = get_file_creation_month_day(listOfFiles[i]);

				//combine paths of month and day with year and main folder
				File main_folder_and_year_month_day = new File(main_folder_and_year + File.separator + month_day_of_the_file);

				//create month folder inside the year folder if needed
				if (!main_folder_and_year_month_day.exists()) {

					try{
						main_folder_and_year_month_day.mkdir();
					} 
					catch(SecurityException se){
						System.out.println("DIR is not created"); 
					}

				}


				//move to file
				listOfFiles[i].renameTo(new File(main_folder_and_year_month_day + File.separator + listOfFiles[i].getName()));


			} 

		}
	}









	String get_file_creation_year(File file) {   
		try{         
			Path p = Paths.get(file.getAbsolutePath());
			BasicFileAttributes view = Files.getFileAttributeView(p, BasicFileAttributeView.class).readAttributes();
			FileTime fileTime=view.lastModifiedTime();
			// return (""+new SimpleDateFormat("dd/MM/yyyy HH:mm:ss").format((fileTime.toMillis())));
			return ("" + new SimpleDateFormat("yyyy").format((fileTime.toMillis())));

		}
		catch(IOException e){ 
			e.printStackTrace(); 
		}

		return ""; 
	}



	String get_file_creation_month_day(File file) {   
		try{         
			Path p = Paths.get(file.getAbsolutePath());
			BasicFileAttributes view = Files.getFileAttributeView(p, BasicFileAttributeView.class).readAttributes();
			FileTime fileTime=view.lastModifiedTime();
			// return (""+new SimpleDateFormat("dd/MM/yyyy HH:mm:ss").format((fileTime.toMillis())));
			return ("" + new SimpleDateFormat("dd-MM-yyyy").format((fileTime.toMillis())));

		}
		catch(IOException e){ 
			e.printStackTrace(); 
		}

		return ""; 
	}


}
