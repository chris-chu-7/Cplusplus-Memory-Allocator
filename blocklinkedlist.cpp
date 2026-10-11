#include "blocklinkedlist.h"

LinkedList::LinkedList(Header* front, size_t size){
    //The constructor for a new linked list 
    head = *front; // front is the contents of it   
    front -> size = size;
    front -> next = NULL;
    front -> start_address = 0x00;
}

void LinkedList::insert(Header* node, uint8_t start_address, size_t size){



}

void LinkedList::remove(uint8_t index){


}

void LinkedList::coalesce() {


}

void LinkedList::printList(){



}
