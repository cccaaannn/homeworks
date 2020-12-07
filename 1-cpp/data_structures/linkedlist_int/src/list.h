#pragma once
#include<iostream>
#include<string>

class node {
public:
    int value;
    node* next;
};


class list {

private:
    // node *nodes;
    int len;
    node* start;
public:

    //construct-destruct
    list();
    ~list();

    // add functions
    void append(int);
    void push(int);
    void add2(int);

    // get set
    int get(int);
    void set(int, int);
    int getLen();

    // print functions
    void printList();
    void printListReverse(int);

    // other utilities
    void clear();
   
};


