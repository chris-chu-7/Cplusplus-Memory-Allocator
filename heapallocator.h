#include <cstdint>
#include <vector>

namespace HA
{

    class heapallocator {
        public:

            static unsigned char buffer[4096];
            LinkedList *buffer_list;
            
            void init_free_block();
            void my_malloc(size_t size); 
            void my_free(void* ptr);
    };



}