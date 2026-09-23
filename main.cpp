using namespace std;
#include <vector>
#include <cstdint>
#include "blocklinkedlist.h"


int main() {

    //test to see if linked list works 
    std::vector<std::uint8_t> data_packet  = {0xAB, 0xCD, 0xEF, 0x27};
    BlockList *test_link_list = new BlockList;

    test_link_list->insert(data_packet); 

}