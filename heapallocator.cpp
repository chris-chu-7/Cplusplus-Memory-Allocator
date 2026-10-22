#include "blocklinkedlist.h"
#include "heapallocator.h"
#include <iostream>
#include <cstdint>



LinkedList buffer_list;


void HA::heapallocator::init_free_block() {
    Header *front  = new Header();
    size_t front_size = 4096; 
    uint16_t front_start_address = 0x00; 
    bool front_list_is_free = 1; 
    LinkedList buffer_list(front, front_size, front_start_address, front_list_is_free);

}

void HA::heapallocator::my_malloc(size_t size) {
    std::cout << "Allocating " << size << "bytes from buffer array...";
    unsigned long header_size = sizeof(Header);
    

    //allocation logic

    //Implement first fit allocation -> find the first node in the linked list with a free size



}

void HA::heapallocator::my_free(void* ptr) {
    std::cout << "Freeing memory block ... \n";
    //free logic 
}