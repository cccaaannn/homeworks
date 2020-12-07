#include"hashT.h"
int index_finder_for_push(int number, int b[], int b_size) {
	int yer = -1;
	for (int i = 0; i < b_size; i++) {
		if (b[i] < number) {
			yer = i;
			break;
		}
	}
	return yer;
}
void push_array(int b[], int push_index, int size) {
	for (int i = size - 1; i > push_index; i--) {
		b[i] = b[i - 1];
	}
}
void push_array2(string c[], int push_index, int size) {
	for (int i = size - 1; i > push_index; i--) {
		c[i] = c[i - 1];
	}
}
hashT::hashT() {

	htable = new HashNode*[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
		htable[i] = NULL;
}

void hashT::insert(string value) {
	
		if (value != "") {
			int flag = 0;
			int hash_val = HashFunc(value);
			HashNode* prev = NULL;
			HashNode* newNode = htable[hash_val];
			while (newNode != NULL)
			{
				if (newNode->value.compare(value) == 0) {
					newNode->counter++;
					flag = 1;
					break;
				}
				prev = newNode;
				newNode = newNode->next;
			}

			if (newNode == NULL && flag == 0) {
				newNode = new HashNode(hash_val, value);
				if (prev == NULL)
				{
					htable[hash_val] = newNode;
				}
				else
				{
					prev->next = newNode;
				}
			}
			else if (newNode != NULL && flag == 0)
			{
				newNode->value = value;
			}
		}
	
	
}

void hashT::print()const {

	for (int i = 0; i < TABLE_SIZE; i++) {

		HashNode* entry = htable[i];

		if (entry != NULL)
		{
			cout << entry->key << ":";

			while (entry != NULL)
			{
				cout << entry->value << "-" << entry->counter << "-->";

				entry = entry->next;


			}
			cout << endl;
		}

	}

}

void hashT::topten() const {
	int b[10] = { 0,0,0,0,0,0,0,0,0,0 };
	string c[10] = { "+", "+", "+", "+","+","+","+","+","+" ,"+" };
	int obaley = 0;

	for (int i = 0; i < TABLE_SIZE; i++) {

		HashNode* entry = htable[i];

		if (entry != NULL) {

			while (entry != NULL) {
				int x = entry->counter;
				string y = entry->value;
				obaley = index_finder_for_push(x, b, 10);
				if (obaley != -1) {
					push_array(b, obaley, 10);
					b[obaley] = x;
					push_array2(c, obaley, 10);
					c[obaley] = y;
				}

				entry = entry->next;

			}

		}

	}

	for (int i = 0; i < 10; i++) {
		cout << b[i] << "**" << c[i] << endl;
	}

}