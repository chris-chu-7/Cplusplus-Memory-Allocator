#include <iostream>
#include "heapallocator.h"
#include "blocklinkedlist.h"
 


int main() {
    //initialize heap allocator
    HA::heapallocator heap;
    heap.my_malloc(200);
    heap.my_malloc(1000);
    heap.my_malloc(2000); 
    heap.my_free(1032);
    heap.my_free(200);  
     

}