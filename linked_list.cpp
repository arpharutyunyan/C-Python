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
            
            if(!isEmpty()){
                while (head!=tail){
                    head = head -> next;
                    delete head -> previous;
                }
                delete head;
            }

            Node* h = copy_list.head;
            while (h!=nullptr){
                push_back(h -> value);
                h = h -> next;
            }
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

        bool find(int x){
            Node* node = head;

            while (node != nullptr){
               if(x == node -> value){
                    return true;
                }
                node = node -> next;
            }
            
            return false;
        }

        void insert_sort(){

            if(head == tail){
                return;
            }

            for(Node* temp = head->next; temp!=nullptr; temp=temp->next){

                Node* pre = temp->previous;
                while (pre!=nullptr and temp->value < pre->value){
                    pre = pre->previous;
                }

                if(pre==nullptr){   // the first element

                    Node* t = temp;       // save the node temp, because in the loop I will lost the temp place

                    //disconnect temp
                    if(temp->next!=nullptr){                 
                        temp->previous->next = temp->next;
                        temp->next->previous = temp->previous;
                    }else{                                  // if the next is null it is the tail: last element
                        temp->previous->next = nullptr;
                        tail = temp->previous;
                    }         
                    
                    temp->previous = nullptr;    // change node connection
                    temp->next = head;
                    head->previous = temp;
                    head = temp;

                    temp = t->next;


                }else if(temp->value >= pre->value and pre != temp->previous){  // 

                    Node* t = temp;

                    //disconnect temp
                    if(temp->next!=nullptr){                      
                        temp->previous->next = temp->next;
                        temp->next->previous = temp->previous;
                    }else{                                           // if the next is null it is the tail: last element
                        temp->previous->next = nullptr;
                        tail = temp->previous;
                    }  

                    temp->previous = pre;                  // change node connection
                    temp->next = pre->next;

                    pre->next->previous = temp;
                    pre->next = temp;

                    temp = t->next;
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

                    int x = pre->next->value;
                    pre->next->value = pre->value;
                    pre->value = x;

                    pre = pre->previous;
                }
            }
        }

        //----------------print-------------------
        void print(){
            //cout << "\nPrint result!!!! \n\n";
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
            
            for(Node* t = tail; t != nullptr; t = t -> previous){
                cout << "value = " << t -> value << "\t";
            }   

            cout << endl << endl;    
        }

        //-----------get-------------------------
        

        int size(){
            return len;
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


        //------------------operator-------------------------
        
        bool operator==(LinkedList second){
            if(len  != second.size()){
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

        LinkedList& operator=(const LinkedList& copy_list){

            
            if(!isEmpty()){
                while (head!=tail){
                    head = head -> next;
                    delete head -> previous;
                }
                delete head;
                head = tail = nullptr;
            }
            
            Node* h = copy_list.head;
            while (h!=nullptr){
                push_back(h -> value);
                h = h -> next;
            }
            return *this;
        }

        int operator[](int n){
            if(n > len - 1){
                cout << " WARNING!!!   segmentation fault :( \n"; 
                return -1;
            }

            Node* node = getNode(n);

            return node -> value;

        }
};



int main(){

    LinkedList ll;
    ll.push_back(100);
    ll.push_back(50);
    ll.push_back(10);
    ll.push_back(2);
    ll.push_back(20);
    ll.push_back(15);
    ll.push_back(0);

    ll.print();

    cout << "insert_sort \n\n";
    ll.insert_sort();
    ll.print();

    cout << "insert_sort_swap \n\n";
    ll.insert_sort_swap();
    ll.print();

    return 0;

}