#include <iostream>
#include "heapallocator.h"
#include "blocklinkedlist.h"
 


int main() {
    //initialize heap allocator
    HA::heapallocator heap;
    heap.my_malloc(200); 
     

}