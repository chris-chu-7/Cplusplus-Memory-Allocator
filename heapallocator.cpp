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
            second -> size = second_size;
            second -> start_address = secondaddress;
            second -> is_free = 1;


            Header *third = new Header();
            size_t third_size = 512; 
            uint8_t thirdaddress = 0xCD; 
            third -> size = third_size;
            third -> start_address = thirdaddress;
            third -> is_free = 0;

            std::cout << "Test 1: Initial List with 0xAB Address" << std::endl;
            my_list.printList();
            std::cout << "\n";


            std::cout << "Test 2: Insert Item at the end of List 0xFF" << std::endl;
            my_list.insert(second);
            my_list.printList();
            std::cout << "\n";


            std::cout << "Test 3: Insert Item in middle of the List 0xCD" << std::endl;
            my_list.insert(third);
            my_list.printList(); 
            std::cout << "\n";


            std::cout << "Test 4: Free block 1" << std::endl;
            front -> is_free = 1;
            my_list.printList(); 
            std::cout << "\n";


            std::cout << "Test 5: Remove middle block" << std::endl;
            my_list.remove(0xCD);
            my_list.printList(); 
            std::cout << "\n";

            std::cout << "Test 6: Remove invalid block without address" << std::endl;
            my_list.remove(0xBC);
            my_list.printList(); 

        }
};


int main(){
    heapAllocator ha = heapAllocator();
    ha.test_Linked_List_Methods(); 
    return 0; 
}