#include "blocklinkedlist.h"

LinkedList::LinkedList(Header* front, size_t size){
    head = *front; // front is the contents of it   
    front -> size = size;
    front -> next = NULL;

}

void LinkedList::insert(Header* node){



}

void LinkedList::remove(uint8_t index){


}

void LinkedList::coalesce() {


}

void LinkedList::printList(){



}
