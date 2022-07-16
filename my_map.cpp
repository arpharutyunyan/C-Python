#include <iostream>
#include <ctime>
using namespace std;

class IndexOutOfBounds : public exception{
    public:
        int index;
        int len;
        string exp_case;
        string solution;
        time_t time;

        IndexOutOfBounds(int index, int len, string exp_case, string solution, time_t time){
            this->index = index;
            this->len = len;
            this->exp_case = exp_case;
            this->solution = solution;
            this->time = time;
        }

        void info(){
            cout << "-----------------------------------------\n";
            cout << "index: " << index << endl;
            cout << "len: " << len << endl;
            cout << "case: " << exp_case << endl;
            cout << "solution: " << solution << endl;
            cout << "in time:  " << ctime(&time) << endl;
            cout << "-----------------------------------------\n";

        }

        const char* what() const throw(){
            return "some text in IndexOutOfBounds";
        }
};

class NotFound : public exception{
    public:
        string func_name;
        string exp_case;
        string solution;
        time_t time;
        int key;

        NotFound(string func_name, string exp_case, string solution, time_t time, int key = -1){
            this->func_name = func_name;
            this->exp_case = exp_case;
            this->solution = solution;
            this->time = time;
            this->key = key;
        }

        const char* what() const throw(){
            return "some text in EmptyMap";
        }

        void info(){
            cout << "-----------------------------------------\n";
            cout << "calling function: " << func_name << endl;
            cout << "case: " << exp_case << endl;
            cout << "solution: " << solution << endl;
            cout << "in time:  " << ctime(&time) << endl;
            if(key > -1){
                cout << "key:  " << key << endl;
            }
            cout << "-----------------------------------------\n";

        }
};

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


class MyMap{

    public:

        Node* head = nullptr;
        Node* tail = nullptr;
        int len = 0;

        // int* arr_of_keys = NULL;  // pointer of arrays wich is using in function keys() and contains all keys
        // int* arr_of_values = NULL;   // pointer of arrays wich is using in function vallues() and contains all keys
        Node* address_of_repeated_key = nullptr;  // initialising in the find() function and save the address of the repeated nodes

        MyMap(){
            // cout << "Non argument" << endl;
        }

        MyMap(MyMap& map){

            Node* h = map.head;
            while (h!=nullptr){
                push_back(h -> key, h->value);
                h = h -> next;
            }
        }

        ~MyMap(){
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

        int pop_back(){

            if(isEmpty()){
                NotFound emap("pop_back", "Map is empty.", "First push anything.", time(0));
                throw emap;
            }
    
            int res_key = tail -> key;  // in all cases return the value of that tail
            len--;

            if(tail == head){     // check the last element
                delete tail;
                tail = head = nullptr;
                
                return res_key; 
            }

            tail = tail -> previous; 
            delete tail -> next;  
            tail -> next = nullptr; 
            
            return res_key;
        }

        //--------------front--------------------

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

        int pop_front(){

            if(isEmpty()){
                NotFound emap("pop_front", "Map is empty.", "First push anything.", time(0));
                throw emap;
            }

            int res_key = head -> value;    // in all cases return the value of that head
            len--;

            if(head == tail){   // check the last element
                
                delete head;
                tail = head = nullptr;
                
                return res_key;
            }

            head = head -> next;  
            delete head -> previous;
            head -> previous = nullptr;
            return res_key;
        }

        //-----------------insert----------------------

        void insert(int k, int v, int index){

            if(find(k)){                   // check if keys repeated, change only the value
                address_of_repeated_key -> value = v;
                return;
            }

            if(index < 0 ){
                IndexOutOfBounds exp(index, len, "Index is small 0.", "Index must be great than 0.", time(0));
                throw exp;
            }

            if(index > len){   // if input invalid index, adding node after the last element 
                // cout << "the lenght of list is " << len << ". Adding node will be after the last element!" << endl;
                // push_back(k, v);
                // return;
                IndexOutOfBounds exp(index, len, "Index is great the length.", "Index must be small or equal the length.", time(0));
                throw exp;
            }

            Node* addedNode = new Node(k, v);

            if(index == 0){
                push_front(k, v);
            }else if(index == len-1){  // index starts from 0
                push_back(k, v);
            }else{

                Node* node = head;               // get node with given index
                for(int i = 0; i < index; i++){
                    node = node -> next;
                }

                addedNode -> previous = node -> previous;
                addedNode -> next = node; 
                node -> previous -> next = addedNode; 
                node -> previous = addedNode;
                len++; 
            }
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

        int getLen(){
            return len;
        }

        void print(){

            cout << "\nPrint result!!!! \n\n";
            
            for(Node* h = head; h != nullptr; h = h -> next){
                cout << h -> key << ":  " << h -> value << endl;
                
            } 

            cout << endl << endl;   
        }

        //------------------functions-----------------

        // function return the pointer of array with all keys
        int* keys(){
            int* arr_of_keys;
            arr_of_keys = new int[len];
            Node* h = head;
            for(int i=0; i<len; i++){
                arr_of_keys[i] = h -> key;
                h = h -> next;
            }
            return arr_of_keys;
        }

        // function return the pointer of array with all values
        int* values(){
            int* arr_of_values;
            arr_of_values = new int[len];
            Node* h = head;
            for(int i=0; i<len; i++){
                arr_of_values[i] = h -> value;
                h = h -> next;
            }
            return arr_of_values;
        }

        //-------------operators-------------

        MyMap& operator=(const MyMap& map){

            Node* h = map.head;
            while (h!=nullptr){
                push_back(h -> key, h -> value);
                h = h -> next;
            }

            return *this;
        }

        bool operator==(MyMap map){
            if(len != map.getLen()){
                return false;
            }

            Node* temp1 = head;
            Node* temp2 = map.head;
            for(int i = 0; i < len; i++){
        
                if(temp1 -> key != temp2 -> key){
                    return false;
                }
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;

            }
            return true;
        }

        int operator[](int k){
            
            if(find(k)){
                return address_of_repeated_key -> value;
            }

            NotFound emap("get operator", "Key is not exist.", "First push this key.", time(0), k);
            throw emap;
            
        }
};

int main(){

    MyMap map;

    try{

        map[2];
        map.pop_back();
        map.pop_front();
        map.insert(2, 20, -5);
        map.insert(2, 20, -5);
        map.insert(2, 20, 5);

    }catch(NotFound emap){
        emap.info();
    }catch(IndexOutOfBounds iexp){
        iexp.info();   
    }catch(exception& ex){
        cout << ex.what();
    }

    return 0;

}