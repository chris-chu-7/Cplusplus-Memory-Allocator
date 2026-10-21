#include <cstdint>
#include <vector>

namespace HA
{

    class heapallocator {
        public:

            static unsigned char buffer[4096];
            
            void my_malloc(size_t size); 
            void my_free(void* ptr);
    };



}