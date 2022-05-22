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
        int index = -1;  // start from 0 index like arrays and count the length linkedlist

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
            index++;
        }

        int pop_back(){
            if(isEmpty()){
                cout << "pop back is empty \n"; 
                return -1;
            }
    
            int res = tail -> value;
            index--;
            if(tail -> previous != head){  
                
                Node* new_tail = tail -> previous;   //if tail.previous == head  new_tail == nullptr
                tail -> previous = nullptr;   
                new_tail -> next = nullptr;  // if new_tail == nullptr  give segmentation fault
                tail = new_tail;
                return res;
            }

            tail -> next = nullptr;
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

            index++;
        }

        int pop_front(){
            if(isEmpty()){
                cout << "pop back is empty \n"; 
                return -1;
            }

            int res = head -> value;
            index--;

            if(head -> next != tail){  
                
                Node* new_head = head -> next;   //if head -> next == tail  new_head == nullptr
                head -> next = nullptr;   
                new_head -> previous = nullptr;  // if new_head == nullptr  give segmentation fault
                head = new_head;
                return res;
            }

            head -> previous = nullptr;
            tail = head = nullptr;
            return res;
        }


        //----------------print-------------------
        void print(){
            cout << "\nPrint result!!!! \n\n";
            if(isEmpty()){
                cout << "nothing to print \n";
                return;
            }
            Node* h = head;
            while (h != nullptr){
                cout << "value = " << h -> value << "\t";
                h = h -> next;
            } 

            cout << endl << endl;   
        }

        void print_reverse(){
            cout << "\nPrint reverse!!!! \n\n";
            if(isEmpty()){
                cout << "nothing to print \n";
                return;
            }
            Node* t = tail;
            while (t != nullptr){
                cout << "value = " << t -> value << "\t";
                t = t -> previous;
            }   

            cout << endl << endl;    
        }

        //-----------get-------------------------
        int get(int n){
            if(n > index){
                cout << " WARNING!!!   segmentation fault :( \n"; 
                return -1;
            }

            Node* node = head;
            for(int i = 0; i < n; i++){
                node = node -> next;
            }

            return node -> value;

        }
};



int main(){

    LinkedList ll;
    for(int i = 0; i < 5; i++){
        //ll.push_front(i);
        ll.push_back(i);
    }

    ll.print();
    cout << "LinkedList = " << ll.get(5) << endl << endl;

    for(int i = 0; i < 3; i++){
        cout << "pop = " << ll.pop_back() << endl;
        //cout << "pop = " << ll.pop_front() << endl;
    }

    ll.print();
    ll.print_reverse();
    return 0;
}