#pragma once
#include <iostream> 
#include <fstream> 
#include "string"
using namespace std;


string read(string text) {

	ifstream access_log;                               //open file
	access_log.open(text);


	ifstream file(text, ios_base::in | ios_base::ate);
	long file_length = file.tellg();                   //go to the last
	file.seekg(0, ios_base::beg);                      //take all between last and first
	file.clear();

	char *text2 = new char[file_length];
	file.read(text2, file_length);

	return text2;
}