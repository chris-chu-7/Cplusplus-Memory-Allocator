#include "blocklinkedlist.h"
#include <iostream>
#include <cstdint>

LinkedList::LinkedList(Header* front, size_t size, uint16_t start_address, bool is_free){
    //The constructor for a new linked list 
    head = front; // front is the contents of it   
    front -> size = size;
    front -> next = NULL;
    front -> start_address = start_address;
    front -> is_free = is_free; 
}

void LinkedList::insert(Header* node){
    //inserting a new element in the linked list  

    //pretend list is empty for safety check 
    if(head == nullptr) {
        head = node; 
        return; 
    }
    uint16_t address = node -> start_address; 

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

void LinkedList::remove(uint16_t index){
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
    if(curr -> start_address == index && curr -> next == nullptr) {
        to_delete = curr;
        curr = prev; 
        delete to_delete; 
        curr -> next = nullptr;
        return; 
    }

    //edge case 3: not found 
    if(curr -> start_address != index) {
        std::cout << "Block with the Address " << std::hex << static_cast<int> (index) << " not found. Exiting remove() function.";
        return;
    } else {
    //standard case: remove node in the middle of the linked list. 
        to_delete = curr;
        prev -> next = prev -> next -> next; 
        delete to_delete; 
        curr = prev -> next; 
    }

}

void LinkedList::mergeBlocks() {
    //implementing coalescing : When a block is freed, merge it with adjacent free blocks to fight fragementation. 
    //this is the skeleton function to implement coalescing. 

    std::cout << "merging blocks... \n  ";
    Header* curr = head; 
    Header* first = nullptr;
    Header* second = nullptr; 

    while (curr != nullptr && curr -> next != nullptr) {
        //maintain 2 pointers 
        first = curr; 
        second = curr -> next; 

        //check if they are consecutive free blocks if they are, merge the blocks 
        if (first -> is_free && second -> is_free) {
            first -> size = first -> size + second -> size; 
            remove(second -> start_address);
        }

        curr = curr -> next;
    } 

    std::cout << "merged. \n  ";


}

uint16_t LinkedList::findFirstFit(int list_size) {
    //Returns the index with the free element able to fit the linked list 
    std::cout << "Finding First Block that fits ... \n  ";

    Header* curr = head; 
    while(curr != nullptr) {
        // if the size is greater than padding + data size return the index 
        if((curr -> is_free == true) && (curr -> size > (sizeof(Header) + list_size))){
            return curr->start_address;
        }
        curr = curr-> next;

    }

    return -1; 
}




void LinkedList::printList(){
    //print out all the elements of the linked list 
    Header* curr = head; 

    while(curr != nullptr) {
        std::cout << " | Starting Address 0x" << std::hex << static_cast<int> (curr -> start_address) << " | ";
        std::cout  << " | Block Size: "  << std::dec << curr -> size << " | " ;
        std::cout << " | Is Free: " << std::boolalpha << curr -> is_free  << " | ";
        if (curr -> next != nullptr) {
            std::cout << " ========> ";
        }
        curr = curr -> next;
    }
    std::cout << "\n";
}



