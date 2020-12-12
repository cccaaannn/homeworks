#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Arraylist {
	int size;
	int *p;
};


struct Arraylist Create_Arraylist();
struct Arraylist Delete_Arraylist(struct Arraylist list);
struct Arraylist clear(struct Arraylist list);
int sum(struct Arraylist list);
struct Arraylist BubbleSort(struct Arraylist list);
struct Arraylist fillWithrandom(struct Arraylist list, int size, int limit);
void PrintArraylist(struct Arraylist list);
void PrintArraylistSepBy(struct Arraylist list, char sep);
int size(struct Arraylist list);
struct Arraylist push(struct Arraylist list, int value);
struct Arraylist insert(struct Arraylist list, int index, int value);
int valueAt(struct Arraylist list, int index);
struct Arraylist pop(struct Arraylist list);
struct Arraylist deleteAllByvalue(struct Arraylist list, int value);
struct Arraylist deleteByvalue(struct Arraylist list, int value);
struct Arraylist deleteByindex(struct Arraylist list, int index);
struct Arraylist replaceAllByvalue(struct Arraylist list, int value, int newvalue);
struct Arraylist replaceByvalue(struct Arraylist list, int value, int newvalue);
struct Arraylist replaceByindex(struct Arraylist list, int index, int value);




int main() {

	struct Arraylist a;
	a = Create_Arraylist();
	
	
	printf("Ortalama bulmak icin deger girin\ntamamlamak icin -1 girin");
	
	while (1) {
		int ekle = 0;
		printf("\n:");
		scanf_s("%d", &ekle);

		if (ekle == -1) {
			break;
		}

		a = push(a, ekle);
	}

	system("cls");

	printf("array\n");

	PrintArraylistSepBy(a, '-');

	a = BubbleSort(a);

	printf("sorted array\n");

	PrintArraylistSepBy(a, '-');

	printf("AVG: %f\n",(float)sum(a)/size(a));
	
	/*
	a = fillWithrandom(a, 10, 100);

	a = insert(a, 9, 1000);
	a = insert(a, 9, 1000);
	a = insert(a, 9, 1000);
	a = insert(a, 9, 1000);
	a = insert(a, 9, 1000);
	a = insert(a, 9, 1000);
	a = insert(a, 9, 1000);
	a = insert(a, 9, 1000);
	a = insert(a, 9, 1000);
	a = insert(a, 9, 1000);

	a = replaceAllByvalue(a, 1000, 999);

	PrintArraylistSepBy(a, '-');
	*/
	a = Delete_Arraylist(a);
}





struct Arraylist Create_Arraylist() {
	struct Arraylist list = { 0,malloc(list.size * sizeof(int)) };
	return list;
}


struct Arraylist Delete_Arraylist(struct Arraylist list) {
	list.size = 0;
	free(list.p);
	return list;
}


struct Arraylist clear(struct Arraylist list) {
	list.size = 0;
	list.p = realloc(list.p, list.size * sizeof(int));
	return list;
}


int sum(struct Arraylist list) {
	if (list.size == 0) {
		return -1;
	}
	else {
		int a = 0;
		for (int i = 0; i < list.size; i++) {
			a += *(list.p + i);
		}
		return a;
	}
}


struct Arraylist BubbleSort(struct Arraylist list) {
	int i, j, temp;
	for (i = 0; i < (list.size - 1); ++i){
		for (j = 0; j < list.size - 1 - i; ++j){
			if (valueAt(list,j) > valueAt(list,j + 1)){
				temp = valueAt(list,j + 1);
				list = replaceByindex(list, j + 1,valueAt(list, j));
				list = replaceByindex(list, j, temp);
			}
		}
	}
	return list;
}


struct Arraylist fillWithrandom(struct Arraylist list, int size, int limit) {
	static int k = 0;
	for (int i = 0; i < size; i++){
		srand(k + time(NULL));
		list = push(list, rand() % limit);
		k++;
	}
	return list;
}


void PrintArraylist(struct Arraylist list) {
	if (list.size > 0) {
		for (int i = 0; i < list.size; i++) {
			printf("%d ", *(list.p + i));
		}
	}
	else {
		printf("List is empty");
	}
	printf("\n");
}


void PrintArraylistSepBy(struct Arraylist list,char sep) {
	if (list.size > 0) {
		for (int i = 0; i < list.size - 1; i++) {
			printf("%d%c", *(list.p + i), sep);
		}
		printf("%d", *(list.p + list.size - 1));
	}
	else {
		printf("List is empty");
	}
	printf("\n");
}


int size(struct Arraylist list) {
	return list.size;
}


struct Arraylist push(struct Arraylist list,int value) {
	list.size++;
	list.p = realloc(list.p, list.size * sizeof(int));
	*(list.p + list.size - 1) = value;
	return list;
}


struct Arraylist insert(struct Arraylist list,int index ,int value) {
	list.size++;
	list.p = realloc(list.p, list.size * sizeof(int));
	for (int i = list.size - 1; i > index; i--) {
		*(list.p + i) = *(list.p + i - 1);
	}
	*(list.p + index) = value;
	return list;
}


int valueAt(struct Arraylist list, int index) {
	return *(list.p + index);
}


struct Arraylist pop(struct Arraylist list) {
	list.size--;
	list.p = realloc(list.p, list.size * sizeof(int));
	return list;
}


struct Arraylist deleteAllByvalue(struct Arraylist list, int value) {
	for (int i = 0; i < list.size; i++){
		if (valueAt(list, i) == value) {
			for (int j = i; j < list.size - 1; j++){
				*(list.p + j) = *(list.p + j + 1);
			}
			list = pop(list);
			i = 0;
		}
	}
	return list;
}


struct Arraylist deleteByvalue(struct Arraylist list, int value) {
	for (int i = 0; i < list.size; i++) {
		if (valueAt(list, i) == value) {
			for (int j = i; j < list.size - 1; j++) {
				*(list.p + j) = *(list.p + j + 1);
			}
			list = pop(list);
			break;
		}
	}
	return list;
}


struct Arraylist deleteByindex(struct Arraylist list, int index) {
	for (int i = index; i < list.size - 1; i++) {
		*(list.p + i) = *(list.p + i + 1);
	}
	list = pop(list);
	return list;
}


struct Arraylist replaceAllByvalue(struct Arraylist list, int value, int newvalue) {
	for (int i = 0; i < list.size; i++) {
		if (valueAt(list, i) == value) {
			list = replaceByindex(list, i, newvalue);
			}
		}
	return list;
}


struct Arraylist replaceByvalue(struct Arraylist list, int value, int newvalue) {
	for (int i = 0; i < list.size; i++) {
		if (valueAt(list, i) == value) {
			list = replaceByindex(list, i, newvalue);
			break;
		}
	}
	return list;
}


struct Arraylist replaceByindex(struct Arraylist list, int index,int value) {
	*(list.p + index) = value;
	return list;
}