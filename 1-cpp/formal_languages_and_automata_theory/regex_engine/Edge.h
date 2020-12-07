#pragma once

#include <iostream>

using namespace std;

class Edge {

public:
	Edge(int source, int destination) {
		this->sourceState = source;
		this->destinationState = destination;
		this->symbol = EPSILON;
	}

	Edge(int source, int destination, char symbol) {
		this->sourceState = source;
		this->destinationState = destination;
		this->symbol = symbol;
	}

	Edge epsilonTransition(int sourceState, int destinationState) {
		return Edge(sourceState, destinationState, EPSILON);
	}

    void print() {
		cout << '(' << sourceState << ", " << destinationState << ", ";
		if (isEpsilonTransition()) {
			cout << "epsilon";
		}
		else {
			cout << "'" << symbol << "'";
		}
		cout << ')' << endl;
	}

    inline int getSourceState() { return sourceState; }
    inline int getDestinationState() { return destinationState; }
    inline char getSymbol() { return symbol; }

    inline bool isEpsilonTransition() { return symbol == EPSILON; }
    
private:
    int sourceState;
    int destinationState;
    char symbol;

    //instead of epsilon we have $, because epsilon is not in ascii table...
    static const char EPSILON = '$';
    
};