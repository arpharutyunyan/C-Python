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

class Stack{

    public:
        Node* head = nullptr;
        Node* tail = nullptr;

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
                tail -> next = nullptr; 
                return res;
            }

            tail = head = nullptr;
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
                head -> previous = nullptr;
                return res;
            }

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
            
            for(Node* h = head; h != nullptr; h = h -> next){
                cout << "value = " << h -> value << "\t";
                
            } 

            cout << endl << endl;   
        }

};

int main(){

    Stack st;
    for(int i = 0; i < 5; i++){
        // st.push_front(i);
        st.push_back(i);
    }

    st.print();

    for(int i = 0; i < 5; i++){
        // cout << "pop = " << st.pop_back() << endl;
        cout << "pop = " << st.pop_front() << endl;
    }

    return 0;
}