#pragma once
#include <cstdint>
#include <vector>
#include "blocklinkedlist.h"

namespace HA
{
    class heapallocator {
        public:

            ::LinkedList *buffer_list;

            heapallocator();
            void my_malloc(size_t size); 
            void my_free(uint16_t ptr);
    };



}