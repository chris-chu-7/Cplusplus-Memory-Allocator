#include "blocklinkedlist.h"
#include <iostream>
#include <cstdint>

class heapAllocator {
    public: 
        void test_Linked_List_Methods() {
            Header *front  = new Header();
            size_t initial_size = 256; 
            uint8_t start_address = 0xAB; 
            bool list_is_free = 0;
            LinkedList my_list(front, initial_size, start_address, list_is_free);
            
            Header *second = new Header();
            size_t second_size = 128; 
            uint8_t secondaddress = 0xFF; 
            second -> start_address = secondaddress;
            
            std::cout<< "Printing Second Address \n\n" << second -> start_address;

            second -> is_free = 1;

            my_list.printList();

            my_list.insert(second);

            my_list.printList();
        }
};


int main(){
    heapAllocator ha = heapAllocator();
    ha.test_Linked_List_Methods(); 
    return 0; 
}