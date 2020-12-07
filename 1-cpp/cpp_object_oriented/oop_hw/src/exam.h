#include <iostream>
#include <string>
using namespace std;

class exam {
private:
	string name, code, codewithtxt;
	int day, hour, students;
public:
	exam();
	


	void exam::createexam();


	void exam::setday();
	void exam::sethour();
	void exam::setcodewithtxt(string);



	string exam::getname();
	string exam::getcode();
	int exam::getday();
	int exam::gethour();
	int exam::getstudents();
	string exam::getcodewithtxt();








};
