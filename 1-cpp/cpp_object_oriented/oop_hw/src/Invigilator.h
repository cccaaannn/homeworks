#include <iostream>
#include <fstream>
using namespace std;

class Invigilator {
public:
	char mo[5], tu[5], we[5], th[5], fr[5], sa[5], su[5];

	string name;
	string Invigilatornumber;
	string Invigilatorwithtxt;

	Invigilator(string,string);
};