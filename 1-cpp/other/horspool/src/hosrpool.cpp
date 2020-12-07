#include <iostream> 
#include <fstream> 
#include "string"
#include "ctime"

using namespace std;


int horspoolstringmatching(const string& TEXT, const string& PATTERN) {

	int E = 0;
	int F = 0;

	int table[126];

	int k = 0, flag = 0;

	int m = PATTERN.length();
	int n = TEXT.length();
	int i, j;


	for (i = 0; i < 126; i++)
		table[i] = m;
	for (j = 0; j < m - 1; j++)
		table[PATTERN[j]] = m - 1 - j;


	i = m - 1;

	while (i <= n - 1) {

		E++;

		k = 0;
		while (k <= m - 1 && PATTERN[m - 1 - k] == TEXT[i - k]) {
			k++;
		}

		F = F + k;


		if (k == m) {
			return i - m + 1;
			flag = 1;
			break;
		}


		else {
			i = i + table[TEXT[i]];
		}


	}
	if (!flag)
		return -1;


}







int main() {

	clock_t start, stop;
	double t1, t2, t3;
	string T, P;
	int pattern_location;

	ifstream the_truman_show_script;
	the_truman_show_script.open("the_truman_show_script.txt");
	while (getline(the_truman_show_script, T)) {

	}
	T.erase(0, 3);


	cout << "enter pattern" << endl;
	getline(cin, P);

	start = clock();
	pattern_location = horspoolstringmatching(T, P);
	stop = clock();
	t2 = (double)(stop - start) / CLOCKS_PER_SEC * 1000.0;


	cout << "Horspool's String Matching" << endl << endl;

	cout << "patern: " << P << endl;
	if (pattern_location != -1) {
		cout << "pattern starts after .....(" << pattern_location << ") th character of the text" << endl;
	}
	else {
		cout << "pattern is NOT found in the text" << endl;
	}


	cout << "execution time is ........(" << t2 << ") ms" << endl << endl;


	system("pause");
	return 0;
}


