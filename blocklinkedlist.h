#pragma once //ensure that every time a cpp file is compiled .h file copy pasted only once 
#include <string>
#include <vector>

struct Header{
    size_t size;
    bool is_free;
    Header *next;
    uint8_t start_address;
};

class LinkedList {
    public: 
        Header *head;
        LinkedList(Header* front, size_t size); 
        void insert(Header* node); 
        void remove(uint8_t index);
        void coalesce();
        void printList(); 


};