#include <iostream>
using namespace std;

class Node{

    public:
        int value = 0;
        Node* previous = nullptr;
        Node* next = nullptr;

        Node(int n){
            value = n;
        }
};

class LinkedList{

    public:

        Node* head = nullptr;
        Node* tail = nullptr;
        int len = 0;
       
        LinkedList(){
            cout << "Non argument" << endl;
        }

        LinkedList(const LinkedList& copy_list){
            
            Node* h = copy_list.head;
            while (h!=nullptr){
                push_back(h -> value);
                h = h -> next;
            }
        }

        LinkedList& operator=(const LinkedList& copy_list){

            Node* h = copy_list.head;
            while (h!=nullptr){
                push_back(h -> value);
                h = h -> next;
            }

            return *this;
        }
        
        ~LinkedList(){
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
                delete tail -> next;  
                tail -> next = nullptr; 
                
                return res;
            }

            delete tail;
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
                delete head -> previous;
                head -> previous = nullptr;
                return res;
            }

            delete head;
            tail = head = nullptr;
            
            return res;
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
        

        int getLen(){
            return len;
        }

        int operator[](int n){
            if(n > len - 1){
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


        bool operator==(LinkedList second){
            if(len  != second.getLen()){
                return false;
            }

            Node* temp1 = head;
            Node* temp2 = second.head;
            for(int i = 0; i < len; i++){
                cout << "temp1" << temp1 -> value << "\t";
                if(temp1 -> value != temp2->value){
                    return false;
                }
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;

            }
            return true;
        }
};



int main(){

    LinkedList ll;
    for(int i = 0; i < 5; i++){
        // ll.push_front(i);
        ll.push_back(i);
    }

    cout << "len = " << ll.getLen() << endl;
    // cout << "get = " << ll[4] << endl;


    LinkedList second;

    second = ll;
    cout << "len = " << second.getLen() << endl;
    ll.print();
    second.print();
    // for(int i = 0; i < 5; i++){
    //     // ll.push_front(i);
    //     second.push_back(i);
    // }


    // cout << "len = " << second.getLen() << endl;
    // if(ll == second){
    //     cout << "Is equals" << endl;
    // }else{
    //     cout << "Is not equals" << endl;
    // }



    // ll.print();

    // for(int i = 0; i < 2; i++){
    //     cout << "pop = " << ll.pop_back() << endl;
    //     // cout << "pop = " << ll.pop_front() << endl;
    // }

    // ll.print();

    // ll.print_reverse();
    return 0;

}