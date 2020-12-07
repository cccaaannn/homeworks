#include "classroom.h"
#include "exam.h"
#include "Invigilator.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;


int main() {

	string name, code;
	int day, hour, students;
	exam a;
	
	int availableclassthing = 0;
	int classtatues[11];
	

	string classnames[11]{"D506","D505", "D504", "D502", "D501", "D308", "D306", "D304", "D303", "D302", "D301"};
	string Invigilatornames[6]{"john","mary", "sue", "jack", "alice", "bob"};
	


	//menu veriables
	int  menuselection = 0;

	
	
	classroom c1("D506", 30),
		c2("D505", 40),
		c3("D504", 40),
		c4("D502", 25),
		c5("D501", 20),
		c6("D308", 33),
		c7("D306", 32),
		c8("D304", 20),
		c9("D303", 28),
		c10("D302", 32),
		c11("D301", 40);

	Invigilator i1("john", "1"),
		i2("mary", "2"),
		i3("sue", "3"),
		i4("jack", "4"),
		i5("alice", "5"),
		i6("bob", "6");

	//MENU



MENU:

	

		system("cls");
		system("COLOR 09");

		cout << "M           M    E E E E    N     N    U       U " << endl;
		cout << "M M       M M    E          N N   N    U       U " << endl;
		cout << "M  M     M  M    E E E E    N  N  N    U       U " << endl;
		cout << "M   M   M   M    E          N   N N    U       U " << endl;
		cout << "M    M M    M    E E E E    N     N    U U U U U " << endl;


		cout << "create exam............................................................1" << endl;
		cout << "Show schedule for specific classes.....................................2" << endl;
		cout << "List available classes of a specific hours and days....................3" << endl;
		cout << "List available hours of a specific class in a specific day.............4" << endl;
		cout << "List available days of a specific class for a specific time interval...5" << endl << endl;
		cout << "enter number (1,2,3,4,5) for select task" << endl;
		cin >> menuselection;

		if (menuselection < 1 || menuselection > 5) {
			cout << "\ntask selection should be between 1 and 5" << endl;
			system("pause");
			goto MENU;
		};

		if (menuselection == 1) {
			goto CREATEEXAM;
		};
		
		if (menuselection == 2) {
			goto SHOWSCHEDULE;
		};

		if (menuselection == 3) {
			goto LISTAVAILABLECLASES;
		};

		if (menuselection == 4) {
			goto LISTAVAILABLEHOURS;
		};
	
		if (menuselection == 5) {
			goto LISTAVAILABLEDAYS;
		};

	
		
		//create exam

CREATEEXAM:
		system("COLOR 0A");
	

	a.createexam();

	day = a.getday();
	hour = a.gethour();

	
	
	int sellection1 = 0;
	availableclassthing = 0;  //menüdeki 3.seçenekde burayý kullanýyo bidaha yazmamak için
	int randomthing; //randomdan sonraki if için
	
RANDOM:
	
	int clasesfull = 0;  //sýnýflar doluysa þeyinin kontrolü
	

 //monday
	if (day == 1) {
		if (c1.mo[hour - 1] == '0') {
			classtatues[0] = 0;
		}
		else {
			classtatues[0] = 1;
		}
		if (c2.mo[hour - 1] == '0') {
			classtatues[1] = 0;
		}
		else {
			classtatues[1] = 1;
		}
		if (c3.mo[hour - 1] == '0') {
			classtatues[2] = 0;
		}
		else {
			classtatues[2] = 1;
		}
		if (c4.mo[hour - 1] == '0') {
			classtatues[3] = 0;
		}
		else {
			classtatues[3] = 1;
		}
		if (c5.mo[hour - 1] == '0') {
			classtatues[4] = 0;
		}
		else {
			classtatues[4] = 1;
		}
		if (c6.mo[hour - 1] == '0') {
			classtatues[5] = 0;
		}
		else {
			classtatues[5] = 1;
		}
		if (c7.mo[hour - 1] == '0') {
			classtatues[6] = 0;
		}
		else {
			classtatues[6] = 1;
		}
		if (c8.mo[hour - 1] == '0') {
			classtatues[7] = 0;
		}
		else {
			classtatues[7] = 1;
		}
		if (c9.mo[hour - 1] == '0') {
			classtatues[8] = 0;
		}
		else {
			classtatues[8] = 1;
		}
		if (c10.mo[hour - 1] == '0') {
			classtatues[9] = 0;
		}
		else {
			classtatues[9] = 1;
		}
		if (c11.mo[hour - 1] == '0') {
			classtatues[10] = 0;
		}
		else {
			classtatues[10] = 1;
		}
	}




	//tuesday





	if (day == 2) {
		if (c1.tu[hour - 1] == '0') {
			classtatues[0] = 0;
		}
		else {
			classtatues[0] = 1;
		}
		if (c2.tu[hour - 1] == '0') {
			classtatues[1] = 0;
		}
		else {
			classtatues[1] = 1;
		}
		if (c3.tu[hour - 1] == '0') {
			classtatues[2] = 0;
		}
		else {
			classtatues[2] = 1;
		}
		if (c4.tu[hour - 1] == '0') {
			classtatues[3] = 0;
		}
		else {
			classtatues[3] = 1;
		}
		if (c5.tu[hour - 1] == '0') {
			classtatues[4] = 0;
		}
		else {
			classtatues[4] = 1;
		}
		if (c6.tu[hour - 1] == '0') {
			classtatues[5] = 0;
		}
		else {
			classtatues[5] = 1;
		}
		if (c7.tu[hour - 1] == '0') {
			classtatues[6] = 0;
		}
		else {
			classtatues[6] = 1;
		}
		if (c8.tu[hour - 1] == '0') {
			classtatues[7] = 0;
		}
		else {
			classtatues[7] = 1;
		}
		if (c9.tu[hour - 1] == '0') {
			classtatues[8] = 0;
		}
		else {
			classtatues[8] = 1;
		}
		if (c10.tu[hour - 1] == '0') {
			classtatues[9] = 0;
		}
		else {
			classtatues[9] = 1;
		}
		if (c11.tu[hour - 1] == '0') {
			classtatues[10] = 0;
		}
		else {
			classtatues[10] = 1;
		}
	}




		//wednesday







		if (day == 3) {
			if (c1.we[hour - 1] == '0') {
				classtatues[0] = 0;
			}
			else {
				classtatues[0] = 1;
			}
			if (c2.we[hour - 1] == '0') {
				classtatues[1] = 0;
			}
			else {
				classtatues[1] = 1;
			}
			if (c3.we[hour - 1] == '0') {
				classtatues[2] = 0;
			}
			else {
				classtatues[2] = 1;
			}
			if (c4.we[hour - 1] == '0') {
				classtatues[3] = 0;
			}
			else {
				classtatues[3] = 1;
			}
			if (c5.we[hour - 1] == '0') {
				classtatues[4] = 0;
			}
			else {
				classtatues[4] = 1;
			}
			if (c6.we[hour - 1] == '0') {
				classtatues[5] = 0;
			}
			else {
				classtatues[5] = 1;
			}
			if (c7.we[hour - 1] == '0') {
				classtatues[6] = 0;
			}
			else {
				classtatues[6] = 1;
			}
			if (c8.we[hour - 1] == '0') {
				classtatues[7] = 0;
			}
			else {
				classtatues[7] = 1;
			}
			if (c9.we[hour - 1] == '0') {
				classtatues[8] = 0;
			}
			else {
				classtatues[8] = 1;
			}
			if (c10.we[hour - 1] == '0') {
				classtatues[9] = 0;
			}
			else {
				classtatues[9] = 1;
			}
			if (c11.we[hour - 1] == '0') {
				classtatues[10] = 0;
			}
			else {
				classtatues[10] = 1;
			}
		}




		//thursday





		if (day == 4) {
			if (c1.th[hour - 1] == '0') {
				classtatues[0] = 0;
			}
			else {
				classtatues[0] = 1;
			}
			if (c2.th[hour - 1] == '0') {
				classtatues[1] = 0;
			}
			else {
				classtatues[1] = 1;
			}
			if (c3.th[hour - 1] == '0') {
				classtatues[2] = 0;
			}
			else {
				classtatues[2] = 1;
			}
			if (c4.th[hour - 1] == '0') {
				classtatues[3] = 0;
			}
			else {
				classtatues[3] = 1;
			}
			if (c5.th[hour - 1] == '0') {
				classtatues[4] = 0;
			}
			else {
				classtatues[4] = 1;
			}
			if (c6.th[hour - 1] == '0') {
				classtatues[5] = 0;
			}
			else {
				classtatues[5] = 1;
			}
			if (c7.th[hour - 1] == '0') {
				classtatues[6] = 0;
			}
			else {
				classtatues[6] = 1;
			}
			if (c8.th[hour - 1] == '0') {
				classtatues[7] = 0;
			}
			else {
				classtatues[7] = 1;
			}
			if (c9.th[hour - 1] == '0') {
				classtatues[8] = 0;
			}
			else {
				classtatues[8] = 1;
			}
			if (c10.th[hour - 1] == '0') {
				classtatues[9] = 0;
			}
			else {
				classtatues[9] = 1;
			}
			if (c11.th[hour - 1] == '0') {
				classtatues[10] = 0;
			}
			else {
				classtatues[10] = 1;
			}

		}


		//friday





		if (day == 5) {
			if (c1.fr[hour - 1] == '0') {
				classtatues[0] = 0;
			}
			else {
				classtatues[0] = 1;
			}
			if (c2.fr[hour - 1] == '0') {
				classtatues[1] = 0;
			}
			else {
				classtatues[1] = 1;
			}
			if (c3.fr[hour - 1] == '0') {
				classtatues[2] = 0;
			}
			else {
				classtatues[2] = 1;
			}
			if (c4.fr[hour - 1] == '0') {
				classtatues[3] = 0;
			}
			else {
				classtatues[3] = 1;
			}
			if (c5.fr[hour - 1] == '0') {
				classtatues[4] = 0;
			}
			else {
				classtatues[4] = 1;
			}
			if (c6.fr[hour - 1] == '0') {
				classtatues[5] = 0;
			}
			else {
				classtatues[5] = 1;
			}
			if (c7.fr[hour - 1] == '0') {
				classtatues[6] = 0;
			}
			else {
				classtatues[6] = 1;
			}
			if (c8.fr[hour - 1] == '0') {
				classtatues[7] = 0;
			}
			else {
				classtatues[7] = 1;
			}
			if (c9.fr[hour - 1] == '0') {
				classtatues[8] = 0;
			}
			else {
				classtatues[8] = 1;
			}
			if (c10.fr[hour - 1] == '0') {
				classtatues[9] = 0;
			}
			else {
				classtatues[9] = 1;
			}
			if (c11.fr[hour - 1] == '0') {
				classtatues[10] = 0;
			}
			else {
				classtatues[10] = 1;
			}

		}




		//saturday



		if (day == 6) {
			if (c1.sa[hour - 1] == '0') {
				classtatues[0] = 0;
			}
			else {
				classtatues[0] = 1;
			}
			if (c2.sa[hour - 1] == '0') {
				classtatues[1] = 0;
			}
			else {
				classtatues[1] = 1;
			}
			if (c3.sa[hour - 1] == '0') {
				classtatues[2] = 0;
			}
			else {
				classtatues[2] = 1;
			}
			if (c4.sa[hour - 1] == '0') {
				classtatues[3] = 0;
			}
			else {
				classtatues[3] = 1;
			}
			if (c5.sa[hour - 1] == '0') {
				classtatues[4] = 0;
			}
			else {
				classtatues[4] = 1;
			}
			if (c6.sa[hour - 1] == '0') {
				classtatues[5] = 0;
			}
			else {
				classtatues[5] = 1;
			}
			if (c7.sa[hour - 1] == '0') {
				classtatues[6] = 0;
			}
			else {
				classtatues[6] = 1;
			}
			if (c8.sa[hour - 1] == '0') {
				classtatues[7] = 0;
			}
			else {
				classtatues[7] = 1;
			}
			if (c9.sa[hour - 1] == '0') {
				classtatues[8] = 0;
			}
			else {
				classtatues[8] = 1;
			}
			if (c10.sa[hour - 1] == '0') {
				classtatues[9] = 0;
			}
			else {
				classtatues[9] = 1;
			}
			if (c11.sa[hour - 1] == '0') {
				classtatues[10] = 0;
			}
			else {
				classtatues[10] = 1;
			}

		}
		

		//sunday



		if (day == 7) {
			if (c1.su[hour - 1] == '0') {
				classtatues[0] = 0;
			}
			else {
				classtatues[0] = 1;
			}
			if (c2.su[hour - 1] == '0') {
				classtatues[1] = 0;
			}
			else {
				classtatues[1] = 1;
			}
			if (c3.su[hour - 1] == '0') {
				classtatues[2] = 0;
			}
			else {
				classtatues[2] = 1;
			}
			if (c4.su[hour - 1] == '0') {
				classtatues[3] = 0;
			}
			else {
				classtatues[3] = 1;
			}
			if (c5.su[hour - 1] == '0') {
				classtatues[4] = 0;
			}
			else {
				classtatues[4] = 1;
			}
			if (c6.su[hour - 1] == '0') {
				classtatues[5] = 0;
			}
			else {
				classtatues[5] = 1;
			}
			if (c7.su[hour - 1] == '0') {
				classtatues[6] = 0;
			}
			else {
				classtatues[6] = 1;
			}
			if (c8.su[hour - 1] == '0') {
				classtatues[7] = 0;
			}
			else {
				classtatues[7] = 1;
			}
			if (c9.su[hour - 1] == '0') {
				classtatues[8] = 0;
			}
			else {
				classtatues[8] = 1;
			}
			if (c10.su[hour - 1] == '0') {
				classtatues[9] = 0;
			}
			else {
				classtatues[9] = 1;
			}
			if (c11.su[hour - 1] == '0') {
				classtatues[10] = 0;
			}
			else {
				classtatues[10] = 1;
			}
		}


		

		if (availableclassthing == 1) {
			goto LISTAVAILABLECLASES2;
		}
		





	
		
		//sýnýflar o saatte dolu mu diye bakýyo 
		
		
		
		int exit = 0;
		int	clases[11]{ 0,0,0,0,0,0,0,0,0,0,0};
		
		
		students = a.getstudents(); 



		if (classtatues[1] == 1) {
			students = students - 40;
			clases[1] = 1;
			if (students <= 0) {
				exit = 1;
			}
		}

		if (classtatues[2] == 1 && exit == 0) {
			students = students - 40;
			clases[2] = 1;
			if (students <= 0) {
				exit = 1;
			}
		}

		if (classtatues[10] == 1 && exit == 0) {
			students = students - 40;
			clases[10] = 1;
			if (students <= 0) {
				exit = 1;
			}
		}

		if (classtatues[5] == 1 && exit == 0) {
			students = students - 33;
			clases[5] = 1;
			if (students <= 0) {
				exit = 1;
			}
		}
		
		if (classtatues[6] == 1 && exit == 0) {
			students = students - 32;
			clases[6] = 1;
			if (students <= 0) {
				exit = 1;
			}
		}

		if (classtatues[9] == 1 && exit == 0) {
			students = students - 32;
			clases[9] = 1;
			if (students <= 0) {
				exit = 1;
			}
		}

		if (classtatues[0] == 1 && exit == 0) {
			students = students - 30;
			clases[0] = 1;
			if (students <= 0) {
				exit = 1;
			}
		}

		if (classtatues[8] == 1 && exit == 0) {
			students = students - 28;
			clases[8] = 1;
			if (students <= 0) {
				exit = 1;
			}
		}

		if (classtatues[3] == 1 && exit == 0) {
			students = students - 25;
			clases[3] = 1;
			if (students <= 0) {
				exit = 1;
			}
		}

		if (classtatues[4] == 1 && exit == 0) {
			students = students - 20;
			clases[4] = 1;
			if (students <= 0) {
				exit = 1;
			}
		}

		if (classtatues[7] == 1 && exit == 0) {
			students = students - 20;
			clases[7] = 1;
			if (students <= 0) {
				exit = 1;
			}
		}


		
		//yeterli sýnýf yoksa 
		if (students > 0) {
			
			clasesfull = 1;
			
		}



        cout << " :D ";      //kaç kere denediðini görmek için

		srand(time(NULL));

		if (classtatues[0] == 0 && classtatues[1] == 0 && classtatues[2] == 0 && classtatues[3] == 0 && classtatues[4] == 0 && classtatues[5] == 0
			&& classtatues[6] == 0 && classtatues[7] == 0 && classtatues[8] == 0 && classtatues[9] == 0 && classtatues[10] == 0 || clasesfull == 1) {

			randomthing = 1;

			day = rand() % 7 + 1;
			hour = rand() % 5 + 1;

			goto RANDOM;
		}


UP:
		if (randomthing == 1) {
			system("cls");
			cout << "there is no available classroom at that time" << endl;
			cout << "suggested day " << day << endl;
			cout << "suggested hour " << hour << endl;
			cout << "if you don't want suggested time enter 1 to reenter values \nif you want to continue enter 0 : ";

			cin >> sellection1;
		}


		

		if (sellection1 == 1) {

			randomthing = 0;


			goto CREATEEXAM;
		}


		if (sellection1 != 0 && sellection1 != 1) {
			cout << "just enter 1 or 0" << endl;
			system("pause");
			goto UP;
		}

		
		system("cls");

	


		a.setcodewithtxt(a.getcode() + ".txt");

		{                                                                // bunu koymayýnca hata veriyo out u atlayamazsýn gibi biþey diyo
			ofstream out(a.getcodewithtxt());

			out << "course name: " << a.getname() << endl;
			out << "course code: " << a.getcode() << endl;
			out << "exam day: " << day << endl;
			out << "exam hour: " << hour << endl;
			out << "student number: " << a.getstudents() << endl;

			for (int i = 0; i < 11; i++) {
				if (clases[i] == 1) {
					out << endl;
					out << "class: " << classnames[i] << endl;
				}
			}

			
			cout << "course name: " << a.getname() << endl;
			cout << "course code: " << a.getcode() << endl;
			cout << "exam day: " << day << endl;
			cout << "exam hour: " << hour << endl;
			cout << "student number: " << a.getstudents() << endl;

			for (int i = 0; i < 11; i++) {
				if (clases[i] == 1) {
					cout << endl;
					cout << "class: " << classnames[i] << endl;
				}
			}








			//Invigilator





			int clascounter = 0;
			int clases2[11];
			int Invigilators[6];

			goto B;
		A:

			for (int i = 0; i < 11; i++) {
				clases2[i] = clases[i];
			}

			for (int i = 0; i < 11; i++) {
				if (clases[i] == 1) {
					clascounter++;
				}
			}

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 11; j++) {
					if (clases2[j] == 1 && Invigilators[i] == 1 && clascounter > 0) {
						out << endl;
						out << classnames[j] << " " << Invigilatornames[i] << endl;
						cout << endl;
						cout << classnames[j] << " " << Invigilatornames[i] << endl;
						
						clases2[j] = 0;
						clascounter--;
						break;
					}
				}
			}

			if (clascounter > 0) {
				for (int i = 0; i < 11; i++) {
					if (clases2[i] == 1) {
						out << "no possible Invigilator for " << classnames[i] << endl;
						cout << "no possible Invigilator for " << classnames[i] << endl;
					}
				}
			}

			cout << endl;
			system("pause");
			goto MENU;


		B:

			//monday
			if (day == 1) {
				if (i1.mo[hour - 1] == '0') {
					Invigilators[0] = 0;
				}
				else {
					Invigilators[0] = 1;
				}
				if (i2.mo[hour - 1] == '0') {
					Invigilators[1] = 0;
				}
				else {
					Invigilators[1] = 1;
				}
				if (i3.mo[hour - 1] == '0') {
					Invigilators[2] = 0;
				}
				else {
					Invigilators[2] = 1;
				}
				if (i4.mo[hour - 1] == '0') {
					Invigilators[3] = 0;
				}
				else {
					Invigilators[3] = 1;
				}
				if (i5.mo[hour - 1] == '0') {
					Invigilators[4] = 0;
				}
				else {
					Invigilators[4] = 1;
				}
				if (i6.mo[hour - 1] == '0') {
					Invigilators[5] = 0;
				}
				else {
					Invigilators[5] = 1;
				}

			}

			//tuesday





			if (day == 2) {
				if (i1.tu[hour - 1] == '0') {
					Invigilators[0] = 0;
				}
				else {
					Invigilators[0] = 1;
				}
				if (i2.tu[hour - 1] == '0') {
					Invigilators[1] = 0;
				}
				else {
					Invigilators[1] = 1;
				}
				if (i3.tu[hour - 1] == '0') {
					Invigilators[2] = 0;
				}
				else {
					Invigilators[2] = 1;
				}
				if (i4.tu[hour - 1] == '0') {
					Invigilators[3] = 0;
				}
				else {
					Invigilators[3] = 1;
				}
				if (i5.tu[hour - 1] == '0') {
					Invigilators[4] = 0;
				}
				else {
					Invigilators[4] = 1;
				}
				if (i6.tu[hour - 1] == '0') {
					Invigilators[5] = 0;
				}
				else {
					Invigilators[5] = 1;
				}

			}




			//wednesday







			if (day == 3) {
				if (i1.we[hour - 1] == '0') {
					Invigilators[0] = 0;
				}
				else {
					Invigilators[0] = 1;
				}
				if (i2.we[hour - 1] == '0') {
					Invigilators[1] = 0;
				}
				else {
					Invigilators[1] = 1;
				}
				if (i3.we[hour - 1] == '0') {
					Invigilators[2] = 0;
				}
				else {
					Invigilators[2] = 1;
				}
				if (i4.we[hour - 1] == '0') {
					Invigilators[3] = 0;
				}
				else {
					Invigilators[3] = 1;
				}
				if (i5.we[hour - 1] == '0') {
					Invigilators[4] = 0;
				}
				else {
					Invigilators[4] = 1;
				}
				if (i6.we[hour - 1] == '0') {
					Invigilators[5] = 0;
				}
				else {
					Invigilators[5] = 1;
				}


			}




			//thursday





			if (day == 4) {
				if (i1.th[hour - 1] == '0') {
					Invigilators[0] = 0;
				}
				else {
					Invigilators[0] = 1;
				}
				if (i2.th[hour - 1] == '0') {
					Invigilators[1] = 0;
				}
				else {
					Invigilators[1] = 1;
				}
				if (i3.th[hour - 1] == '0') {
					Invigilators[2] = 0;
				}
				else {
					Invigilators[2] = 1;
				}
				if (i4.th[hour - 1] == '0') {
					Invigilators[3] = 0;
				}
				else {
					Invigilators[3] = 1;
				}
				if (i5.th[hour - 1] == '0') {
					Invigilators[4] = 0;
				}
				else {
					Invigilators[4] = 1;
				}
				if (i6.th[hour - 1] == '0') {
					Invigilators[5] = 0;
				}
				else {
					Invigilators[5] = 1;
				}



			}


			//friday





			if (day == 5) {
				if (i1.fr[hour - 1] == '0') {
					Invigilators[0] = 0;
				}
				else {
					Invigilators[0] = 1;
				}
				if (i2.fr[hour - 1] == '0') {
					Invigilators[1] = 0;
				}
				else {
					Invigilators[1] = 1;
				}
				if (i3.fr[hour - 1] == '0') {
					Invigilators[2] = 0;
				}
				else {
					Invigilators[2] = 1;
				}
				if (i4.fr[hour - 1] == '0') {
					Invigilators[3] = 0;
				}
				else {
					Invigilators[3] = 1;
				}
				if (i5.fr[hour - 1] == '0') {
					Invigilators[4] = 0;
				}
				else {
					Invigilators[4] = 1;
				}
				if (i6.fr[hour - 1] == '0') {
					Invigilators[5] = 0;
				}
				else {
					Invigilators[5] = 1;
				}

			}




			//saturday



			if (day == 6) {
				if (i1.sa[hour - 1] == '0') {
					Invigilators[0] = 0;
				}
				else {
					Invigilators[0] = 1;
				}
				if (i2.sa[hour - 1] == '0') {
					Invigilators[1] = 0;
				}
				else {
					Invigilators[1] = 1;
				}
				if (i3.sa[hour - 1] == '0') {
					Invigilators[2] = 0;
				}
				else {
					Invigilators[2] = 1;
				}
				if (i4.sa[hour - 1] == '0') {
					Invigilators[3] = 0;
				}
				else {
					Invigilators[3] = 1;
				}
				if (i5.sa[hour - 1] == '0') {
					Invigilators[4] = 0;
				}
				else {
					Invigilators[4] = 1;
				}
				if (i6.sa[hour - 1] == '0') {
					Invigilators[5] = 0;
				}
				else {
					Invigilators[5] = 1;
				}



			}


			//sunday



			if (day == 7) {
				if (i1.su[hour - 1] == '0') {
					Invigilators[0] = 0;
				}
				else {
					Invigilators[0] = 1;
				}
				if (i2.su[hour - 1] == '0') {
					Invigilators[1] = 0;
				}
				else {
					Invigilators[1] = 1;
				}
				if (i3.su[hour - 1] == '0') {
					Invigilators[2] = 0;
				}
				else {
					Invigilators[2] = 1;
				}
				if (i4.su[hour - 1] == '0') {
					Invigilators[3] = 0;
				}
				else {
					Invigilators[3] = 1;
				}
				if (i5.su[hour - 1] == '0') {
					Invigilators[4] = 0;
				}
				else {
					Invigilators[4] = 1;
				}
				if (i6.su[hour - 1] == '0') {
					Invigilators[5] = 0;
				}
				else {
					Invigilators[5] = 1;
				}

			}


			goto A;

		}










		















	








		//menu 2

