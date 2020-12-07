#include "aray.h"


//constructor
aray::aray(int size) {

	if (size <= 0) {
		cerr << "Capacity of the array must be a positive "
			<< "number. Creating an arraylist of capacity"
			<< "100" << endl;
		maxsize = 100;
	}
	else {
		maxsize = size;
	}

	length = 0;
	list = new string[maxsize];
	countt = new int[maxsize];
	assert(list != NULL);

}

//destractor
aray::~aray() {
	delete[] list;
	delete[] countt;
}

//size
int aray::listsize()const {
	return length;
}



//insert
void aray::insert(int index, string value) {
	if (index<0 || index >= maxsize) {
		cerr << "Index value for the item "
			<< "to be inserted is out of range"
			<< endl;
	}
	else {
		list[index] = value;
		countt[index] = 1;
		length++;
	}

}

//increase count of a  index
void aray::increasecountt(int index) {
	if (index<0 || index >= maxsize) {
		cerr << "Index value for the item "
			<< "to be inserted is out of range"
			<< endl;
	}
	else {
		countt[index]++;
	}
}


//replace
void aray::replace(int index, string value) {
	if (index<0 || index >= maxsize) {
		cerr << "Index value for the item "
			<< "to be inserted is out of range"
			<< endl;
	}
	else {
		list[index] = value;

	}

}

//retrieve just value
string aray::retrieve(int index)const {
	if (index<0 || index >= maxsize) {
		cerr << "Index value for the item "
			<< "to be inserted is out of range"
			<< endl;
	}
	else {
		return list[index];
	}
}


//retrieve just count
int aray::retrieve1(int index)const {
	if (index<0 || index >= maxsize) {
		cerr << "Index value for the item "
			<< "to be inserted is out of range"
			<< endl;
	}
	else {
		return countt[index];
	}
}

//retrieve value and count
void aray::retrieve2(int index, string &value, int &c)const {

	if (index<0 || index >= maxsize) {
		cerr << "Index value for the item "
			<< "to be inserted is out of range"
			<< endl;
	}
	else
	{
		value = list[index];
		c = countt[index];
	}
}


//makes count 0;
void aray::counetrrsifirlayici(int index) {

	if (index<0 || index >= maxsize) {
		cerr << "Index value for the item "
			<< "to be inserted is out of range"
			<< endl;
	}
	else
	{
		countt[index] = 0;
	}
}


//pushes the array
void aray::ittirici(int durulacakindex) {

	for (int i = length; i > durulacakindex - 1; i--) {
		list[i + 1] = list[i];
		countt[i + 1] = countt[i];
	}

	list[durulacakindex] = ' ';
	countt[durulacakindex] = 0;

}





//binaary search
int aray::binarysearch(string value)
{

	int first = 0,             // first array element
		last = length - 1,       // last array element
		middle,                // mid point of search
		position = -1;         // position of search value
	bool found = false;        // flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;     // calculate mid point
		if (list[middle] == value)      // ýf value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (list[middle] > value) { // ýf value is in lower half
			last = middle - 1;
			pozisyon = last;
		}
		else {
			first = middle + 1;           // ýf value is in upper half
			pozisyon = first;
		}
	}

	return position;

}