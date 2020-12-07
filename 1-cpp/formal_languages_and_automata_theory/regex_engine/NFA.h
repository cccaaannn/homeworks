#pragma once


#include <vector>
#include "Edge.h"


using namespace std;

static int cs = 0, cl = 0;



class NFA {
private:
	static int stateIDsource;

	NFA(int, vector<int>, vector<int>, vector<Edge>);

	int initialState;
	vector<int> allStates;
	vector<int> acceptStates;
	vector<Edge> transitions;

	vector<int> currentStates;

public:
	NFA();

	bool accepts(string);
	void print();

	//every new state must have distinct id, so increment the id generator
	//each time you need a new one.
	inline static int newState() { return stateIDsource++; }

	static NFA singleSymbol(char c);
	static NFA unionOfNFAs(NFA&, NFA&);
	static NFA concatenate(NFA&, NFA&);
	static NFA star(NFA&);

	NFA RegularMachine(string);

	

};



void printVector(const vector<int>&);

void TestReadFile(string, string, string);
void TestSimultaneous(string, string, string);
