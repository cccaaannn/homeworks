#pragma once
#include <iostream>
#include <string>
using namespace std;


string regex;
char c;
int cc;
string postfix;

void E(); //prototype for E
void T(); //prototype for T
void F(); //prototype for F
void G(); //prototype for G


void E() {
	T();
	while (c == '|') {
		c = regex[cc++];
		T();
		postfix += "|";
	}
}

void T() {
	F();
	while (c != '\0' && strchr(")|*+?", c) == NULL) { /* '(' or LITERAL */
		F();
		postfix += "&";
	}
}

void F() {
	G();
	while (c != '\0' && strchr("*+?", c) != NULL) {
		postfix += c;
		c = regex[cc++];
	}
}

void G() {
	if (c == '\0')
		cout << ("unexpected end of expression!");
	if (c == '\\') { /* escape */
		c = regex[cc++];
		if (c == '\0')
			cout << ("escape at end of string");
		postfix += c;
		c = regex[cc++];
	}
	else if (strchr("()|*+?", c) == NULL) { /* non-meta chacter */
		if (c == '&')
			postfix += "&";
		else
			postfix += c;
		c = regex[cc++];
	}
	else if (c == '(') {
		c = regex[cc++];
		E();
		if (c != ')')
			cout << ("Parantez eksik knk ona bir el at sana zahme"); //mismatched parantheses
		c = regex[cc++];
	}
	else
		cout << ("Saçma sapan bir Regular expression yazmýþsýn knk...");//bogus expression! 
}



void ConvertInfixToPostfix(string infix)
{
	cc = 0;
	regex = infix + '\0';
	c = regex[cc++];
	E();
	cout << endl << "Regex in Postfix form : " << postfix << endl<< endl;
}










