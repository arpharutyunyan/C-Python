#include <iostream>
#include <climits>
// #include "priority_queue_map.cpp"

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


class Priority_queue_map{

    public:

        Priority_queue_map(){}

        ~Priority_queue_map(){
            if(!isEmpty()){

                while (head!=tail){
                    head = head -> next;
                    delete head -> previous;
                }
                delete head;
            }
        }

    public:

        Node* head = nullptr;
        Node* tail = nullptr;
        int len = 0;
        Node* address_of_repeated_key = nullptr;

        bool isEmpty(){
            return head == nullptr;
        }

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

        Node pop(){
    
            Node deleted_head(head->key, head->value);  // in all cases return the value of that tail
            len--;

            if(head == tail){     // check the last element
                delete head;
                tail = head = nullptr;
                
                return deleted_head; 
            }

            head = head -> next;  
            delete head -> previous;
            head -> previous = nullptr; 
            
            cout << deleted_head.key << " : " << deleted_head.value << endl;
            return deleted_head;
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

    public:

        void add_with_value(int k, int v){

            if(isEmpty()){
                push_back(k, v);
                return;
            }

            if(v <= head->value){

                push_front(k, v);

            }else if(v >= tail->value){

                push_back(k, v);

            }else{

                if(find(k)){
                    address_of_repeated_key->value = v;
                    return;

                }else{
                    Node* node = head;
                    Node* addedNode = new Node(k, v);

                    while (v >= node->value){
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

        void insert_sort_swap(){

            if(head == tail){
                return;
            }

            for(Node* temp = head->next; temp!=nullptr; temp=temp->next){

                Node* pre = temp->previous;
                while (pre!=nullptr and pre->value > pre->next->value){

                    int v = pre->next->value;
                    int k = pre->next->key;
                    pre->next->value = pre->value;
                    pre->next->key = pre->key;
                    pre->value = v;
                    pre->key = k;

                    pre = pre->previous;
                }
            }
        }    

        void print(){

            cout << "\nPrint result!!!! \n\n";
            
            for(Node* h = head; h != nullptr; h = h -> next){
                cout << h -> key << ":  " << h -> value << endl;
                
            } 

            cout << endl << endl;   
        }        
};


int main(){

    int row = 9;
    int col = 9;

    Priority_queue_map pq;

    //weight
    int incidence[row][col] = {
      // 0  1  2  3  4  5  6  7  8
        {0, 5, 0, 0, 0, 0, 45, 0, 15}, //0    Ashtarak
        {5, 0, 0, 0, 0, 0, 0, 12, 0}, //1    Yerevan
        {0, 0, 0, 20, 0, 60, 0, 0, 0}, //2    Gyumri
        {0, 0, 20, 0, 60, 0, 40, 0, 0}, //3    Atashat
        {0, 0, 0, 60, 0, 0, 0, 2, 0}, //4    Yeghvard
        {0, 0, 60, 0, 0, 0, 25, 0, 30}, //5    Talin
        {45, 0, 0, 40, 0, 25, 0, 70, 0}, //6    Aparan
        {0, 12, 0, 0, 30, 0, 70, 0, 0}, //7    Abovyan
        {15, 0, 0, 0, 0, 30, 0, 0, 0}, //8    Oshakan
    };


    string cities[9] = {"ashtarak", "yerevan", "gyumri", "artashat", "yeghvard", "talin", "aparan", "abovyan", "oshakan"};

    int weights[row] = {};

    bool checked[row] = {false}; // first the all cityies is not checked

    int past_way[row] = {0};

    // add first weights
    for(int i=0; i<row; i++){
        weights[i] = INT_MAX;
        // cout << weights[i] << "\t";
    }

    int start_index = 2;  // start is Gyumri
    int finish_index = 1;
    weights[start_index] = 0; // add first weight

    pq.add_with_value(start_index, 0); // add first node in pq

    while (!pq.isEmpty()){

        Node pop = pq.pop();
        checked[pop.key] = true; // add to checked array

        for (int i=0; i<row; i++){
           if(incidence[pop.key][i] > 0){
        
                if(!checked[i] ){
                    
                    int value = weights[pop.key] + incidence[pop.key][i]; // update value for weights
                    if(value < weights[i]){
                        weights[i] = value;
                        past_way[pop.key] = i;
                    }
                    
                    if(i != finish_index){
                        pq.add_with_value(i, weights[i]); 
        
                        pq.insert_sort_swap();
                       
                    }
                    
                }          
            }
        }

        cout << "key = " << pop.key << endl;
        // pq.print();
        
    }
    
    for(int i=0; i<row; i++){
        cout << "weights[" << i << "] = " << weights[i] << endl;
    }

    for(int i=0; i<row; i++){
        cout << "checked[" << i << "] = " << checked[i] << endl;
    }

    
    // for(int i=0; i<row; i++){
    //     cout << "past_way[" << i << "] = " << past_way[i] << endl;
    // }

    return 0;
}