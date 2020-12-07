#include <iostream>

#include "list.h"

int main() {
    
    list l;

    try{

        l.append(2);
        l.append(3);
        l.append(4);
        l.append(5);

        l.printList();

        std::cout << std::endl;

        l.push(1);
        l.push(0);

        l.printList();

        std::cout << std::endl;

        int element0 = l.get(0);
        int element1 = l.get(1);
        int element2 = l.get(2);

        std::cout << element0 << " " << element1 << " " << element2 << std::endl;

        // List index out of range error
        // int element = l.get(-1);

        l.set(0, 10);
        l.set(1, 11);
        l.set(2, 12);
        
        l.printList();
        std::cout << std::endl << std::endl;

        std::cout << "reverse print" << std::endl;
        l.printListReverse(-1);
        std::cout << std::endl;

        l.clear();

        l.printList();

    }
    catch(std::string e){
        std::cout << e << std::endl;
    }
    catch(...)  { 
        std::cout << "Default Exception" << std::endl; 
    } 
    
    

 
    system("pause");
    return 0;
}