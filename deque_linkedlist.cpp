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

class Deque{


    public:
        Node* head = nullptr;
        Node* tail = nullptr;

        ~Deque(){
            for(Node* h=head; h; h=h->next){
                delete h;
            }
        }

        bool isEmpty(){
            return head == nullptr;
        }


        void push_back(int n){
            Node* temp = new Node(n);
            if(isEmpty()){
                cout << "stack is empty \n\n"; 
                head = tail = temp;
            }else{
                tail -> next = temp;
                temp -> previous = tail;
                tail = temp;
            }
        }

        int pop_back(){
            if(isEmpty()){
                cout << "pop back is empty \n"; 
                return -1;
            }
    
            int res = tail -> value;
            if(tail != head){  
                
                tail = tail -> previous;
                delete tail -> next;
                tail -> next = nullptr; 
                return res;
            }

            delete tail;
            tail = nullptr;
            return res; 
        }

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
        }

        int pop_front(){
            if(isEmpty()){
                cout << "stack is empty \n"; 
                return -1;
            }

            int res = head -> value;
            if(head != tail){  
                
                head = head -> next;  
                delete head -> previous;
                head -> previous = nullptr;
                return res;
            }

            delete head;
            head = nullptr;
            return res;
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

};

int main(){

    Deque dq;
    for(int i = 0; i < 5; i++){
        dq.push_front(i);
        // dq.push_back(i);
    }

    dq.print();

    for(int i = 0; i < 3; i++){
        // cout << "pop = " << dq.pop_back() << endl;
        cout << "pop = " << dq.pop_front() << endl;
    }

    return 0;
}