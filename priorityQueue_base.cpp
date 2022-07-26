#include <iostream>
#include "rectangle.cpp"
using namespace std;


class Node{

    public:
        int value;
        Node* previous = nullptr;
        Node* next = nullptr;

        Node(int n){
            value = n;
        }
};


class Priority_queue{

    public:
       
        Priority_queue(){}

        Priority_queue(const Priority_queue& copy_list){

            // cout << "copy constructor \n";
            
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

               
        ~Priority_queue(){
            // cout << "destructor \n";

            if(!isEmpty()){
                while (head!=tail){
                    head = head -> next;
                    delete head -> previous;
                }
                delete head;
            }
        }

        //------------------operator-------------------------
        
        bool operator==(Priority_queue& second){
            if(len  != second.getLen()){
                return false;
            }

            if(&second == this){
                return true;
            }

            Node* temp1 = head;
            Node* temp2 = second.head;
            for(int i = 0; i < len; i++){

                if(temp1 -> value != temp2->value){  
                    return false;
                }
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;

            }
            return true;
        }

        Priority_queue& operator=(const Priority_queue& copy_list){

            
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
                // cout << " WARNING!!!   segmentation fault :( \n"; 
                return -1;
            }

            Node* node = getNode(n);

            return node -> value;

        }

        friend ostream& operator<<(ostream& print, const Priority_queue& pq){
            cout << "\n operator << Print in priority queue \n\n";
            
            for(auto h = pq.head; h != nullptr; h = h -> next){
                cout << "value = " << h -> value << "\t";
                // cout << h -> value << endl;
                
            } 

            cout << endl << endl;   
            return print;
        }

    private:

        Node* head = nullptr;
        Node* tail = nullptr;
        int len = 0;

        bool isEmpty(){
            return head == nullptr;
        }

        //-----------back---------------
        void push_back(int n){
            Node* temp = new Node(n);
            if(isEmpty()){
                // cout << "push back is empty \n\n"; 
                head = tail = temp;
            }else{
                tail -> next = temp;
                temp -> previous = tail;
                tail = temp;
            }
            len++;
        }

        Node pop_back(){
            if(isEmpty()){
                // cout << "pop back is empty \n"; 
                return -1;
            }
    
            // int res = tail -> value;
            Node res = *tail;
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
                // cout << "push front is empty \n"; 
                head = tail = temp;
            }else{
                head -> previous = temp;
                temp -> next = head;
                head = temp;
            }

            len++;
        }

        Node pop_front(){
            if(isEmpty()){
                // cout << "pop front is empty \n"; 
                return -1;
            }

            // int res = head -> value;
            Node res = *head;
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

    public:

        void add(int n, bool reverse = false){

            if(isEmpty()){
                push_back(n);
                return;
            }

            if(!reverse){
                if(n <= head->value){

                    push_front(n);

                }else if(n >= tail->value){

                    push_back(n);

                }else{

                    Node* node = head;
                    Node* addedNode = new Node(n);

                    while (n > node->value){
                        node = node->next;
                    }
                    
                    addedNode -> next = node; 
                    addedNode -> previous = node->previous;
                    node -> previous -> next = addedNode; 
                    node -> previous = addedNode; 

                    len++;
                    return;
                }
                
            }else{
                if(n >= head->value){

                    push_front(n);

                }else if(n <= tail->value){

                    push_back(n);

                }else{

                    Node* node = head;
                    Node* addedNode = new Node(n);

                    while (n < node->value){
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

        //----------------print-------------------
        // void print(){
        //     cout << "\nPrint result!!!! \n\n";
        //     if(isEmpty()){
        //         cout << "nothing to print \n";
        //         return;
        //     }
            
        //     for(auto h = head; h != nullptr; h = h -> next){
        //         // cout << "value = " << h -> value << "\t";
        //         cout << h -> value << endl;
                
        //     } 

        //     cout << endl << endl;   
        // }

        void print_reverse(){
            cout << "\nPrint reverse!!!! \n\n";
            
            for(auto t = tail; t != nullptr; t = t -> previous){
                cout << "value = " << t -> value << "\t";
            }   

            cout << endl << endl;    
        }

        //-----------get-------------------------
        

        int getLen(){
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
};



int main(){

    Priority_queue pq;


    pq.add(10);
    pq.add(0);
    pq.add(50);
    pq.add(5);
    pq.add(5);
    pq.add(25);

    // cout << "pq \n"; 
    // pq.print();
    cout << pq;

    Priority_queue pq1;

    pq1.add('c');
    pq1.add('d');
    pq1.add('u');
    pq1.add('a');
    pq1.add('k');
    pq1.add('x');
    cout << "pq1 \n"; 
    cout << pq1;
    // pq1.print();

    return 0;

}