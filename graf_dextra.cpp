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

        bool isEmpty(){
            return head == nullptr;
        }

        void push_back(int k, int v){

            if(isEmpty()){          
                head = tail = new Node(k, v);         // create the first element
                len++;
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
        {0, 0, 0, 60, 0, 0, 0, 30, 0}, //4    Yeghvard
        {0, 0, 60, 0, 0, 0, 25, 0, 30}, //5    Talin
        {45, 0, 0, 40, 0, 25, 0, 70, 0}, //6    Aparan
        {0, 12, 0, 0, 30, 0, 70, 0, 0}, //7    Abovyan
        {15, 0, 0, 0, 0, 30, 0, 0, 0}, //8    Oshakan
    };


    int relation[row][col] = {
      // 0  1  2  3  4  5  6  7  8  j
        {0, 1, 0, 0, 0, 0, 1, 0, 1}, //0    Ashtarak  i
        {1, 0, 0, 0, 0, 0, 0, 1, 0}, //1    Yerevan
        {0, 0, 0, 1, 0, 1, 0, 0, 0}, //2    Gyumri
        {0, 0, 1, 0, 1, 0, 1, 0, 0}, //3    Atashat
        {0, 0, 0, 1, 0, 0, 0, 1, 0}, //4    Yeghvard
        {0, 0, 1, 0, 0, 0, 1, 0, 1}, //5    Talin
        {1, 0, 0, 1, 0, 1, 0, 1, 0}, //6    Aparan
        {0, 1, 0, 0, 1, 0, 1, 0, 0}, //7    Abovyan
        {1, 0, 0, 0, 0, 1, 0, 0, 0}, //8    Oshakan
    };

    string cities[9] = {"ashtarak", "yerevan", "gyumri", "artashat", "yeghvard", "talin", "aparan", "abovyan", "oshakan"};

    int weights[row] = {};

    // add first weights
    for(int i=0; i<row; i++){
        weights[i] = INT_MAX;
        // cout << weights[i] << "\t";
    }

    int start_index = 2;
    int finish_index = 1;
    weights[start_index] = 0; // start is Gyumri

    Node node(start_index, 0);
    pq.add_with_value(node.key, node.value);

    while (!pq.isEmpty()){

        Node pop = pq.pop();

        if(pop.key == finish_index){
            break;
        }

        for (int i=0; i<row; i++){
           if(incidence[pop.key][i] > 0){
                int value = weights[pop.key] + incidence[pop.key][i];
                weights[i] = value;
                pq.add_with_value(i, value);
           }
        }

        // pop = pq.pop();
        // weights[pop.key] = pop.value;
        // break;
        
    }
    
    for(int i=0; i<row; i++){
        cout << weights[i] << "\t";
    }
    // show realtion
    // for(int i=0; i<row; i++){

    //     cout << cities[i] << "  -> [";
    //     for(int j=0; j<col; j++){

            
    //         if(relation[i][j] > 0){
    //             cout << cities[j] << ", ";
    //         }
            
    //     }

    //     cout << "]" << endl << endl;
        
    // }

    // add to priority queue
    // for(int i=0; i<row; i++){

    //     for(int j=0; j<col; j++){

            
    //         if(incidence[i][j] > 0){
               
    //             pq.add_with_value(i, incidence[i][j]);
    //         }
            
    //     }        
    // }

    pq.print();

    return 0;
}