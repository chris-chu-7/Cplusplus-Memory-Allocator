#include <cstdint>
#pragma once //ensure that every time a cpp file is compiled .h file copy pasted only once 
#include <string>
#include <vector>

struct Header{
    //32 bytes
    //8 bytes of size, 8 bytes of start address, 8byte pointer
    //8 byte boolean we have the paddings here. we have 7 bytes pad for is_free
    // And 6 bytes (8 bytes - 2 bytes for 16 bit) padding for start_address
    size_t size;
    bool is_free;
    Header *next;
    uint16_t start_address;
};

class LinkedList {
    public: 
        Header *head;
        LinkedList(Header* front, size_t size, uint16_t start_address, bool is_free); 
        void insert(Header* node); 
        void remove(uint16_t index);
        void mergeBlocks();
        void printList(); 
        uint16_t LinkedList::findFirstFit(int list_size);


};