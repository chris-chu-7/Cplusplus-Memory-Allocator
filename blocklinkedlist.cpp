#include "blocklinkedlist.h"

LinkedList::LinkedList(Header* front, size_t size){
    //The constructor for a new linked list 
    head = front; // front is the contents of it   
    front -> size = size;
    front -> next = NULL;
    front -> start_address = 0x00;
    front -> is_free = true; 
}

void LinkedList::insert(Header* node){
    //inserting a new element in the linked list  

    //pretend list is empty for safety check 
    if(head == nullptr) {
        head = node; 
        return; 
    }
    uint8_t address = node -> start_address; 

    //initialize a pointer to traverse the list starting from the head 
    Header* curr = head; 
    Header* prev = head;

    while( curr != nullptr && address > curr -> start_address) {
        prev = curr;
        curr = curr -> next; 
    }

    if (curr == head) {
        node->next = head;
        head = node; 
    } else {
        //Now we insert the node on the index before the current node 
        node -> next = curr;
        prev -> next = node; 

    }


}

void LinkedList::remove(uint8_t index){


}

void LinkedList::coalesce() {


}

void LinkedList::printList(){



}
