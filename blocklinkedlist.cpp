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
    //index represents the address
    Header* curr = head; 
    Header* prev = head; 
    Header* to_delete = head; //performing memory management 
    
    while(curr -> start_address != index && curr -> next != nullptr){
        prev = curr; 
        curr = curr -> next;
    }

    //edge case 1: remove head node
    if (curr == head) {
        to_delete = curr;
        curr = curr -> next;
        head = curr; 
        delete to_delete; 
        return;
    }

    //edge case 2: remove last node
    if(curr -> next == nullptr) {
        to_delete = curr;
        curr = prev; 
        delete to_delete; 
        curr -> next = nullptr;
        return; 
    }

    //edge case 3: not found 
    if(curr -> start_address != index) {
        return;
    } else {
    //standard case: remove node in the middle of the linked list. 
        to_delete = curr;
        prev -> next = prev -> next -> next; 
        delete to_delete; 
        curr = prev -> next; 
    }

}

void LinkedList::coalesce() {


}

void LinkedList::printList(){



}
