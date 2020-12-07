#include "list.h"

// #include <exception>


list::list() {
    len = 0;
    start = NULL;
}

list::~list() {
    clear();
}


void list::clear(){
    if (start != NULL) {
        node* cursor = start;
        node* deleter = start;
        start = NULL;

        while (cursor->next != NULL) {
            cursor = cursor->next;
            deleter = NULL;
            deleter = cursor;
        }
        len = 0;
        cursor = NULL;
    }
}


void list::append(int newValue) {
    //node newNode;

    node* newNode = new node;

    newNode->value = newValue;
    newNode->next = NULL;


    if (start == NULL) {
        start = newNode;
        len = 1;
    }
    else {
        node* cursor = start;
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = newNode;
        len++;
        cursor = NULL;
    }
}

void list::push(int newValue) {
    node* newNode = new node;
    
    newNode->value = newValue;
    newNode->next = start;

    start = newNode;

    len++;
}




void list::add2(int newValue) {
    //node newNode;

    node newNode;

    newNode.value = newValue;
    newNode.next = NULL;


    if (start == NULL) {
        start = &newNode;
        len = 1;
    }
    else {
        node* cursor = start;
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = &newNode;
        len++;
        cursor = NULL;
    }
}


void list::printList() {

    node* cursor = start;
    if (cursor == NULL) {
        std::cout << "Empty list" << std::endl;
    }
    else {
        while (cursor != NULL) {
            std::cout << cursor->value << " ";
            cursor = cursor->next;
        }
    }
    cursor = NULL;
}



void list::printListReverse(int index) {


    // if -1 is given print all list
    if(index == -1 ){
        index = len - 1;
    }


    if (start == NULL) {
        std::cout << "Empty list" << std::endl;
    }

    else if(index >= len || index < 0){
        throw std::string("List index out of range");
    }

    else {
        if(index == 0){
            std::cout << start->value << std::endl;
        }
        else{
            node* cursor = start;
            for(int i = 0; i < index; i++){
                cursor = cursor->next;
            }
            std::cout << cursor->value << " ";

            printListReverse(index - 1);
        }
    }

}



int list::getLen() {
    return len;
}



int list::get(int index) {

    if(index >= len || index < 0){
        throw std::string("List index out of range");
    }

    else{
        if(start == NULL) {
            throw std::string("Empty list");
            }
        else if(index == 0){
            return start->value;
            }
        else {
            node* cursor = start;
            for (int i = 0; i < index; i++){
                cursor = cursor->next;
            }
            return cursor->value;
            }
        }

}


void list::set(int index, int value) {

    if(index >= len || index < 0){
        throw std::string("List index out of range");
    }
    else{
        if(start == NULL) {
            throw std::string("Empty list");
            }
        else if(index == 0){
            
            start->value = value;
            }
        else{
            node* cursor = start;
            for (int i = 0; i < index; i++){
                cursor = cursor->next;
            }
            cursor->value = value;
            }
        }

}




