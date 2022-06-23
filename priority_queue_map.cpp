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

        Priority_queue_map(){
            cout << "Non argument" << endl;
        }

        Priority_queue_map(Priority_queue_map& map){

            Node* h = map.head;
            while (h!=nullptr){
                push_back(h -> key, h->value);
                h = h -> next;
            }
        }

        ~Priority_queue_map(){
            if(!isEmpty()){

                while (head!=tail){
                    head = head -> next;
                    delete head -> previous;
                }
                delete head;
            }

        }

        //-------------operators-------------

        Priority_queue_map& operator=(const Priority_queue_map& map){

            Node* h = map.head;
            while (h!=nullptr){
                push_back(h -> key, h -> value);
                h = h -> next;
            }

            return *this;
        }

        bool operator==(Priority_queue_map map){
            if(len != map.getLen()){
                return false;
            }

            if(&map == this){
                return true;
            }

            Node* temp1 = head;
            Node* temp2 = map.head;
            for(int i = 0; i < len; i++){
        
                if(temp1 -> key != temp2 -> key){
                    return false;
                }
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;

            }
            return true;
        }

        int operator[](int k){
            
            if(find(k)){
                return address_of_repeated_key -> value;
            }

            return -1;
        }

    public:

        Node* head = nullptr;
        Node* tail = nullptr;
        int len = 0;

        Node* address_of_repeated_key = nullptr;  // initialising in the find() function and save the address of the repeated nodes


        bool isEmpty(){
            return head == nullptr;
        }


        //-----------back---------------

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

        Node pop_back(){

            // if(isEmpty()){
            //     return nullptr;
            // }
    
            Node deleted_tail(tail->key, tail->value);  // in all cases return the value of that tail
            len--;

            if(tail == head){     // check the last element
                delete tail;
                tail = head = nullptr;
                
                return deleted_tail; 
            }

            tail = tail -> previous; 
            delete tail -> next;  
            tail -> next = nullptr; 
            
            cout << deleted_tail.key << " : " << deleted_tail.value << endl;
            return deleted_tail;
        }

        // int pop_back(){

        //     if(isEmpty()){
        //         return -1;
        //     }
    
        //     int res_key = tail -> key;  // in all cases return the value of that tail
        //     len--;

        //     if(tail == head){     // check the last element
        //         delete tail;
        //         tail = head = nullptr;
                
        //         return res_key; 
        //     }

        //     tail = tail -> previous; 
        //     delete tail -> next;  
        //     tail -> next = nullptr; 
            
        //     return res_key;
        // }

        //--------------front--------------------

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

        int pop_front(){

            if(isEmpty()){
                return -1;
            }

            int res_key = head -> value;    // in all cases return the value of that head
            len--;

            if(head == tail){   // check the last element
                
                delete head;
                tail = head = nullptr;
                
                return res_key;
            }

            head = head -> next;  
            delete head -> previous;
            head -> previous = nullptr;
            return res_key;
        }

        //-----------------insert----------------------

        void insert(int k, int v, int index){

            if(find(k)){                   // check if keys repeated, change only the value
                address_of_repeated_key -> value = v;
                return;
            }

            if(index > len-1){   // if input invalid index, adding node after the last element 
                cout << "the lenght of list is " << len << ". Adding node will be after the last element!" << endl;
                push_back(k, v);
                return;
            }

            Node* addedNode = new Node(k, v);

            if(index == 0){
                push_front(k, v);
            }else if(index == len-1){  // index starts from 0
                push_back(k, v);
            }else{

                Node* node = head;               // get node with given index
                for(int i = 0; i < index; i++){
                    node = node -> next;
                }

                addedNode -> previous = node -> previous;
                addedNode -> next = node; 
                node -> previous -> next = addedNode; 
                node -> previous = addedNode;
                len++; 
            }
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

        void add(int k, int v){

            if(isEmpty()){
                push_back(k, v);
                return;
            }

            if(k < head->key){

                push_front(k, v);

            }else if(k > tail->key){

                push_back(k, v);

            }else{

                if(find(k)){
                    address_of_repeated_key->value = v;
                    return;
                }else{

                    Node* node = head;
                    Node* addedNode = new Node(k, v);

                    while (k > node->key){
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

        void add_tail(int k, int v){

            if(isEmpty()){
                push_back(k, v);
                return;
            }

            if(k < head->key){

                push_front(k, v);

            }else if(k > tail->key){

                push_back(k, v);

            }else{

                if(find(k)){
                    address_of_repeated_key->value = v;
                    return;
                }else{

                    Node* node = tail;
                    Node* addedNode = new Node(k, v);

                    while (k < node->key){
                        node = node->previous;
                    }
                    
                    addedNode -> next = node -> next; 
                    addedNode -> previous = node;
                    node -> next -> previous = addedNode; 
                    node -> next = addedNode; 
                    
                    len++;
                    return;
                }
            }
               
        }

        int getLen(){
            return len;
        }

        void print(){

            cout << "\nPrint result!!!! \n\n";
            
            for(Node* h = head; h != nullptr; h = h -> next){
                cout << h -> key << ":  " << h -> value << endl;
                
            } 

            cout << endl << endl;   
        }

        
};

int main(){

    Priority_queue_map map;

    map.add(10, 300);
    map.add(0, 100);
    map.add(50, 500);
    map.add(5, 200);
    map.add(25, 400);
    map.add(25, 400);
    map.add(25, 1000);
    
    
    map.print();

    map.pop_back();
    map.pop_back();
    // cout << map.pop_back()->value << "\n";

    map.print();
    // Priority_queue_map map2;

    // map2.add_tail(10, 300);
    // map2.add_tail(0, 100);
    // map2.add_tail(50, 500);
    // map2.add_tail(5, 200);
    // map2.add_tail(25, 400);
    // map2.add_tail(25, 500);
    // map2.add_tail(25, 600);
    // map2.add_tail(25, 700);
    // map2.print();


    // if(map == map2){
    //     cout << "True" << endl;
    // }else{
    //     cout << "False" << endl;
    // }

    return 0;

}