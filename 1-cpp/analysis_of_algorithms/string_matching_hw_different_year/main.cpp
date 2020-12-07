#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <time.h>
using namespace std;

string stopwords[] = { "a","the","an","and","but","by","than","in","all","of","ll","he","i","was","is","from","at","as",
"she","his","her","to","up","on","does","have","their","be","that","you","too","we","it","him","will",
"can","out","all","got","some","this","our","do","has","for","they","them","much","off","just","then","very",
"yes","yet","your","with","she","willing","wish","wished","wishing","within","without","such","as" ,"what","what time","who","m.",
"how","many","where","himself", "s","re", "i'm","doesn't", "i'd","haven't","everybody's","isn't","we're","it's","int.",
"what's","ext.","don't","wanna","you're","t","i'll","how many","shouldn't","not","if" ,"color" };

char punct[9] = { ',',';','-','(',')','!','\"','?' , ':' };

void lowerCase(string &a) {

	for (int i = 0; i <= a.size(); i++) {

		if (a[i] >= 65 && a[i] <= 90) {

			a[i] = a[i] + 32;
		}

	}
}

void removeStopword(string &a) {
	//cout << a;
	for (int i = 0; i < (sizeof(stopwords) / sizeof(*stopwords)); i++) {

		if (a == stopwords[i]) {
			a = "";
			break;
		}
	}
}

void punctuations(string &a) {
	for (int j = 0; j < a.size(); j++) {
		for (int i = 0; i < (sizeof(punct) / sizeof(*punct)); i++) {
			if (a[j] == punct[i]) {
				a[j] = ' ';
				break;
			}
		}
	}
}

string removeSpace(string a) {
	a.erase(remove_if(begin(a), end(a), isspace), end(a));
	return a;
}

vector<vector<string> > RemoveDot(vector<vector<string> > v1) {
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			for (int k = 0; k < v1[i][j].size(); k++) {
				if (v1[i][j][k] == '.') {
					v1[i][j][k] = ' ';
				

				}

			}
			v1[i][j] = removeSpace(v1[i][j]);
			removeStopword(v1[i][j]);
		}

	}
	return v1;
}

vector<vector<string> > removeVectorSpaces(vector<vector<string> > v1) {

	bool f = false;
	int q = 0;

	vector<vector<string> > v2;
	v2.push_back(vector<string>());

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			if (v1[i].size() != 0) {
				v2[q].push_back(v1[i][j]);
				f = true;
			}
		}
		if (f) {
			q++;
			v2.push_back(vector<string>());
			f = false;
		}
	}

	v2.pop_back();

	return v2;

}

bool IsEmptyVector(vector<vector<string> > v1) {
	int p = 0;
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i].size() == 0) {
			p++;
		}
	}
	if (p == v1.size()) {
		return true;
	}
	else {
		return false;
	}
}

vector<vector<string> > RemoveDuplicate(vector<vector<string> > v1) {

	for (int k = 0; k < v1.size(); k++) {
		for (int i = 0; i < v1[k].size(); i++) {
			for (int j = i + 1; j < v1[k].size() - 1; j++) {
				if (v1[k][i] == v1[k][j]) {
					//cout << v1[k][j] << " " << endl;
					v1[k].erase(v1[k].begin() + j);
				}
			}
		}
	}
	return v1;

}

