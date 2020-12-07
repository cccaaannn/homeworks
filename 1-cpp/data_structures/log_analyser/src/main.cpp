#include <iostream> 
#include <fstream> 
#include "string"
#include "ctime"
#include "stdlib.h"
#include "aray.h"
#include "read.h"
#include "list.h"
#include "binaryinsearcht.h"
using namespace std;


int main() {

	clock_t start, stop;
	double t1;
	string text;
	
	
	start = clock();                        //start timer

	 

	aray can(50000);                        //create aray

	text = read("access_log");              //read

	binaryINSERACHT(can, text);             //count-insert  

	list(can);                              //show




	stop = clock();                         //end timer


	t1 = (double)(stop - start) / CLOCKS_PER_SEC * 1000.0;


	cout << endl << t1 << " ms total time" << endl << endl;


	system("pause");
}