SHOWSCHEDULE:
		system("COLOR 0C");

	

		int sellection2 = 0;


		system("cls");
		cout << "SHOW SCHEDULE FOR SPECIFIC CLASSES" << endl;
		
		cout << "menu.....0" << endl;
		cout << "D506.....1" << endl;
		cout << "D505.....2" << endl;
		cout << "D504.....3" << endl;
		cout << "D502.....4" << endl;
		cout << "D501.....5" << endl;
		cout << "D308.....6" << endl;
		cout << "D306.....7" << endl;
		cout << "D304.....8" << endl;
		cout << "D303.....9" << endl;
		cout << "D302.....10" << endl;
		cout << "D301.....11" << endl;
	   
		
		
		
		
		cout << "enter class number: " << endl;
		cin >> sellection2;

		if (sellection2 < 0 || sellection2>11) {
			cout << "value should be between 0 and 11" << endl;
			system("pause");
			goto SHOWSCHEDULE;
		}




		if (sellection2 == 0) {
			goto MENU;
		}

			
		//C1

		system("cls");
		cout << "SHOW SCHEDULE FOR SPECIFIC CLASSES" << endl;
		
		
				
		if (sellection2 == 1) {
			cout << "D506     cappacity  30" << endl;
			
			cout << "1" << "   ";
			for (int i = 0; i < 5; i++) {
				
				if (c1.mo[i] < 49 || c1.mo[i] > 53) {
					cout << " " << "   ";
               }
				else {
					cout << c1.mo[i] << "   ";
				}
			}
			
			cout << endl;
			cout << "2" << "   ";
			for (int i = 0; i < 5; i++) {
				
				if (c1.tu[i] < 49 || c1.tu[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c1.tu[i] << "   ";
				}
			}

			cout << endl;
			cout << "3" << "   ";
			for (int i = 0; i < 5; i++) {
				
				if (c1.we[i] < 49 || c1.we[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c1.we[i] << "   ";
				}
			}

			cout << endl;
			cout << "4" << "   ";
			for (int i = 0; i < 5; i++) {
				
				if (c1.th[i] < 49 || c1.th[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c1.th[i] << "   ";
				}
			}

			cout << endl;
			cout << "5" << "   ";
			for (int i = 0; i < 5; i++) {
				
				if (c1.fr[i] < 49 || c1.fr[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c1.fr[i] << "   ";
				}
			}

			cout << endl;
			cout << "6" << "   ";
			for (int i = 0; i < 5; i++) {
				
				if (c1.sa[i] < 49 || c1.sa[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c1.sa[i] << "   ";
				}
			}

			cout << endl;
			cout << "7" << "   ";
			for (int i = 0; i < 5; i++) {
				
				if (c1.su[i] < 49 || c1.su[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c1.su[i] << "   ";
				}
			}
			cout << endl << endl;
		}

		

		//c2


		

		if (sellection2 == 2) {
			
			system("cls");
			cout << "SHOW SCHEDULE FOR SPECIFIC CLASSES" << endl;

						
			cout << "D505     cappacity  40" << endl;

			cout << "1" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c2.mo[i] < 49 || c2.mo[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c2.mo[i] << "   ";
				}
			}

			cout << endl;
			cout << "2" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c2.tu[i] < 49 || c2.tu[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c2.tu[i] << "   ";
				}
			}

			cout << endl;
			cout << "3" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c2.we[i] < 49 || c2.we[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c2.we[i] << "   ";
				}
			}

			cout << endl;
			cout << "4" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c2.th[i] < 49 || c2.th[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c2.th[i] << "   ";
				}
			}

			cout << endl;
			cout << "5" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c2.fr[i] < 49 || c2.fr[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c2.fr[i] << "   ";
				}
			}

			cout << endl;
			cout << "6" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c2.sa[i] < 49 || c2.sa[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c2.sa[i] << "   ";
				}
			}

			cout << endl;
			cout << "7" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c2.su[i] < 49 || c2.su[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c2.su[i] << "   ";
				}
			}
			cout << endl << endl;
		}

		

		//c3

		

		if (sellection2 == 3) {
			
			system("cls");
			cout << "SHOW SCHEDULE FOR SPECIFIC CLASSES" << endl;
	
			
			cout << "D504     cappacity  40" << endl;

			cout << "1" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c3.mo[i] < 49 || c3.mo[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c3.mo[i] << "   ";
				}
			}

			cout << endl;
			cout << "2" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c3.tu[i] < 49 || c3.tu[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c3.tu[i] << "   ";
				}
			}

			cout << endl;
			cout << "3" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c3.we[i] < 49 || c3.we[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c3.we[i] << "   ";
				}
			}

			cout << endl;
			cout << "4" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c3.th[i] < 49 || c3.th[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c3.th[i] << "   ";
				}
			}

			cout << endl;
			cout << "5" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c3.fr[i] < 49 || c3.fr[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c3.fr[i] << "   ";
				}
			}

			cout << endl;
			cout << "6" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c3.sa[i] < 49 || c3.sa[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c3.sa[i] << "   ";
				}
			}

			cout << endl;
			cout << "7" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c3.su[i] < 49 || c3.su[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c3.su[i] << "   ";
				}
			}
			cout << endl << endl;
		}

		

		//c4

		

		if (sellection2 == 4) {
			
			system("cls");
			cout << "SHOW SCHEDULE FOR SPECIFIC CLASSES" << endl;

			
			cout << "D502     cappacity  25" << endl;

			cout << "1" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c4.mo[i] < 49 || c4.mo[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c4.mo[i] << "   ";
				}
			}

			cout << endl;
			cout << "2" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c4.tu[i] < 49 || c4.tu[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c4.tu[i] << "   ";
				}
			}

			cout << endl;
			cout << "3" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c4.we[i] < 49 || c4.we[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c4.we[i] << "   ";
				}
			}

			cout << endl;
			cout << "4" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c4.th[i] < 49 || c4.th[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c4.th[i] << "   ";
				}
			}

			cout << endl;
			cout << "5" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c4.fr[i] < 49 || c4.fr[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c4.fr[i] << "   ";
				}
			}

			cout << endl;
			cout << "6" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c4.sa[i] < 49 || c4.sa[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c4.sa[i] << "   ";
				}
			}

			cout << endl;
			cout << "7" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c4.su[i] < 49 || c4.su[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c4.su[i] << "   ";
				}
			}
			cout << endl << endl;
		}

		


		//c5

	

		if (sellection2 == 5) {
			
			system("cls");
			cout << "SHOW SCHEDULE FOR SPECIFIC CLASSES" << endl;

			
			cout << "D501     cappacity  20" << endl;

			cout << "1" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c5.mo[i] < 49 || c5.mo[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c5.mo[i] << "   ";
				}
			}

			cout << endl;
			cout << "2" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c5.tu[i] < 49 || c5.tu[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c5.tu[i] << "   ";
				}
			}

			cout << endl;
			cout << "3" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c5.we[i] < 49 || c5.we[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c5.we[i] << "   ";
				}
			}

			cout << endl;
			cout << "4" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c5.th[i] < 49 || c5.th[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c5.th[i] << "   ";
				}
			}

			cout << endl;
			cout << "5" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c5.fr[i] < 49 || c5.fr[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c5.fr[i] << "   ";
				}
			}

			cout << endl;
			cout << "6" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c5.sa[i] < 49 || c5.sa[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c5.sa[i] << "   ";
				}
			}

			cout << endl;
			cout << "7" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c5.su[i] < 49 || c5.su[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c5.su[i] << "   ";
				}
			}
			cout << endl << endl;
		}

		


		//c6

	

		if (sellection2 == 6) {
			
			system("cls");
			cout << "SHOW SCHEDULE FOR SPECIFIC CLASSES" << endl;

			
			cout << "D308     cappacity  33" << endl;

			cout << "1" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c6.mo[i] < 49 || c6.mo[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c6.mo[i] << "   ";
				}
			}

			cout << endl;
			cout << "2" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c6.tu[i] < 49 || c6.tu[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c6.tu[i] << "   ";
				}
			}

			cout << endl;
			cout << "3" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c6.we[i] < 49 || c6.we[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c6.we[i] << "   ";
				}
			}

			cout << endl;
			cout << "4" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c6.th[i] < 49 || c6.th[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c6.th[i] << "   ";
				}
			}

			cout << endl;
			cout << "5" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c6.fr[i] < 49 || c6.fr[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c6.fr[i] << "   ";
				}
			}

			cout << endl;
			cout << "6" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c6.sa[i] < 49 || c6.sa[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c6.sa[i] << "   ";
				}
			}

			cout << endl;
			cout << "7" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c6.su[i] < 49 || c6.su[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c6.su[i] << "   ";
				}
			}
			cout << endl << endl;
		}

		


		//c7

		
		if (sellection2 == 7) {
			
			system("cls");
			cout << "SHOW SCHEDULE FOR SPECIFIC CLASSES" << endl;

			
			cout << "D306     cappacity  32" << endl;

			cout << "1" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c7.mo[i] < 49 || c7.mo[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c7.mo[i] << "   ";
				}
			}

			cout << endl;
			cout << "2" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c7.tu[i] < 49 || c7.tu[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c7.tu[i] << "   ";
				}
			}

			cout << endl;
			cout << "3" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c7.we[i] < 49 || c7.we[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c7.we[i] << "   ";
				}
			}

			cout << endl;
			cout << "4" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c7.th[i] < 49 || c7.th[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c7.th[i] << "   ";
				}
			}

			cout << endl;
			cout << "5" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c7.fr[i] < 49 || c7.fr[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c7.fr[i] << "   ";
				}
			}

			cout << endl;
			cout << "6" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c7.sa[i] < 49 || c7.sa[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c7.sa[i] << "   ";
				}
			}

			cout << endl;
			cout << "7" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c7.su[i] < 49 || c7.su[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c7.su[i] << "   ";
				}
			}
			cout << endl << endl;
		}

		


		//c8

		

		if (sellection2 == 8) {
			
			system("cls");
			cout << "SHOW SCHEDULE FOR SPECIFIC CLASSES" << endl;

			
			cout << "D304     cappacity  20" << endl;

			cout << "1" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c8.mo[i] < 49 || c8.mo[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c8.mo[i] << "   ";
				}
			}

			cout << endl;
			cout << "2" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c8.tu[i] < 49 || c8.tu[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c8.tu[i] << "   ";
				}
			}

			cout << endl;
			cout << "3" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c8.we[i] < 49 || c8.we[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c8.we[i] << "   ";
				}
			}

			cout << endl;
			cout << "4" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c8.th[i] < 49 || c8.th[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c8.th[i] << "   ";
				}
			}

			cout << endl;
			cout << "5" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c8.fr[i] < 49 || c8.fr[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c8.fr[i] << "   ";
				}
			}

			cout << endl;
			cout << "6" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c8.sa[i] < 49 || c8.sa[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c8.sa[i] << "   ";
				}
			}

			cout << endl;
			cout << "7" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c8.su[i] < 49 || c8.su[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c8.su[i] << "   ";
				}
			}
			cout << endl << endl;
		}

		


		//c9

	


		if (sellection2 == 9) {
			
			system("cls");
			cout << "SHOW SCHEDULE FOR SPECIFIC CLASSES" << endl;
			
			cout << "D303     cappacity  28" << endl;

			cout << "1" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c9.mo[i] < 49 || c9.mo[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c9.mo[i] << "   ";
				}
			}

			cout << endl;
			cout << "2" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c9.tu[i] < 49 || c9.tu[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c9.tu[i] << "   ";
				}
			}

			cout << endl;
			cout << "3" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c9.we[i] < 49 || c9.we[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c9.we[i] << "   ";
				}
			}

			cout << endl;
			cout << "4" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c9.th[i] < 49 || c9.th[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c9.th[i] << "   ";
				}
			}

			cout << endl;
			cout << "5" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c9.fr[i] < 49 || c9.fr[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c9.fr[i] << "   ";
				}
			}

			cout << endl;
			cout << "6" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c9.sa[i] < 49 || c9.sa[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c9.sa[i] << "   ";
				}
			}

			cout << endl;
			cout << "7" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c9.su[i] < 49 || c9.su[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c9.su[i] << "   ";
				}
			}
			cout << endl << endl;
		}

	


		//c10

		

		if (sellection2 == 10) {
		
			system("cls");
			cout << "SHOW SCHEDULE FOR SPECIFIC CLASSES" << endl;

			
			cout << "D302     cappacity  32" << endl;

			cout << "1" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c10.mo[i] < 49 || c10.mo[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c10.mo[i] << "   ";
				}
			}

			cout << endl;
			cout << "2" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c10.tu[i] < 49 || c10.tu[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c10.tu[i] << "   ";
				}
			}

			cout << endl;
			cout << "3" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c10.we[i] < 49 || c10.we[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c10.we[i] << "   ";
				}
			}

			cout << endl;
			cout << "4" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c10.th[i] < 49 || c10.th[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c10.th[i] << "   ";
				}
			}

			cout << endl;
			cout << "5" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c10.fr[i] < 49 || c10.fr[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c10.fr[i] << "   ";
				}
			}

			cout << endl;
			cout << "6" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c10.sa[i] < 49 || c10.sa[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c10.sa[i] << "   ";
				}
			}

			cout << endl;
			cout << "7" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c10.su[i] < 49 || c10.su[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c10.su[i] << "   ";
				}
			}
			cout << endl << endl;
		}

		


		//c11

	


		if (sellection2 == 11) {
			
			system("cls");
			cout << "SHOW SCHEDULE FOR SPECIFIC CLASSES" << endl;
			
			cout << "D301     cappacity  40" << endl;

			cout << "1" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c11.mo[i] < 49 || c11.mo[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c11.mo[i] << "   ";
				}
			}

			cout << endl;
			cout << "2" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c11.tu[i] < 49 || c11.tu[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c11.tu[i] << "   ";
				}
			}

			cout << endl;
			cout << "3" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c11.we[i] < 49 || c11.we[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c11.we[i] << "   ";
				}
			}

			cout << endl;
			cout << "4" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c11.th[i] < 49 || c11.th[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c11.th[i] << "   ";
				}
			}

			cout << endl;
			cout << "5" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c11.fr[i] < 49 || c11.fr[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c11.fr[i] << "   ";
				}
			}

			cout << endl;
			cout << "6" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c11.sa[i] < 49 || c11.sa[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c11.sa[i] << "   ";
				}
			}

			cout << endl;
			cout << "7" << "   ";
			for (int i = 0; i < 5; i++) {

				if (c11.su[i] < 49 || c11.su[i] > 53) {
					cout << " " << "   ";
				}
				else {
					cout << c11.su[i] << "   ";
				}
			}
			cout << endl << endl;
		}

		system("pause");
		goto MENU;




















	












	



	
	
	
	
	
		//menu3


