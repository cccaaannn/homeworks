#include "exam.h"

exam::exam() {
	string name = "aaa", code = "aaa", codewithtxt = "aaa.txt";
	int day = 1, hour = 1, students = 1;
};



void exam::createexam() {
	
	
	system("cls");

	cout << "CREATE EXAM" << endl << endl;

	cout << "enter course name: ";
	cin >> name;
	system("cls");

	cout << "CREATE EXAM" << endl << endl;

	cout << "enter course code: ";
	cin >> code;
	
	
A:	
	system("cls");

	cout << "CREATE EXAM" << endl << endl;

	cout << "enter number of students: ";
	cin >> students;
	if (students > 340) {
		cout << "there is not enough class in school" << endl;
		cout << "reenter value" << endl;
		system("pause");
		goto A;
	}
	
	
	

	
B:

	system("cls");

	cout << "CREATE EXAM" << endl << endl;

	cout << "for monday...... write 1" << endl;
	cout << "for tuesday..... write 2" << endl;
	cout << "for wednesday....write 3" << endl;
	cout << "for thursday.....write 4" << endl;
	cout << "for friday.......write 5" << endl;
	cout << "for saturday.... write 6" << endl;
	cout << "for sunday.......write 7" << endl;

	cout << "enter the reservation day (just write the day code): ";
	cin >> day;

	if (day != 1 && day != 2 && day != 3 && day != 4 && day != 5 && day != 6 && day != 7) {
		cout << "\nday value should be 1,2,3,4,5,6 or 7" << endl;
		cout << "please reenter the day" << endl;
		system("pause");
		system("cls");
		goto B;
	};





C:

	system("cls");

	cout << "CREATE EXAM" << endl << endl;

	cout << "for 08:30 - 10:30  write 1" << endl;
	cout << "for 10:30 - 12:30  write 2" << endl;
	cout << "for 12:30 - 14:30  write 3" << endl;
	cout << "for 14:30 - 16:30  write 4" << endl;
	cout << "for 16:30 - 18:30  write 5" << endl;

	cout << "enter the reservation hour (just write the hour code): ";
	cin >> hour;

	if (hour != 1 && hour != 2 && hour != 3 && hour != 4 && hour != 5) {
		cout << "\nhour should be 1,2,3,4 or 5" << endl;
		cout << "please reenter the hour" << endl;
		system("pause");
		system("cls");
		goto C;
	};




};


void exam::setday() {
A:

	cout << "for monday...... write 1" << endl;
	cout << "for tuesday..... write 2" << endl;
	cout << "for wednesday....write 3" << endl;
	cout << "for thursday.....write 4" << endl;
	cout << "for friday.......write 5" << endl;
	cout << "for saturday.... write 6" << endl;
	cout << "for sunday.......write 7" << endl;

	cout << "enter the reservation day (just write the day code): ";
	cin >> day;

	if (day != 1 && day != 2 && day != 3 && day != 4 && day != 5 && day != 6 && day != 7) {
		cout << "\nday value should be 1,2,3,4,5,6 or 7" << endl;
		cout << "please reenter the day" << endl;
		system("pause");
		system("cls");
		goto A;
	};
}

void exam::sethour() {
	system("cls");



B:
	

	cout << "for 08:30 - 10:30  write 1" << endl;
	cout << "for 10:30 - 12:30  write 2" << endl;
	cout << "for 12:30 - 14:30  write 3" << endl;
	cout << "for 14:30 - 16:30  write 4" << endl;
	cout << "for 16:30 - 18:30  write 5" << endl;

	cout << "enter the reservation hour (just write the hour code): ";
	cin >> hour;

	if (hour != 1 && hour != 2 && hour != 3 && hour != 4 && hour != 5) {
		cout << "\nhour should be 1,2,3,4 or 5" << endl;
		cout << "please reenter the hour" << endl;
		system("pause");
		system("cls");
		goto B;
	}
}

void exam::setcodewithtxt(string a) {
	codewithtxt = a;
}





string exam::getname() {
	return name;
};


string exam::getcode() {
	return code;
};

int exam::getday() {
	return day;
};

int exam::gethour() {
	return hour;
};

int exam::getstudents() {
	return students;
};

string exam::getcodewithtxt() {
	return codewithtxt;
}