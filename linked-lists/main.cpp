#include <iostream>
#include "MyLinkedList.h"
using namespace std;

int main() {

    MyLinkedList list;
    list.addAtHead(3);
    list.addAtTail(2);
    list.addAtTail(5);
    list.addCycle(-4,2);
    cout << list.detectCycle();
//    list.addCycle(25);
//    list.addAtIndex(2,11);
//    list.deleteAtIndex(0);


//    cout << list.get(1) << endl;
//    list.printList(list.head) ;

    return 0;
}
