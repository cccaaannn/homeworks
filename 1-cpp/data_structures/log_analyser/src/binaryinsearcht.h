#pragma once
#include <iostream> 
#include <fstream> 
#include "string"
#include "aray.h"
using namespace std;


string d;
int za;

void binaryINSERACHT(aray &can, string a) {

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//horspool string matching

	string T = "GET ";

	int k = 0, flag = 0;

	int m = 4;
	long long n = a.length();
	long long  j;
	long long ii;

	cout << "length of the text: " << n << endl << endl;  //shows length of the text

	ii = m - 1;

	while (ii <= n - 1) {   //stop et the end of the text

		k = 0;
		while (k <= m - 1 && T[m - 1 - k] == a[ii - k]) {
			k++;
		}
		if (k == m) {
			ii++;

			//taking text after GET to emty character
			int p = 0;
			while (a[ii + p] != ' ') {
				d += a[ii + p];
				p++;
			}

			za = can.binarysearch(d);             //binary search

			if (za == -1) {                       //if binary search can't found the pattern insert the pattern to the suitable loaction

				if (can.pozisyon <= 0) {                    //if pattert at the begining
					can.ittirici(0);
					can.insert(0, d);
				}
				else if (can.pozisyon >= can.listsize()) {       //if pattern at the end
					can.ittirici(can.pozisyon);
					can.insert(can.pozisyon, d);
				}
				else if (can.retrieve(can.pozisyon) > d) {         //if pattern smaller than the position
					can.ittirici(can.pozisyon);
					can.insert(can.pozisyon, d);
				}
				else if (can.retrieve(can.pozisyon) < d) {            //if pattern biggern than the position
					can.ittirici(can.pozisyon + 1);
					can.insert(can.pozisyon + 1, d);
				}

			}
			else {
				can.increasecountt(za);          //if binary search can found the pattern increase the count of that pattern
			}

			za = 0;
			can.pozisyon = 0;

			d = "";
			ii = ii + m - 1;

		}


		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//rest of the horespool modified for only "GET "
		else {
			if (a[ii] == 'G') {
				ii = ii + 3;
			}
			else if (a[ii] == 'E') {
				ii = ii + 2;
			}
			else if (a[ii] == 'T') {
				ii = ii + 1;
			}
			else {
				ii = ii + 4;

			}
		}


	}

}
