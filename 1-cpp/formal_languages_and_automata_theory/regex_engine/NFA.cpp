

#include <stdlib.h>
#include <iostream>
#include <string>
#include <stack>
#include <windows.h>

#include "NFA.h"
using namespace std;



int NFA::stateIDsource = 0;

NFA::NFA() {
}

NFA::NFA(int initialState, vector<int> allStates, vector<int> acceptStates, vector<Edge> transitions) {
	this->initialState = initialState;
	this->allStates = allStates;
	this->acceptStates = acceptStates;
	this->transitions = transitions;
}

void NFA::print() {

	cout << "Start State : ";
	cout << this->initialState <<endl;
	cout << "Accepts States : ";
	printVector(acceptStates);
	cout << "All States : ";
	printVector(allStates);
	cout << "Edges : " << endl;
	for (int i = 0; i<transitions.size(); ++i) {
		transitions[i].print();
	}
	cout <<endl<< "NFA simulation results : " << endl<< endl;
}

bool NFA::accepts(string str) {

	int i = 0;

	vector<int> S;
	vector<int> T;
	S.push_back(this->initialState);

	while (!(i==str.length()))
	{
		for (int s_index = 0; s_index<S.size(); s_index++)
		{
			
			//cout << s_index <<endl;

			for (int transitions_index = 0; transitions_index<this->transitions.size(); transitions_index++)
			{
				if (this->transitions[transitions_index].getSourceState() == S[s_index])
					if (this->transitions[transitions_index].isEpsilonTransition())
					{
						S.push_back(this->transitions[transitions_index].getDestinationState());
					}
			}
		}



		T.clear();
		for (int s_index = 0; s_index < S.size(); s_index++)
		{
			for (int transitions_index = 0; transitions_index<this->transitions.size(); transitions_index++)
			{
				if (this->transitions[transitions_index].getSourceState() == S[s_index])
					if (this->transitions[transitions_index].getSymbol()==str[i])
					{
						T.push_back(this->transitions[transitions_index].getDestinationState());
					}
			}
		}
		
		S.clear();
		S = T;

		i++;
		//cout << "ben " << i << endl;
	}
	


	/*cout << "S nin içi" << endl;
	for (int i : S)
	{
		cout << i << endl;
	}*/

	/*cout << "REAL ACCEPT STATE nin içi" << endl;
	for (int j: this->acceptStates)
	{
		cout << j << endl;
	}
	*/

	for (int i : S)
	{
		for (int j : this->acceptStates)
		{
			if (j == i)
				return true;
		}
	}

	
	return false;
	
}



NFA NFA::singleSymbol(char c) {
	//implemented for you: singleSymbol

	int initialState = NFA::newState();
	int finalState = NFA::newState();
	
	//we have just two states here
	vector<int> allStates;
	allStates.push_back(initialState);
	allStates.push_back(finalState);

	//there is a single accept state,
	vector<int> acceptStates;
	acceptStates.push_back(finalState);

	//there is a single transition in this automaton, which takes initial state
	//to final state if input is given as the same as 'symbol' variable.
	Edge onlyOneTransition(initialState, finalState, c);
	vector<Edge> transitions;
	transitions.push_back(onlyOneTransition);

	//create an NFA with such properties.
	return NFA(initialState, allStates, acceptStates, transitions);
}

NFA NFA::unionOfNFAs(NFA& nfa1, NFA& nfa2) {

	int initialState = NFA::newState();

	Edge Right(initialState,nfa1.initialState);
	Edge Left(initialState,nfa2.initialState);

	vector<int> allStates;
	allStates.insert(allStates.end(), nfa1.allStates.begin(), nfa1.allStates.end());
	allStates.insert(allStates.end(), nfa2.allStates.begin(), nfa2.allStates.end());
	allStates.push_back(initialState);

	vector<int> acceptStates;
	acceptStates.insert(acceptStates.end(), nfa1.acceptStates.begin(), nfa1.acceptStates.end());
	acceptStates.insert(acceptStates.end(), nfa2.acceptStates.begin(), nfa2.acceptStates.end());


	vector<Edge> transitions;
	transitions.insert(transitions.end(), nfa1.transitions.begin(), nfa1.transitions.end());
	transitions.insert(transitions.end(), nfa2.transitions.begin(), nfa2.transitions.end());
	transitions.push_back(Right);
	transitions.push_back(Left);


	return NFA(initialState, allStates, acceptStates, transitions);
}

NFA NFA::concatenate(NFA& nfa1, NFA& nfa2) {

	vector<int> allStates;
	allStates.insert(allStates.end(), nfa1.allStates.begin(), nfa1.allStates.end());
	allStates.insert(allStates.end(), nfa2.allStates.begin(), nfa2.allStates.end());

	vector<int> acceptStates;
	acceptStates.insert(acceptStates.end(), nfa2.acceptStates.begin(), nfa2.acceptStates.end());

	vector<Edge> transitions;
	transitions.insert(transitions.end(), nfa1.transitions.begin(), nfa1.transitions.end());
	transitions.insert(transitions.end(), nfa2.transitions.begin(), nfa2.transitions.end());

	for (int i=0; i<nfa1.acceptStates.size();i++)
	{
		Edge connections(nfa1.acceptStates[i], nfa2.initialState);
		transitions.push_back(connections);
	}

	return NFA(nfa1.initialState, allStates, acceptStates, transitions);

}

