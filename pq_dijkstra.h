#include <iostream>

using namespace std;

class Node{

    public:
        int value = 0;
        int key = 0;
        Node* previous = nullptr;
        Node* next = nullptr;

        Node(int k, int v){
            key = k;
            value = v;
        }
};


class Priority_queue_map{

    public:

        Priority_queue_map(){}

        ~Priority_queue_map(){
            if(!isEmpty()){

                while (head!=tail){
                    head = head -> next;
                    delete head -> previous;
                }
                delete head;
            }
        }

    public:

        Node* head = nullptr;
        Node* tail = nullptr;
        int len = 0;
        Node* address_of_repeated_key = nullptr;

        bool isEmpty(){
            return head == nullptr;
        }

        void push_back(int k, int v){


            if(isEmpty()){          
                head = tail = new Node(k, v);         // create the first element
                len++;
            }else if(find(k)){
                address_of_repeated_key -> value = v;    // check if keys repeated, change only the value
            }else{
                Node* node = new Node(k, v);
                tail -> next = node;
                node -> previous = tail;
                tail = node;
                len++;
            }   
        }

        void push_front(int k, int v){

            if(isEmpty()){                   // create the first element
                head = tail = new Node(k, v);
                len++;
            }else if(find(k)){
                address_of_repeated_key -> value = v;    // check if keys repeated, change only the value  
            }else{
                Node* node = new Node(k, v);
                head -> previous = node;
                node -> next = head;
                head = node;
                len++;
            }   
        }

        Node pop(){
    
            Node deleted_head(head->key, head->value);  // in all cases return the value of that tail
            len--;

            if(head == tail){     // check the last element
                delete head;
                tail = head = nullptr;
                
                return deleted_head; 
            }

            head = head -> next;  
            delete head -> previous;
            head -> previous = nullptr; 
            
            // cout << deleted_head.key << " : " << deleted_head.value << endl;
            return deleted_head;
        }

        bool find(int k){

            for(Node* node = head; node != nullptr; node = node -> next){
                if(k == node -> key){
                    address_of_repeated_key = node;   // save the adrress of repeated key

                    return true;
                }
            }
            return false;
        }

    public:

        void add_with_value(int k, int v){

            if(isEmpty()){
                push_back(k, v);
                return;
            }

            if(v <= head->value){

                push_front(k, v);

            }else if(v >= tail->value){

                push_back(k, v);

            }else{

                if(find(k)){
                    address_of_repeated_key->value = v;
                    return;

                }else{
                    Node* node = head;
                    Node* addedNode = new Node(k, v);

                    while (v >= node->value){
                        node = node->next;
                    }
                    
                    addedNode -> next = node; 
                    addedNode -> previous = node->previous;
                    node -> previous -> next = addedNode; 
                    node -> previous = addedNode; 

                    len++;
                    return;
                }
            }
        }  

        void insert_sort_swap(){

            if(head == tail){
                return;
            }

            for(Node* temp = head->next; temp!=nullptr; temp=temp->next){

                Node* pre = temp->previous;
                while (pre!=nullptr and pre->value > pre->next->value){

                    int v = pre->next->value;
                    int k = pre->next->key;
                    pre->next->value = pre->value;
                    pre->next->key = pre->key;
                    pre->value = v;
                    pre->key = k;

                    pre = pre->previous;
                }
            }
        }    

        void print(){

            cout << "\nPrint result!!!! \n\n";
            
            for(Node* h = head; h != nullptr; h = h -> next){
                cout << h -> key << ":  " << h -> value << endl;
                
            } 

            cout << endl << endl;   
        }        
};