LISTAVAILABLECLASES:
		
		system("COLOR 08");

		availableclassthing = 1;
		int counter = 0, sellection3 = 0;
        
		system("cls");
		cout << "LIST AVAILABLE CLASES" << endl;
        a.setday();
		
		
		system("cls");
		cout << "LIST AVAILABLE CLASES" << endl;
		a.sethour();

		
		day = a.getday();
		hour = a.gethour();

		goto RANDOM;
LISTAVAILABLECLASES2:

		system("cls");

		for (int i = 0; i < 11; i++) {

			
			if (classtatues[i] != 0) {
				cout << classnames[i] << " is available" << endl;
				counter++;
			}

		}

		system("pause");

		if (counter == 0) {
			cout << "there is no available clases that time" << endl;
			cout << "enter 1 to return menu enter 0 to re enter values: " << endl;
			cin >> sellection3;
			
			if (sellection3 == 0) {
				goto LISTAVAILABLECLASES;
			}
			else {
				goto MENU;
			}
			
		}



		system("pause");
		goto MENU;





































		//MENU 4

LISTAVAILABLEHOURS:
		
		system("COLOR 0D");

		int sellection4;
		int counter1 = 0;
		
		system("cls");
		cout << "LIST AVAILABLE HOURS" << endl;

		
		cout << "menu.....0" << endl;
		cout << "D506.....1" << endl;
		cout << "D505.....2" << endl;
		cout << "D504.....3" << endl;
		cout << "D502.....4" << endl;
		cout << "D501.....5" << endl;
		cout << "D308.....6" << endl;
		cout << "D306.....7" << endl;
		cout << "D304.....8" << endl;
		cout << "D303.....9" << endl;
		cout << "D302.....10" << endl;
		cout << "D301.....11" << endl;
		
		cout << "sellect class: ";
        
		cin >> sellection4;

		if (sellection4 < 0 || sellection4>11) {
			cout << "value should be between 0 and 11" << endl;
			system("pause");
			goto LISTAVAILABLEHOURS;
		}

		
		if (sellection4 == 0) {
			goto MENU;
		}

		
		
		
		system("cls");
		cout << "LIST AVAILABLE HOURS" << endl;

		a.setday();
		day = a.getday();


		
		
		
		
		
		
		


		//c1

		if (sellection4 == 1) {
			system("cls");
			
			cout << "08:30 - 10:30.....1" << endl;
			cout << "10:30 - 12:30.....2" << endl;
			cout << "12:30 - 14:30.....3" << endl;
			cout << "14:30 - 16:30.....4" << endl;
			cout << "16:30 - 18:30.....5" << endl << endl;
			
			
			if (day == 1) {
				for (int i = 0; i < 5; i++) {
					if (c1.mo[i] != '0') {
						cout << c1.mo[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 2) {
				for (int i = 0; i < 5; i++) {
					if (c1.tu[i] != '0') {
						cout << c1.tu[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 3) {
				for (int i = 0; i < 5; i++) {
					if (c1.we[i] != '0') {
						cout << c1.we[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 4) {
				for (int i = 0; i < 5; i++) {
					if (c1.th[i] != '0') {
						cout << c1.th[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 5) {
				for (int i = 0; i < 5; i++) {
					if (c1.fr[i] != '0') {
						cout << c1.fr[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 6) {
				for (int i = 0; i < 5; i++) {
					if (c1.sa[i] != '0') {
						cout << c1.sa[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 7) {
				for (int i = 0; i < 5; i++) {
					if (c1.su[i] != '0') {
						cout << c1.su[i] << " is available" << endl;
						counter1++;
					}

				}

			}

		}


		
		//c2

		if (sellection4 == 2) {
			system("cls");

			cout << "08:30 - 10:30.....1" << endl;
			cout << "10:30 - 12:30.....2" << endl;
			cout << "12:30 - 14:30.....3" << endl;
			cout << "14:30 - 16:30.....4" << endl;
			cout << "16:30 - 18:30.....5" << endl << endl;


			if (day == 1) {
				for (int i = 0; i < 5; i++) {
					if (c2.mo[i] != '0') {
						cout << c2.mo[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 2) {
				for (int i = 0; i < 5; i++) {
					if (c2.tu[i] != '0') {
						cout << c2.tu[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 3) {
				for (int i = 0; i < 5; i++) {
					if (c2.we[i] != '0') {
						cout << c2.we[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 4) {
				for (int i = 0; i < 5; i++) {
					if (c2.th[i] != '0') {
						cout << c2.th[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 5) {
				for (int i = 0; i < 5; i++) {
					if (c2.fr[i] != '0') {
						cout << c2.fr[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 6) {
				for (int i = 0; i < 5; i++) {
					if (c2.sa[i] != '0') {
						cout << c2.sa[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 7) {
				for (int i = 0; i < 5; i++) {
					if (c2.su[i] != '0') {
						cout << c2.su[i] << " is available" << endl;
						counter1++;
					}

				}

			}

		}



		//c3

		if (sellection4 == 3) {
			system("cls");

			cout << "08:30 - 10:30.....1" << endl;
			cout << "10:30 - 12:30.....2" << endl;
			cout << "12:30 - 14:30.....3" << endl;
			cout << "14:30 - 16:30.....4" << endl;
			cout << "16:30 - 18:30.....5" << endl << endl;


			if (day == 1) {
				for (int i = 0; i < 5; i++) {
					if (c3.mo[i] != '0') {
						cout << c3.mo[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 2) {
				for (int i = 0; i < 5; i++) {
					if (c3.tu[i] != '0') {
						cout << c3.tu[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 3) {
				for (int i = 0; i < 5; i++) {
					if (c3.we[i] != '0') {
						cout << c3.we[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 4) {
				for (int i = 0; i < 5; i++) {
					if (c3.th[i] != '0') {
						cout << c3.th[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 5) {
				for (int i = 0; i < 5; i++) {
					if (c3.fr[i] != '0') {
						cout << c3.fr[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 6) {
				for (int i = 0; i < 5; i++) {
					if (c3.sa[i] != '0') {
						cout << c3.sa[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 7) {
				for (int i = 0; i < 5; i++) {
					if (c3.su[i] != '0') {
						cout << c3.su[i] << " is available" << endl;
						counter1++;
					}

				}

			}

		}



		//c4

		if (sellection4 == 4) {
			system("cls");

			cout << "08:30 - 10:30.....1" << endl;
			cout << "10:30 - 12:30.....2" << endl;
			cout << "12:30 - 14:30.....3" << endl;
			cout << "14:30 - 16:30.....4" << endl;
			cout << "16:30 - 18:30.....5" << endl << endl;


			if (day == 1) {
				for (int i = 0; i < 5; i++) {
					if (c4.mo[i] != '0') {
						cout << c4.mo[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 2) {
				for (int i = 0; i < 5; i++) {
					if (c4.tu[i] != '0') {
						cout << c4.tu[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 3) {
				for (int i = 0; i < 5; i++) {
					if (c4.we[i] != '0') {
						cout << c4.we[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 4) {
				for (int i = 0; i < 5; i++) {
					if (c4.th[i] != '0') {
						cout << c4.th[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 5) {
				for (int i = 0; i < 5; i++) {
					if (c4.fr[i] != '0') {
						cout << c4.fr[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 6) {
				for (int i = 0; i < 5; i++) {
					if (c4.sa[i] != '0') {
						cout << c4.sa[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 7) {
				for (int i = 0; i < 5; i++) {
					if (c4.su[i] != '0') {
						cout << c4.su[i] << " is available" << endl;
						counter1++;
					}

				}

			}

		}



		//c5

		if (sellection4 == 5) {
			system("cls");

			cout << "08:30 - 10:30.....1" << endl;
			cout << "10:30 - 12:30.....2" << endl;
			cout << "12:30 - 14:30.....3" << endl;
			cout << "14:30 - 16:30.....4" << endl;
			cout << "16:30 - 18:30.....5" << endl << endl;


			if (day == 1) {
				for (int i = 0; i < 5; i++) {
					if (c5.mo[i] != '0') {
						cout << c5.mo[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 2) {
				for (int i = 0; i < 5; i++) {
					if (c5.tu[i] != '0') {
						cout << c5.tu[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 3) {
				for (int i = 0; i < 5; i++) {
					if (c5.we[i] != '0') {
						cout << c5.we[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 4) {
				for (int i = 0; i < 5; i++) {
					if (c5.th[i] != '0') {
						cout << c5.th[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 5) {
				for (int i = 0; i < 5; i++) {
					if (c5.fr[i] != '0') {
						cout << c5.fr[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 6) {
				for (int i = 0; i < 5; i++) {
					if (c5.sa[i] != '0') {
						cout << c5.sa[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 7) {
				for (int i = 0; i < 5; i++) {
					if (c5.su[i] != '0') {
						cout << c5.su[i] << " is available" << endl;
						counter1++;
					}

				}

			}

		}



		//c6

		if (sellection4 == 6) {
			system("cls");

			cout << "08:30 - 10:30.....1" << endl;
			cout << "10:30 - 12:30.....2" << endl;
			cout << "12:30 - 14:30.....3" << endl;
			cout << "14:30 - 16:30.....4" << endl;
			cout << "16:30 - 18:30.....5" << endl << endl;


			if (day == 1) {
				for (int i = 0; i < 5; i++) {
					if (c6.mo[i] != '0') {
						cout << c6.mo[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 2) {
				for (int i = 0; i < 5; i++) {
					if (c6.tu[i] != '0') {
						cout << c6.tu[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 3) {
				for (int i = 0; i < 5; i++) {
					if (c6.we[i] != '0') {
						cout << c6.we[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 4) {
				for (int i = 0; i < 5; i++) {
					if (c6.th[i] != '0') {
						cout << c6.th[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 5) {
				for (int i = 0; i < 5; i++) {
					if (c6.fr[i] != '0') {
						cout << c6.fr[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 6) {
				for (int i = 0; i < 5; i++) {
					if (c6.sa[i] != '0') {
						cout << c6.sa[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 7) {
				for (int i = 0; i < 5; i++) {
					if (c6.su[i] != '0') {
						cout << c6.su[i] << " is available" << endl;
						counter1++;
					}

				}

			}

		}



		//c7

		if (sellection4 == 7) {
			system("cls");

			cout << "08:30 - 10:30.....1" << endl;
			cout << "10:30 - 12:30.....2" << endl;
			cout << "12:30 - 14:30.....3" << endl;
			cout << "14:30 - 16:30.....4" << endl;
			cout << "16:30 - 18:30.....5" << endl << endl;


			if (day == 1) {
				for (int i = 0; i < 5; i++) {
					if (c7.mo[i] != '0') {
						cout << c7.mo[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 2) {
				for (int i = 0; i < 5; i++) {
					if (c7.tu[i] != '0') {
						cout << c7.tu[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 3) {
				for (int i = 0; i < 5; i++) {
					if (c7.we[i] != '0') {
						cout << c7.we[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 4) {
				for (int i = 0; i < 5; i++) {
					if (c7.th[i] != '0') {
						cout << c7.th[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 5) {
				for (int i = 0; i < 5; i++) {
					if (c7.fr[i] != '0') {
						cout << c7.fr[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 6) {
				for (int i = 0; i < 5; i++) {
					if (c7.sa[i] != '0') {
						cout << c7.sa[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 7) {
				for (int i = 0; i < 5; i++) {
					if (c7.su[i] != '0') {
						cout << c7.su[i] << " is available" << endl;
						counter1++;
					}

				}

			}

		}



		//c8

		if (sellection4 == 8) {
			system("cls");

			cout << "08:30 - 10:30.....1" << endl;
			cout << "10:30 - 12:30.....2" << endl;
			cout << "12:30 - 14:30.....3" << endl;
			cout << "14:30 - 16:30.....4" << endl;
			cout << "16:30 - 18:30.....5" << endl << endl;


			if (day == 1) {
				for (int i = 0; i < 5; i++) {
					if (c8.mo[i] != '0') {
						cout << c8.mo[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 2) {
				for (int i = 0; i < 5; i++) {
					if (c8.tu[i] != '0') {
						cout << c8.tu[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 3) {
				for (int i = 0; i < 5; i++) {
					if (c8.we[i] != '0') {
						cout << c8.we[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 4) {
				for (int i = 0; i < 5; i++) {
					if (c8.th[i] != '0') {
						cout << c8.th[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 5) {
				for (int i = 0; i < 5; i++) {
					if (c8.fr[i] != '0') {
						cout << c8.fr[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 6) {
				for (int i = 0; i < 5; i++) {
					if (c8.sa[i] != '0') {
						cout << c8.sa[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 7) {
				for (int i = 0; i < 5; i++) {
					if (c8.su[i] != '0') {
						cout << c8.su[i] << " is available" << endl;
						counter1++;
					}

				}

			}

		}



		//c9

		if (sellection4 == 9) {
			system("cls");

			cout << "08:30 - 10:30.....1" << endl;
			cout << "10:30 - 12:30.....2" << endl;
			cout << "12:30 - 14:30.....3" << endl;
			cout << "14:30 - 16:30.....4" << endl;
			cout << "16:30 - 18:30.....5" << endl << endl;


			if (day == 1) {
				for (int i = 0; i < 5; i++) {
					if (c9.mo[i] != '0') {
						cout << c9.mo[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 2) {
				for (int i = 0; i < 5; i++) {
					if (c9.tu[i] != '0') {
						cout << c9.tu[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 3) {
				for (int i = 0; i < 5; i++) {
					if (c9.we[i] != '0') {
						cout << c9.we[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 4) {
				for (int i = 0; i < 5; i++) {
					if (c9.th[i] != '0') {
						cout << c9.th[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 5) {
				for (int i = 0; i < 5; i++) {
					if (c9.fr[i] != '0') {
						cout << c9.fr[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 6) {
				for (int i = 0; i < 5; i++) {
					if (c9.sa[i] != '0') {
						cout << c9.sa[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 7) {
				for (int i = 0; i < 5; i++) {
					if (c9.su[i] != '0') {
						cout << c9.su[i] << " is available" << endl;
						counter1++;
					}

				}

			}

		}



		//c10

		if (sellection4 == 10) {
			system("cls");

			cout << "08:30 - 10:30.....1" << endl;
			cout << "10:30 - 12:30.....2" << endl;
			cout << "12:30 - 14:30.....3" << endl;
			cout << "14:30 - 16:30.....4" << endl;
			cout << "16:30 - 18:30.....5" << endl << endl;


			if (day == 1) {
				for (int i = 0; i < 5; i++) {
					if (c10.mo[i] != '0') {
						cout << c10.mo[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 2) {
				for (int i = 0; i < 5; i++) {
					if (c10.tu[i] != '0') {
						cout << c10.tu[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 3) {
				for (int i = 0; i < 5; i++) {
					if (c10.we[i] != '0') {
						cout << c10.we[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 4) {
				for (int i = 0; i < 5; i++) {
					if (c10.th[i] != '0') {
						cout << c10.th[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 5) {
				for (int i = 0; i < 5; i++) {
					if (c10.fr[i] != '0') {
						cout << c10.fr[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 6) {
				for (int i = 0; i < 5; i++) {
					if (c10.sa[i] != '0') {
						cout << c10.sa[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 7) {
				for (int i = 0; i < 5; i++) {
					if (c10.su[i] != '0') {
						cout << c10.su[i] << " is available" << endl;
						counter1++;
					}

				}

			}

		}



      
		//c11


		if (sellection4 == 11) {
			system("cls");

			cout << "08:30 - 10:30.....1" << endl;
			cout << "10:30 - 12:30.....2" << endl;
			cout << "12:30 - 14:30.....3" << endl;
			cout << "14:30 - 16:30.....4" << endl;
			cout << "16:30 - 18:30.....5" << endl << endl;


			if (day == 1) {
				for (int i = 0; i < 5; i++) {
					if (c11.mo[i] != '0') {
						cout << c11.mo[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 2) {
				for (int i = 0; i < 5; i++) {
					if (c11.tu[i] != '0') {
						cout << c11.tu[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 3) {
				for (int i = 0; i < 5; i++) {
					if (c11.we[i] != '0') {
						cout << c11.we[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 4) {
				for (int i = 0; i < 5; i++) {
					if (c11.th[i] != '0') {
						cout << c11.th[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 5) {
				for (int i = 0; i < 5; i++) {
					if (c11.fr[i] != '0') {
						cout << c11.fr[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 6) {
				for (int i = 0; i < 5; i++) {
					if (c11.sa[i] != '0') {
						cout << c11.sa[i] << " is available" << endl;
						counter1++;
					}

				}

			}

			if (day == 7) {
				for (int i = 0; i < 5; i++) {
					if (c11.su[i] != '0') {
						cout << c11.su[i] << " is available" << endl;
						counter1++;
					}

				}

			}

		}
		


		if (counter1 == 0) {
			system("cls");
			cout << "there are no avaliable hours at that day" << endl;
		}



		system("pause");
		goto MENU;

		


































































































		


			//menu5

		LISTAVAILABLEDAYS:

			system("COLOR 0E");

			int sellection5;
			int counter2 = 0;

			system("cls");
			cout << "LIST AVAILABLE DAYS" << endl;


			cout << "menu.....0" << endl;
			cout << "D506.....1" << endl;
			cout << "D505.....2" << endl;
			cout << "D504.....3" << endl;
			cout << "D502.....4" << endl;
			cout << "D501.....5" << endl;
			cout << "D308.....6" << endl;
			cout << "D306.....7" << endl;
			cout << "D304.....8" << endl;
			cout << "D303.....9" << endl;
			cout << "D302.....10" << endl;
			cout << "D301.....11" << endl;

			cout << "sellect class: ";

			cin >> sellection5;

			if (sellection5 < 0 || sellection5 > 11) {
				cout << "value should be between 0 and 11" << endl;
				system("pause");
				goto LISTAVAILABLEHOURS;
			}


			if (sellection5 == 0) {
				goto MENU;
			}




			system("cls");
			cout << "LIST AVAILABLE DAYS" << endl;

			a.sethour();
			hour = a.gethour();



			//c1

			if (sellection5 == 1) {
				system("cls");

				cout << "monday.......1" << endl;
				cout << "tuesday......2" << endl;
				cout << "wednesday....3" << endl;
				cout << "thursday.....4" << endl;
				cout << "friday.......5" << endl;
				cout << "saturday.....6" << endl;
				cout << "sunday.......7" << endl << endl;




				if (c1.mo[hour - 1] != '0') {
					cout << "monday(1) is available" << endl;
					counter2++;
				}

				if (c1.tu[hour - 1] != '0') {
					cout << "tuesday(2) is available" << endl;
					counter2++;
				}

				if (c1.we[hour - 1] != '0') {
					cout << "wednesday(3) is available" << endl;
					counter2++;
				}

				if (c1.th[hour - 1] != '0') {
					cout << "thursday(4) is available" << endl;
					counter2++;
				}

				if (c1.fr[hour - 1] != '0') {
					cout << "friday(5) is available" << endl;
					counter2++;
				}

				if (c1.sa[hour - 1] != '0') {
					cout << "saturday(6) is available" << endl;
					counter2++;
				}

				if (c1.su[hour - 1] != '0') {
					cout << "sunday(7) is available" << endl;
					counter2++;
				}


			}



			//c2

			if (sellection5 == 2) {
				system("cls");

				cout << "monday.......1" << endl;
				cout << "tuesday......2" << endl;
				cout << "wednesday....3" << endl;
				cout << "thursday.....4" << endl;
				cout << "friday.......5" << endl;
				cout << "saturday.....6" << endl;
				cout << "sunday.......7" << endl << endl;




				if (c2.mo[hour - 1] != '0') {
					cout << "monday(1) is available" << endl;
					counter2++;
				}

				if (c2.tu[hour - 1] != '0') {
					cout << "tuesday(2) is available" << endl;
					counter2++;
				}

				if (c2.we[hour - 1] != '0') {
					cout << "wednesday(3) is available" << endl;
					counter2++;
				}

				if (c2.th[hour - 1] != '0') {
					cout << "thursday(4) is available" << endl;
					counter2++;
				}

				if (c2.fr[hour - 1] != '0') {
					cout << "friday(5) is available" << endl;
					counter2++;
				}

				if (c2.sa[hour - 1] != '0') {
					cout << "saturday(6) is available" << endl;
					counter2++;
				}

				if (c2.su[hour - 1] != '0') {
					cout << "sunday(7) is available" << endl;
					counter2++;
				}


			}



			//c3

			if (sellection5 == 3) {
				system("cls");

				cout << "monday.......1" << endl;
				cout << "tuesday......2" << endl;
				cout << "wednesday....3" << endl;
				cout << "thursday.....4" << endl;
				cout << "friday.......5" << endl;
				cout << "saturday.....6" << endl;
				cout << "sunday.......7" << endl << endl;




				if (c3.mo[hour - 1] != '0') {
					cout << "monday(1) is available" << endl;
					counter2++;
				}

				if (c3.tu[hour - 1] != '0') {
					cout << "tuesday(2) is available" << endl;
					counter2++;
				}

				if (c3.we[hour - 1] != '0') {
					cout << "wednesday(3) is available" << endl;
					counter2++;
				}

				if (c3.th[hour - 1] != '0') {
					cout << "thursday(4) is available" << endl;
					counter2++;
				}

				if (c3.fr[hour - 1] != '0') {
					cout << "friday(5) is available" << endl;
					counter2++;
				}

				if (c3.sa[hour - 1] != '0') {
					cout << "saturday(6) is available" << endl;
					counter2++;
				}

				if (c3.su[hour - 1] != '0') {
					cout << "sunday(7) is available" << endl;
					counter2++;
				}


			}



			//c4

			if (sellection5 == 4) {
				system("cls");

				cout << "monday.......1" << endl;
				cout << "tuesday......2" << endl;
				cout << "wednesday....3" << endl;
				cout << "thursday.....4" << endl;
				cout << "friday.......5" << endl;
				cout << "saturday.....6" << endl;
				cout << "sunday.......7" << endl << endl;




				if (c4.mo[hour - 1] != '0') {
					cout << "monday(1) is available" << endl;
					counter2++;
				}

				if (c4.tu[hour - 1] != '0') {
					cout << "tuesday(2) is available" << endl;
					counter2++;
				}

				if (c4.we[hour - 1] != '0') {
					cout << "wednesday(3) is available" << endl;
					counter2++;
				}

				if (c4.th[hour - 1] != '0') {
					cout << "thursday(4) is available" << endl;
					counter2++;
				}

				if (c4.fr[hour - 1] != '0') {
					cout << "friday(5) is available" << endl;
					counter2++;
				}

				if (c4.sa[hour - 1] != '0') {
					cout << "saturday(6) is available" << endl;
					counter2++;
				}

				if (c4.su[hour - 1] != '0') {
					cout << "sunday(7) is available" << endl;
					counter2++;
				}


			}



			//c5

			if (sellection5 == 5) {
				system("cls");

				cout << "monday.......1" << endl;
				cout << "tuesday......2" << endl;
				cout << "wednesday....3" << endl;
				cout << "thursday.....4" << endl;
				cout << "friday.......5" << endl;
				cout << "saturday.....6" << endl;
				cout << "sunday.......7" << endl << endl;




				if (c5.mo[hour - 1] != '0') {
					cout << "monday(1) is available" << endl;
					counter2++;
				}

				if (c5.tu[hour - 1] != '0') {
					cout << "tuesday(2) is available" << endl;
					counter2++;
				}

				if (c5.we[hour - 1] != '0') {
					cout << "wednesday(3) is available" << endl;
					counter2++;
				}

				if (c5.th[hour - 1] != '0') {
					cout << "thursday(4) is available" << endl;
					counter2++;
				}

				if (c5.fr[hour - 1] != '0') {
					cout << "friday(5) is available" << endl;
					counter2++;
				}

				if (c5.sa[hour - 1] != '0') {
					cout << "saturday(6) is available" << endl;
					counter2++;
				}

				if (c5.su[hour - 1] != '0') {
					cout << "sunday(7) is available" << endl;
					counter2++;
				}


			}



			//c6

			if (sellection5 == 6) {
				system("cls");

				cout << "monday.......1" << endl;
				cout << "tuesday......2" << endl;
				cout << "wednesday....3" << endl;
				cout << "thursday.....4" << endl;
				cout << "friday.......5" << endl;
				cout << "saturday.....6" << endl;
				cout << "sunday.......7" << endl << endl;




				if (c6.mo[hour - 1] != '0') {
					cout << "monday(1) is available" << endl;
					counter2++;
				}

				if (c6.tu[hour - 1] != '0') {
					cout << "tuesday(2) is available" << endl;
					counter2++;
				}

				if (c6.we[hour - 1] != '0') {
					cout << "wednesday(3) is available" << endl;
					counter2++;
				}

				if (c6.th[hour - 1] != '0') {
					cout << "thursday(4) is available" << endl;
					counter2++;
				}

				if (c6.fr[hour - 1] != '0') {
					cout << "friday(5) is available" << endl;
					counter2++;
				}

				if (c6.sa[hour - 1] != '0') {
					cout << "saturday(6) is available" << endl;
					counter2++;
				}

				if (c6.su[hour - 1] != '0') {
					cout << "sunday(7) is available" << endl;
					counter2++;
				}


			}



			//c7

			if (sellection5 == 7) {
				system("cls");

				cout << "monday.......1" << endl;
				cout << "tuesday......2" << endl;
				cout << "wednesday....3" << endl;
				cout << "thursday.....4" << endl;
				cout << "friday.......5" << endl;
				cout << "saturday.....6" << endl;
				cout << "sunday.......7" << endl << endl;




				if (c7.mo[hour - 1] != '0') {
					cout << "monday(1) is available" << endl;
					counter2++;
				}

				if (c7.tu[hour - 1] != '0') {
					cout << "tuesday(2) is available" << endl;
					counter2++;
				}

				if (c7.we[hour - 1] != '0') {
					cout << "wednesday(3) is available" << endl;
					counter2++;
				}

				if (c7.th[hour - 1] != '0') {
					cout << "thursday(4) is available" << endl;
					counter2++;
				}

				if (c7.fr[hour - 1] != '0') {
					cout << "friday(5) is available" << endl;
					counter2++;
				}

				if (c7.sa[hour - 1] != '0') {
					cout << "saturday(6) is available" << endl;
					counter2++;
				}

				if (c7.su[hour - 1] != '0') {
					cout << "sunday(7) is available" << endl;
					counter2++;
				}


			}



			//c8

			if (sellection5 == 8) {
				system("cls");

				cout << "monday.......1" << endl;
				cout << "tuesday......2" << endl;
				cout << "wednesday....3" << endl;
				cout << "thursday.....4" << endl;
				cout << "friday.......5" << endl;
				cout << "saturday.....6" << endl;
				cout << "sunday.......7" << endl << endl;




				if (c8.mo[hour - 1] != '0') {
					cout << "monday(1) is available" << endl;
					counter2++;
				}

				if (c8.tu[hour - 1] != '0') {
					cout << "tuesday(2) is available" << endl;
					counter2++;
				}

				if (c8.we[hour - 1] != '0') {
					cout << "wednesday(3) is available" << endl;
					counter2++;
				}

				if (c8.th[hour - 1] != '0') {
					cout << "thursday(4) is available" << endl;
					counter2++;
				}

				if (c8.fr[hour - 1] != '0') {
					cout << "friday(5) is available" << endl;
					counter2++;
				}

				if (c8.sa[hour - 1] != '0') {
					cout << "saturday(6) is available" << endl;
					counter2++;
				}

				if (c8.su[hour - 1] != '0') {
					cout << "sunday(7) is available" << endl;
					counter2++;
				}


			}



			//c9

			if (sellection5 == 9) {
				system("cls");

				cout << "monday.......1" << endl;
				cout << "tuesday......2" << endl;
				cout << "wednesday....3" << endl;
				cout << "thursday.....4" << endl;
				cout << "friday.......5" << endl;
				cout << "saturday.....6" << endl;
				cout << "sunday.......7" << endl << endl;




				if (c9.mo[hour - 1] != '0') {
					cout << "monday(1) is available" << endl;
					counter2++;
				}

				if (c9.tu[hour - 1] != '0') {
					cout << "tuesday(2) is available" << endl;
					counter2++;
				}

				if (c9.we[hour - 1] != '0') {
					cout << "wednesday(3) is available" << endl;
					counter2++;
				}

				if (c9.th[hour - 1] != '0') {
					cout << "thursday(4) is available" << endl;
					counter2++;
				}

				if (c9.fr[hour - 1] != '0') {
					cout << "friday(5) is available" << endl;
					counter2++;
				}

				if (c9.sa[hour - 1] != '0') {
					cout << "saturday(6) is available" << endl;
					counter2++;
				}

				if (c9.su[hour - 1] != '0') {
					cout << "sunday(7) is available" << endl;
					counter2++;
				}


			}



			//c10

			if (sellection5 == 10) {
				system("cls");

				cout << "monday.......1" << endl;
				cout << "tuesday......2" << endl;
				cout << "wednesday....3" << endl;
				cout << "thursday.....4" << endl;
				cout << "friday.......5" << endl;
				cout << "saturday.....6" << endl;
				cout << "sunday.......7" << endl << endl;




				if (c10.mo[hour - 1] != '0') {
					cout << "monday(1) is available" << endl;
					counter2++;
				}

				if (c10.tu[hour - 1] != '0') {
					cout << "tuesday(2) is available" << endl;
					counter2++;
				}

				if (c10.we[hour - 1] != '0') {
					cout << "wednesday(3) is available" << endl;
					counter2++;
				}

				if (c10.th[hour - 1] != '0') {
					cout << "thursday(4) is available" << endl;
					counter2++;
				}

				if (c10.fr[hour - 1] != '0') {
					cout << "friday(5) is available" << endl;
					counter2++;
				}

				if (c10.sa[hour - 1] != '0') {
					cout << "saturday(6) is available" << endl;
					counter2++;
				}

				if (c10.su[hour - 1] != '0') {
					cout << "sunday(7) is available" << endl;
					counter2++;
				}


			}



			//c11

			if (sellection5 == 11) {
				system("cls");

				cout << "monday.......1" << endl;
				cout << "tuesday......2" << endl;
				cout << "wednesday....3" << endl;
				cout << "thursday.....4" << endl;
				cout << "friday.......5" << endl;
				cout << "saturday.....6" << endl;
				cout << "sunday.......7" << endl << endl;




				if (c11.mo[hour - 1] != '0') {
					cout << "monday(1) is available" << endl;
					counter2++;
				}

				if (c11.tu[hour - 1] != '0') {
					cout << "tuesday(2) is available" << endl;
					counter2++;
				}

				if (c11.we[hour - 1] != '0') {
					cout << "wednesday(3) is available" << endl;
					counter2++;
				}

				if (c11.th[hour - 1] != '0') {
					cout << "thursday(4) is available" << endl;
					counter2++;
				}

				if (c11.fr[hour - 1] != '0') {
					cout << "friday(5) is available" << endl;
					counter2++;
				}

				if (c11.sa[hour - 1] != '0') {
					cout << "saturday(6) is available" << endl;
					counter2++;
				}

				if (c11.su[hour - 1] != '0') {
					cout << "sunday(7) is available" << endl;
					counter2++;
				}


			}





			if (counter2 == 0) {
				system("cls");
				cout << "there are no avaliable days at that time" << endl;
			}



			system("pause");
			goto MENU;
		

	




}