NFA NFA::star(NFA& nfa) {

	vector<int> allStates;
	allStates.insert(allStates.end(), nfa.allStates.begin(), nfa.allStates.end());

	vector<int> acceptStates;
	acceptStates.insert(acceptStates.end(), nfa.acceptStates.begin(), nfa.acceptStates.end());

	vector<Edge> transitions;
	transitions.insert(transitions.end(), nfa.transitions.begin(), nfa.transitions.end());

	for (int i = 0; i<nfa.acceptStates.size(); i++)
	{
		Edge connections(nfa.acceptStates[i], nfa.initialState);
		transitions.push_back(connections);
	}

	int initialState = NFA::newState();

	Edge connection(initialState, nfa.initialState);
	transitions.push_back(connection);
	allStates.push_back(initialState);
	acceptStates.push_back(initialState);

	return NFA(initialState,allStates,acceptStates,transitions);
}

void printVector(const vector<int>& a) {
	cout << '[';
	for (int i = 0; i<a.size() - 1; ++i) {
		cout << a[i] << ", ";
	}
	cout << a.back() << ']' << endl;
}


stack <NFA> MyStack;
NFA RegularMachine(string Postfix)
{

	
	
	//cout << "ARRAY'in içi... " << endl;
	int i = 0;

	while (!(i== Postfix.length()))
	{
		if (Postfix[i] == '*')
		{ 
			NFA Star = NFA::star(MyStack.top());
			MyStack.pop();
			MyStack.push(Star);
		}
		else if (Postfix[i] == '|')
		{
			NFA first= MyStack.top();
			MyStack.pop();
			NFA second= MyStack.top();
			MyStack.pop();
			NFA Union = NFA::unionOfNFAs(first,second);
			MyStack.push(Union);
		}
		else if (Postfix[i] == '&')
		{
			NFA first = MyStack.top();
			MyStack.pop();
			NFA second = MyStack.top();
			MyStack.pop();
			NFA con = NFA::concatenate(second ,first); //burda neden second first çünkü ilk kurulan en atta ya stackte iþte o second ve concanateion da ilk kurulan 2. kurulana eklenmesi gerek o yüzden...
			MyStack.push(con);
		}
		else
		{
			NFA Symbol = NFA::singleSymbol(Postfix[i]);
			MyStack.push(Symbol);
		}
		
		//cout << "ARRAY'in içi... " << endl;
		i ++ ;
	}

	
	return MyStack.top();
}


int screen = 0;
int lineNumber = 0;
void TestReadFile(string RE, string Postfix,string Text) {
	NFA RegularMachineResult = RegularMachine(Postfix);
	lineNumber++;

	if (screen == 0)
	{
		cout << "Following NFA was built :" << endl;
		cout << "-------------------------" << endl<< endl;
		RegularMachineResult.print();
		screen = 1;
	}

	
	bool accept = false;
	int TextCounter=0;
	while (TextCounter < Text.size())
	{

		int start = TextCounter;
		int stop = 1;
		for (int i = 0; i <= TextCounter; i++)
		{   
			//cout << Text.substr(start, stop) << endl;

			string SubText = Text.substr(start, stop);
			if (RegularMachineResult.accepts(SubText)) {
				accept = true;
			}

			
			start--;
			stop++;
		}
			
		TextCounter++;
	}

	if (accept == true)
	{
		cout << "ACCEPTED LINE ("<< lineNumber <<") " << Text<<endl;
	}

}


int TextColorStart[99];
int TextColorLength[99];

bool flag = false;
void TestSimultaneous(string RE, string Postfix, string Text)
{
	
	system("CLS");

	NFA RegularMachineResult = RegularMachine(Postfix);

	bool accept = false;
	int TextCounter = 0;
	while (TextCounter < Text.size())
	{

		int start = TextCounter;
		int stop = 1;
		for (int i = 0; i <= TextCounter; i++)
		{
			//cout << Text.substr(start, stop) << endl;

			string SubText = Text.substr(start, stop);
			if (RegularMachineResult.accepts(SubText)) {
				accept = true;
			}


			start--;
			stop++;
		}

		if (accept == true)
		{
			accept = false;
			TextColorStart[TextCounter] = 1;
		}

		TextCounter++;
	}

	

	cout << "RENKLERLÝ OLMASI GEREKEN " << endl;
	for (int i : TextColorStart)
	{
		cout<<"Start: "<< i <<endl;
	}



	cout << "Regular Expression : " << RE << endl;

	for (int i = 0; i < Text.length(); i++)
	{
		cout << Text[i];
		
	}


	//cout << "Text : " << Text;

}