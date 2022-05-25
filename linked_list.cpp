#include <iostream>
using namespace std;

class Node{

    public:
        int value;
        Node* previous;
        Node* next;

        Node(int n){
            value = n;
        }
};

class LinkedList{

    public:
        Node* head = nullptr;
        Node* tail = nullptr;
        int len = -1;  // start from 0 index like arrays and count the length linkedlist

        bool isEmpty(){
            return head == nullptr;
        }


        //-----------back---------------
        void push_back(int n){
            Node* temp = new Node(n);
            if(isEmpty()){
                cout << "push back is empty \n\n"; 
                head = tail = temp;
            }else{
                tail -> next = temp;
                temp -> previous = tail;
                tail = temp;
            }
            len++;
        }

        int pop_back(){
            if(isEmpty()){
                cout << "pop back is empty \n"; 
                return -1;
            }
    
            int res = tail -> value;
            len--;
            if(tail != head){  
                
                tail = tail -> previous;   
                tail -> next = nullptr; 
                return res;
            }

            tail = head = nullptr;
            return res; 
        }

        //-----------------front------------------------
        void push_front(int n){
            Node* temp = new Node(n);
            if(isEmpty()){
                cout << "push front is empty \n"; 
                head = tail = temp;
            }else{
                head -> previous = temp;
                temp -> next = head;
                head = temp;
            }

            len++;
        }

        int pop_front(){
            if(isEmpty()){
                cout << "pop front is empty \n"; 
                return -1;
            }

            int res = head -> value;
            len--;

            if(head != tail){  
                
                head = head -> next;  
                head -> previous = nullptr;
                return res;
            }

            tail = head = nullptr;
            return res;
        }


        // -----------  pop by index -------------
        int pop_by_index(int n){
            if(isEmpty() || n<0 || n> len){
                cout << "is empty \n";
                return -1;
            }

            Node* node = getNode(n);

            if(node == tail){
                return pop_back();
            }else if (node == head){
                return pop_front();
            }else{
                node -> previous -> next = node -> next;
                node -> next -> previous = node -> previous;
                len--;
                return node -> value;
            }
        }


        //--------------- insert --------------------
        void insert(int n, int index){

            Node* node = getNode(index);
            Node* addedNode = new Node(n);
            if(index == 0){
                push_front(n);
            }else if(index == len + 1){
                push_back(n);
            }else{
                addedNode -> previous = node -> previous;
                addedNode -> next = node; 
                node -> previous -> next = addedNode; 
                node -> previous = addedNode;
                len++; 
            }
        }

        //----------------print-------------------
        void print(){
            cout << "\nPrint result!!!! \n\n";
            if(isEmpty()){
                cout << "nothing to print \n";
                return;
            }
            
            for(Node* h = head; h != nullptr; h = h -> next){
                cout << "value = " << h -> value << "\t";
                
            } 

            cout << endl << endl;   
        }

        void print_reverse(){
            cout << "\nPrint reverse!!!! \n\n";
            if(isEmpty()){
                cout << "nothing to print \n";
                return;
            }

            for(Node* t = tail; t != nullptr; t = t -> previous){
                cout << "value = " << t -> value << "\t";
            }   

            cout << endl << endl;    
        }

        //-----------get-------------------------
        int get(int n){
            if(n > len){
                cout << " WARNING!!!   segmentation fault :( \n"; 
                return -1;
            }

            Node* node = getNode(n);
            return node -> value;

        }

        int operator[](int n){
            if(n > len){
                cout << " WARNING!!!   segmentation fault :( \n"; 
                return -1;
            }

            Node* node = getNode(n);

            return node -> value;

        }

        Node* getNode(int n){

            if(isEmpty()){
                cout << "nothing to return \n";
                return nullptr;
            }

            Node* node = head;
            for(int i = 0; i < n; i++){
                node = node -> next;
            }

            return node;
        }
};



int main(){

    LinkedList ll;
    for(int i = 0; i < 5; i++){
        ll.push_front(i);
        // ll.push_back(i);
    }

    ll.print();
    //ll.print_reverse();
    // cout << "LinkedList = " << ll.get(4) << endl << endl;
    //cout << "LinkedList = " << ll[2] << endl << endl;
    // cout << "LinkedList = " << ll.pop_by_index(5) << endl << endl;
    ll.insert(100, 3);
    
    // for(int i = 0; i < 5; i++){
    //     // cout << "pop = " << ll.pop_back() << endl;
    //     cout << "pop = " << ll.pop_front() << endl;
    // }

    ll.print();

    ll.print_reverse();
    return 0;
}