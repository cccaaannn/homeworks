#include <iostream>
using namespace std;


int main() {
	
	for (int i = 1; i < 101; i++) {
		
		int x = 0, y = 0, z = 0;
		
		if (i % 5 == 0 && i % 3 == 0) {
			cout << "fizzbuzz" << endl;
			x = 1;
		}

		if (i % 5 == 0 && x == 0) {
			cout << "buzz" << endl;
			y = 1;
		}

		if (i % 3 == 0 && x == 0) {
			cout << "fizz" << endl;
			z = 1;
		}

		if (x == 0 && y == 0 && z == 0) {
			cout << i << endl;
		}


	}










}