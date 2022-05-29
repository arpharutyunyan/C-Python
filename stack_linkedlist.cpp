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

        ~Stack(){

            while (head!=tail){
                head = head -> next;
                delete head -> previous;
            }
            delete head;
  
        }

        bool isEmpty(){
            return head == nullptr;
        }


        void push(int n){
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

        int pop(){
            if(isEmpty()){
                cout << "stack is empty \n"; 
                return -1;
            }
    
            int res = tail -> value;
            if(tail->previous != nullptr){  
                
                tail = tail -> previous; 
                delete tail -> next; 
                tail -> next = nullptr; 
                return res;
            }

            delete tail;
            tail = nullptr;
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
        st.push(i);
    }

    // st.print();  // running print() function gives error in valgrind: for() loops touch tail->next = nullptr

    for(int i = 0; i < 3; i++){
        cout << "pop = " << st.pop() << endl;
    }

    // st.print();

    return 0;
}