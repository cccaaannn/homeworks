#include <iostream>
// #include <windows.h>

using namespace std;

int main() {
		A:
	
	int a, b = 1;
	cin >> a;
	
	system("cls");
	system("color 02");

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if (j >= i) {
				cout << " ";
			}
		}
		
		cout << "*";
		
		
		if (i != 0) {
			for (int k = 0; k < b ; k++) {
				cout << " ";
			}
			b = b + 2;
		}
		
		if (i != 0) {
			cout << "*";
		}
		
		cout << endl;
		
	}

	
	
	b = b - 4;
	

	
	for (int i = 0; i < a -1 ; i++) {
		for (int j = 0; j < a ; j++) {
			if (j <= i) {
				cout << " ";
			}
		}
		
		cout << " ";
		cout << "*";


		if (i != a - 1) {
			for (int k = 0; k < b; k++) {
				cout << " ";
			}
			b = b - 2;
		}

		if (i != a - 2) {
			cout << "*";
		}

		cout << endl;
	}
	
	cout << endl;
	system("pause");

	goto A;
}