#include <cstdint>
#include <vector>

namespace HA
{

    typedef std::vector<std::uint8_t> heap_region; 

    class heapallocator {
        public: 
            
            void my_malloc(size_t size); 
            void my_free(void* ptr);
    };



}