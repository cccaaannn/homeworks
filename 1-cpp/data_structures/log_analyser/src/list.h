#pragma once
#include <iostream> 
#include "string"
#include "aray.h"
using namespace std;




void list(aray &can) {
	for (int j = 0; j < 10; j++) {
		int buyuk = 0;
		int yer = 0;
		for (int i = 0; i < 50000; i++)
		{
			if (can.retrieve1(i) > buyuk && can.retrieve(i) != "")
			{
				buyuk = can.retrieve1(i);    //search the aray find biggest
				yer = i;
			}
		}
		cout << j + 1 << "- " << can.retrieve(yer) << " (" << can.retrieve1(yer) << ") times repeated" << endl;
		can.counetrrsifirlayici(yer);    //makes the biggest value 0

	}
}


