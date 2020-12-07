#include <iostream> 
#include <fstream> 
#include "string"
#include "ctime"



using namespace std;

int C = 0, D = 0;
int E = 0, F = 0;
int a = 0, b = 0;

int bruteforcestringmatch(const string &T, const string &P) {

	C = 0, D = 0;

	int n = T.length();
	int m = P.length();

	for (int i = 0; i <= n - m; ++i) {
		int j = 0;
		D++;

		while (j < m && T[i + j] == P[j]) {

			j++;

			if (b == 1)
			{
				C++;
			}
			a = 1;
			b = 1;
		}


		if (j == m) {

			return i;
		}

		if (a == 1) { 
			D++;
			a = 0;
			b = 0;
		}


	}




	return -1;


}


int horspoolstringmatching(const string &P, const string &T) {

	E = 0, F = 0;

	int table[126];

	int k = 0, flag = 0;

	int m = T.length();
	int n = P.length();
	int i, j;


	for (i = 0; i < 126; i++)
		table[i] = m;
	for (j = 0; j < m - 1; j++)
		table[T[j]] = m - 1 - j;


	i = m - 1;

	while (i <= n - 1) {

		E++;

		k = 0;
		while (k <= m - 1 && T[m - 1 - k] == P[i - k]) {
			k++;
		}

		F = F + k;


		if (k == m) {
			return i - m + 1;
			flag = 1;
			break;
		}


		else {
			i = i + table[P[i]];
		}


	}
	if (!flag)
		return -1;


}





string randomstringgenerator(const int L) {
	string S;
	static const char A[] = "0123456789""ABCDEFGHIJKLMNOPQRSTUVWXYZ""abcdefghijklmnopqrstuvwxyz""?.!,";
	for (int i = 0; i < L; i++) {
		S += A[rand() % (sizeof(A) - 1)];
	}
	return S;
}








int main() {

	clock_t start, stop;
	double t1, t2, t3;
	string T, P;
	int menu_loop = 1;


	ifstream the_truman_show_script;
	the_truman_show_script.open("the_truman_show_script.txt");
	while (getline(the_truman_show_script, T)) {

	}
	T.erase(0, 3);

	/*cout << T << endl;*/


	while (menu_loop == 1) {
		int location1 = 0, location2 = 0;
		int menu_selection = -1;


		system("cls");

		cout << "(1) Brute-Force String Matching" << endl;
		cout << "(2) Horspool's String Matching" << endl;
		cout << "(3) Compare brute-force and Horspool's string matching algorithms" << endl;
		cout << "(4) Analyze the average-case efficiencies of brute-force and Horspool's algorithms" << endl;
		cout << "(0) Exit" << endl;

		cout << ":";
		cin >> menu_selection;

		if (menu_selection < 0 || menu_selection > 4) {
			cout << "selection should be between 0 and 4" << endl;
				system("pause");
		}


		cin.ignore(numeric_limits<streamsize>::max(), '\n');







		if (menu_selection == 1) {

			cout << "enter pattern" << endl;
			getline(cin, P);



			start = clock();
			location1 = bruteforcestringmatch(T, P);
			stop = clock();
			t1 = (double)(stop - start) / CLOCKS_PER_SEC * 1000.0;

			system("cls");

			cout << "Brute-Force String Matching" << endl << endl;

			cout << "patern: " << P << endl;
			if (location1 != -1) {
				cout << "pattern starts after .....(" << location1 << ") th character of the text" << endl;
			}
			else {
				cout << "pattern is NOT found in the text" << endl;
			}
			cout << "basic operation executed .(" << C + D - 1 << ") times" << endl;
			cout << "execution time is ........(" << t1 << ") ms" << endl << endl;

			system("pause");

		}











		if (menu_selection == 2) {

			cout << "enter pattern" << endl;
			getline(cin, P);

			start = clock();
			location2 = horspoolstringmatching(T, P);
			stop = clock();
			t2 = (double)(stop - start) / CLOCKS_PER_SEC * 1000.0;

			system("cls");

			cout << "Horspool's String Matching" << endl << endl;

			cout << "patern: " << P << endl;
			if (location1 != -1) {
				cout << "pattern starts after .....(" << location2 << ") th character of the text" << endl;
			}
			else {
				cout << "pattern is NOT found in the text" << endl;
			}
			cout << "basic operation executed .(" << E + F - 1 << ") times" << endl;
			cout << "execution time is ........(" << t2 << ") ms" << endl << endl;


			system("pause");


		}






		if (menu_selection == 3) {

			cout << "enter pattern" << endl;
			getline(cin, P);

			system("cls");

			start = clock();
			location1 = bruteforcestringmatch(T, P);
			stop = clock();
			t1 = (double)(stop - start) / CLOCKS_PER_SEC * 1000.0;

			start = clock();
			location2 = horspoolstringmatching(T, P);
			stop = clock();
			t2 = (double)(stop - start) / CLOCKS_PER_SEC * 1000.0;

			cout << "Brute-Force String Matching" << endl << endl;

			cout << "patern: " << P << endl;
			if (location1 != -1) {
				cout << "pattern starts after .....(" << location1 << ") th character of the text" << endl;
			}
			else {
				cout << "pattern is NOT found in the text" << endl;
			}
			cout << "basic operation executed .(" << C + D - 1 << ") times" << endl;
			cout << "execution time is ........(" << t1 << ") ms" << endl << endl;


			cout << "Horspool's String Matching" << endl << endl;

			cout << "patern: " << P << endl;
			if (location1 != -1) {
				cout << "pattern starts after .....(" << location2 << ") th character of the text" << endl;
			}
			else {
				cout << "pattern is NOT found in the text" << endl;
			}
			cout << "basic operation executed .(" << E + F - 1 << ") times" << endl;
			cout << "execution time is ........(" << t2 << ") ms" << endl << endl;



			system("pause");

		}









		if (menu_selection == 4) {
			
		
				system("cls");
				cout << "working..." << endl;
			
		

			int L, sum1 = 0, sum2 = 0, avg1, avg2;

			start = clock();
			for (int i = 0; i < 100; i++) {
				L = (rand() % 5) + 3;
				P = randomstringgenerator(L);

				location1 = bruteforcestringmatch(T, P);
				location2 = horspoolstringmatching(T, P);

				sum1 = sum1 + C + D - 1;
				sum2 = sum2 + E + F - 1;
			}
			stop = clock();
			t3 = (double)(stop - start) / CLOCKS_PER_SEC * 1000.0;

			avg1 = sum1 / 100;
			avg2 = sum2 / 100;


			system("cls");

			cout << "Brute-Force String Matching" << endl;
			cout << "basic operation executed in average (" << avg1 << ") times" << endl << endl;

			cout << "Horspool's String Matching" << endl;
			cout << "basic operation executed in average (" << avg2 << ") times" << endl << endl;

			cout << "total execution time is ............(" << t3 << ") ms" << endl << endl;
			system("pause");
		}
		







		if (menu_selection == 0) {
			menu_loop = 0;
		}


	}


}

