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

        void push_back(int n){
            Node* temp = new Node(n);
            if(head == nullptr){
                head = tail = temp;
            }else{
                tail -> next = temp;
                temp -> previous = tail;
                tail = temp;
            }
        }

        void push_front(int n){
            Node* temp = new Node(n);
            if(head == nullptr){
                head = tail = temp;
            }else{
                head -> previous = temp;
                temp -> next = head;
                head = temp;
            }
        }

        void print(){
            Node* h = head;
            while (h != nullptr){
                cout << "value = " << h -> value << endl;;
                h = h -> next;
            }    
        }

        void print_reverse(){
            Node* t = tail;
            while (t != nullptr){
                cout << "value = " << t -> value << endl;;
                t = t -> previous;
            }    
        }
};


int main(){

    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);

    // ll.push_front(1);
    // ll.push_front(2);
    // ll.push_front(3);

    ll.print_reverse();
    return 0;
}