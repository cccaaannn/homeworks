#pragma once

#include<iostream>
#include<string>

using namespace std;

struct HashNode {

	int counter;
	int key;
	string value;
	HashNode*next;
	HashNode(int key, string value)
	{
		this->key = key;
		this->counter = 1;
		this->value = value;
		this->next = NULL;
	}
};
class hashT {
public:
	int TABLE_SIZE = 500;
	hashT();
	int HashFunc(string value)
	{
		int sum = 0;
		for (int i = 0; i < value.size(); i++)
		{
			sum = sum + value[i];
		}
		return sum % TABLE_SIZE;
	}

	void insert(string value);

	void print() const;

	void topten() const;
private:
	HashNode** htable;

};
