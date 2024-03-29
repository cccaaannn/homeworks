#include "ConvertInfixToPostfix.h"
#include "NFA.h"
#include "fstream"
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;
 
clock_t start;
double duration;
void ColorText(string);

static string RE;
char menuValue;
void Menu();

int main()
{

	Menu();

	while (1)
	{
		if (menuValue == '1')
		{
			system("CLS");
			cout << "Define your Regular Expression... ";
			cout << "( Alphabet does not contain (, ), |, *, and &. )" << endl<< endl;
			cout << "Regular Expression : ";
			getline(cin, RE);// neden getline çünkü boşluk karakterini de kullanma ihtimali var. Dokümanda bunula ilgili bir uyarı olmadığı için... Cin boşluğa kadar okuma yapar sadece...
			cin >> RE;

			ConvertInfixToPostfix(RE);

			start = std::clock();
			string ReadLine;
			ifstream myFile("Text.txt");
			if (myFile.is_open())
			{
		
				while (getline(myFile, ReadLine))
				{
				
				
					//cout << ReadLine << endl;
					TestReadFile(RE, postfix, ReadLine);
			
				}
			}

			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			cout << endl << "Total Elapsed Time : " << duration << "  second" << "\n\n\n\n\n";

			break;
		}
		else if (menuValue == '2')
		{
			system("CLS");
			cout << "Define your Regular Expression... ";
			cout << "( Alphabet does not contain (, ), |, *, and &. )" << endl << endl;
			cout << "Regular Expression : ";
			getline(cin, RE);// neden getline çünkü boşluk karakterini de kullanma ihtimali var. Dokümanda bunula ilgili bir uyarı olmadığı için... Cin boşluğa kadar okuma yapar sadece...
			cin >> RE;
			ConvertInfixToPostfix(RE);

			
			system("CLS");
			cout << "Regular Expression : " << RE << endl;
			cout << "Text : ";

			//cout << "Text : ";
			string t;
			char ch;
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			while (1)
			{
				
			
				ch = _getch();
				if (ch == 8)
				{
					t = t.substr(0,t.length()-1);
					cs--;
				}
				else
					t = t + ch;
				
				TestSimultaneous(RE, postfix, t);
				//system("CLS");
				
			}

		}
		else if (menuValue == '0')
		{
			exit(0);
		}
		else
		{
			system("CLS");
			cout << "Please invalid value..." << endl << endl;
			Menu();

		}

		
 	}
	


	//TestReadFile(RE,postfix,"aaeb");
	//FetchText();

	system("PAUSE");
	return 0;
}



void Menu()
{

	cout << "(1) Read File..." << endl;
	cout << "(2) Simultaneous Check..." << endl;
	cout << "(0) Exit..." << endl;
	cin >> menuValue;

}
