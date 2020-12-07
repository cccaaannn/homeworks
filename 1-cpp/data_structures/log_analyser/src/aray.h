#pragma once
#include<iostream>
#include<cassert>
#include<string>

using namespace std;


class aray {
	string *list;  //value
	int *countt;   //count
	int maxsize;
	int length;
public:
	//cnstruct-destruct
	aray(int);
	~aray();

	//general
	int listsize()const;
	void insert(int, string);
	void replace(int, string);

	//retrieve
	void retrieve2(int, string&, int&)const;
	int retrieve1(int)const;
	string retrieve(int)const;

	//search
	int binarysearch(string);
	int pozisyon = 0;

	//push
	void ittirici(int);

	//count
	void increasecountt(int);
	void counetrrsifirlayici(int);
};

