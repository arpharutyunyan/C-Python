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


class MyMap{

    public:

        Node* head = nullptr;
        Node* tail = nullptr;
        int len = 0;
        Node* address_of_repeated_key = nullptr;

        MyMap(){
            cout << "Non argument" << endl;
        }

        MyMap(MyMap& map){

            Node* h = map.head;
            while (h!=nullptr){
                push_back(h -> key, h->value);
                h = h -> next;
            }

        }

        ~MyMap(){
            if(!isEmpty()){

                while (head!=tail){
                    head = head -> next;
                    delete head -> previous;
                }
                delete head;

                
            }
        }

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

        int pop_back(){

            if(isEmpty()){
                return -1;
            }
    
            int res_key = tail -> key;  // in all cases return the value of that tail
            len--;

            if(tail == head){     // check the last element
                delete tail;
                tail = head = nullptr;
                
                return res_key; 
            }

            tail = tail -> previous; 
            delete tail -> next;  
            tail -> next = nullptr; 
            
            return res_key;
        }

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

            if(index > len-1){
                cout << "the lenght of list is " << len << ". Adding node will be after the last element!" << endl;
                push_back(k, v);
                return;
            }

            Node* addedNode = new Node(k, v);

            if(index == 0){
                push_front(k, v);
            }else if(index == len-1){  // count index from 0
                push_back(k, v);
            }else{

                Node* node = head;                    // get node with given index
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


        //-------------operators-------------

        MyMap& operator=(const MyMap& map){

            Node* h = map.head;
            while (h!=nullptr){
                push_back(h -> key, h -> value);
                h = h -> next;
            }

            return *this;
        }

        bool operator==(MyMap map){
            if(len != map.getLen()){
                return false;
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


};

int main(){

    MyMap map;

    for(int i = 0; i < 5; i++){
        // map.push_front(i, i+10);
        map.push_back(i, i+10);
    }

    // map.print();

    map.insert(2, 15, 100);
    map.insert(2, 150, 100);

    map.print();

    map.push_back(2, 5);
    map.push_front(1, 5);

    map.print();

    MyMap map2(map);
    map2.print();

    // MyMap map3;
    // map3 = map2;
    // map3.print();

    // if(map == map2){
    //     cout << "True" << endl;
    // }else{
    //     cout << "False" << endl;
    // }

    // for(int i = 0; i < 2; i++){
    //     // cout << "key = " << map.pop_front() << endl;
    //     cout << "key = " << map.pop_back() << endl;
    // }

    return 0;

}