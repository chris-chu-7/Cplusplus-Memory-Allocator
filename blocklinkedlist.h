//Block Linked List Data Structure Code 
//Definition lives in the header 

#pragma once //make sure the file is only compiled once in here 
#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Block{
    public: 
        int start_index; 
        int block_size; //amount of data in the block 
        bool is_occupied; //see if the block is freed or not
        Block *next; //next block we point to giving next address
        //block contents  
        std::vector<std::uint8_t> data;
};

//Specialized form of a linked list data structure 
class BlockList{
    public:
        Block *head; 
        Block *tail; 
        Block *temp; 

        bool isEmpty() {
            return head == NULL; 
        }

        bool insert(std::vector<std::uint8_t> &byteArray, int index, int heapsize){ //insert at the end of teh array 
            //NOTE that the location is not the location in the linked list
            //it is the location in the giant heap table.  
            //first fit allocation
            //initialize the node


            temp = new Block; 
            temp -> block_size = byteArray.size(); 
            temp -> is_occupied = true; 
            temp -> data = byteArray; 
            //data of the node 
            Block* curr = head;
            Block* prev = NULL; 
 
            if (isEmpty() ){
                temp->next = NULL; 
                head = temp; 
                tail = temp; 
            } else if (index == 0) {
                temp -> next = head; 
                head = temp; 
            }
            
            else {
                //implementing first fit allocation
                

                for(int i = 0; i <= index; i++) {
                    if(i == index){
                        if(curr -> next == NULL){
                            curr -> next = temp; 
                            tail = temp; 
                        } else {
                            prev -> next = temp; 
                            temp -> next = curr;
                        }

                    } else if ((i < index) && (curr -> next == NULL)){
                        return false; 
                    } else {
                        prev = curr; 
                        curr = curr -> next;
                    }
                }

            }

            return false;

        }    

        void remove(int starting_index){
            //since the linked list is NOT in sequential order and
            //is simulating a heap, we have to put it in randomized order based on pseudo random number generator 
            //the starting index represents the pointer and we use this in the free() method in the heap allocator
            
            //iterate through everyhing 
            temp = head; 
            Block *prev_node;

            while(temp -> start_index != starting_index) {
                prev_node = temp; 
                temp = temp -> next;
            }

            if (temp->start_index == starting_index){
                prev_node -> next = temp -> next; 
            } else {
                cout << "Cannot find data to remove it";
            }
            
        }



};