int main() {
	int start = clock();
	// opening the file
	ifstream TheText;
	ifstream TheQuestions;
	TheText.open("the_truman_show_script.txt");
	TheQuestions.open("questions.txt");

	//vectors
	vector<string> all;

	vector<vector<string> > questions;
	questions.push_back(vector<string>()); //satýr ekliyor baþtaki satýr 2.sütun

	string text2;
	string word;

	if (TheQuestions.is_open()) {
		string line;
		string temp;
		int n = 0, n1 = 1;
		bool linee = false;
		bool linee2 = false;
		while (TheQuestions >> line) {

			if (line[line.size() - 1] == '?') {
				linee = true;
				linee2 = true;
			}
			
			if (linee2) {
				linee2 = false;
				cout << "Question " << n1 << endl << temp + line << endl;
				temp = "";
				n1++;
			}

			else {
				temp += line + " ";

			}

			lowerCase(line);
			punctuations(line);
			line = removeSpace(line);
			removeStopword(line);

			if (line != "") {
				questions[n].push_back(line);
			}

			if (linee) {
				linee = false;
				questions.push_back(vector<string>());
				n++;
			}

		}

		questions.pop_back();

	}

	if (TheText.is_open()) {

		int n2 = 0;
		string candidate;
		bool s = false, s2 = false;

		while (TheText >> candidate) {

			lowerCase(candidate);
			punctuations(candidate);
			candidate = removeSpace(candidate);

			removeStopword(candidate);

			all.push_back(candidate);

			text2 += candidate + " ";

		}

		TheText.close();
	}

	else
	{
		cout << "the file does not exist!" << endl;
	}

	///////questions.size() kaç soru cevapladýðýný böyle
	for (int x = 0; x < questions.size(); x++) {

		cout << endl;

		vector<vector<string> > hold;
		hold.push_back(vector<string>());
		//****************
		vector<vector<string> > cevapcümlesi;
		cevapcümlesi.push_back(vector<string>());

		word = questions[x][0];

		lowerCase(word);
		int countwords = 0;
		int n2 = 0;
		string candidate;
		bool s = false, s2 = false;

		for (int i = 0; i < all.size(); i++) {

			candidate = all[i];

			//lowerCase(candidate);
			//punctuations(candidate);
			//candidate = kahve(candidate);
			//removeStopword(candidate);

			if (word == candidate) {
				++countwords;
				s = true;
			}


			if (candidate != "") {
				hold[n2].push_back(candidate);
			}

			if ((candidate != "") && (candidate[candidate.size() - 1] == '.') && (s)) {
				s2 = true;
				s = false;
			}
			else if ((candidate != "") && (candidate[candidate.size() - 1] == '.')) {
				hold[n2].clear();
			}

			if (s2) {
				hold.push_back(vector<string>());
				n2++;
				s2 = false;
			}
		}

		hold.pop_back();          //son satýr nedense bi coþtu onu silek














		hold = RemoveDuplicate(hold);
		hold = RemoveDot(hold);
		///////////////////////
		/*
		cout << "The word '" << word << "' has been found " << countwords << " times.\n";
		for (int i = 0; i < hold.size(); i++) {
		cout << i << " - ";
		for (int j = 0; j < hold[i].size(); j++) {
		cout << hold[i][j] << "*";
		}
		cout << endl;
		}
		*/


		int l = 0;
		for (int i = 0; i < hold.size(); i++) {
			for (int j = 0; j < hold[i].size(); j++) {
				for (int k = 0; k < questions[x].size(); k++) {
					if (hold[i][j] == questions[x][k]) {
						hold[i][j].clear();
						l++;
						break;
					}
				}
			}
			//l < questions[x].size()-1
			if (l < questions[x].size()) {
				hold[i].clear();
			}
			l = 0;
		}









		//cout << endl;

		if (IsEmptyVector(hold)) {
			cout << "Answer " << x + 1 << " NOT FOUND" << endl;
		}
		else {
			cout << "Answer " << x + 1 << endl;
			cevapcümlesi = removeVectorSpaces(hold);

			for (int i = 0; i < cevapcümlesi.size(); i++) {

				for (int j = 0; j < cevapcümlesi[i].size(); j++) {
					cout << cevapcümlesi[i][j] << " ";
				}
				cout << endl;
			}
		}
	}









	int end = clock();
	cout << endl << "it took " << ((float)end - start) / CLOCKS_PER_SEC << "seconds.";
	system("PAUSE");
}