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
            third -> is_free = 1;

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

            std::cout << "Test 4: Testing Block Merging" << std::endl;
            Header *fourth = new Header();
            size_t fourth_size = 128; 
            uint8_t fourthaddress = 0xEE; 
            fourth -> size = fourth_size;
            fourth -> start_address = fourthaddress;
            fourth -> is_free = 1;

            Header *fifth = new Header();
            size_t fifth_size = 128; 
            uint8_t fifthaddress = 0xBC; 
            fifth -> size = fifth_size;
            fifth -> start_address = fifthaddress;
            fifth -> is_free = 1;

            my_list.insert(fourth);
            my_list.insert(fifth);

            std::cout << "Before Block Merging" << std::endl;
            my_list.printList();
            my_list.mergeBlocks();
            std::cout << "After Block Merging" << std::endl;
            my_list.printList();

        }
};


int main(){
    heapAllocator ha = heapAllocator();
    ha.test_Linked_List_Methods(); 
    return 0; 
}