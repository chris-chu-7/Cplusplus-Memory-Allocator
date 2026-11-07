#include "blocklinkedlist.h"
#include "heapallocator.h"
#include <iostream>
#include <cstdint>




//constructor that initializes the block 
namespace HA{
    Header *front  = new Header();
    size_t front_size = 4096; 
    uint16_t front_start_address = 0x00; 
    bool front_list_is_free = 1; 
    LinkedList *buffer_list = new LinkedList(front, front_size, front_start_address,  front_list_is_free);
}

void HA::heapallocator::my_malloc(size_t size) {
    buffer_list -> printList();
    std::cout << "Allocating " << std::dec << size << " bytes from buffer array... \n";
    unsigned long header_size = sizeof(Header);

    //allocation logic
    //Implement first fit allocation -> find the first node in the linked list with a free size
    uint16_t first_fit_index = buffer_list -> findFirstFit(size);
    std :: cout << "First fit index " << static_cast<std::int16_t>(first_fit_index) << "\n\n\n";
    //element to insert
    Header *node = new Header(); 
    node -> is_free = false;
    node -> size = size + sizeof(Header);
    node -> start_address = first_fit_index;

    std :: cout << "Start Address " << static_cast<std::int16_t>(node -> start_address) << "\n\n\n";

    buffer_list -> insert(node);


    std::cout << "Block of size " << size << " successfully allocated. \n";
    buffer_list -> printList();

}

void HA::heapallocator::my_free(uint16_t ptr) {
    std::cout << "Attempting to Free memory block ... \n";
    //free logic 

    if(buffer_list -> doesBlockExist(ptr)) {

        Header *node = buffer_list -> head;
        while(node -> start_address < ptr) {
            node = node -> next;
        }
        //no extra check needed since the block existed already
        node -> is_free = true;

        //merge the free blocks together/coalescing 
        buffer_list -> mergeBlocks();
        std::cout << "Memory block with address" <<std::hex << static_cast<int> (ptr) << "Successfully freed. \n";

    } else {
        std::cout << "Not able to free memory. Exiting method now.  \n";

    }
    
    buffer_list -> printList();


}