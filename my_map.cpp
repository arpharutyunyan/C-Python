#include <iostream>
#include <ctime>
using namespace std;

// template<class I, class S>
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

// template<class I, class S>
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

template<class Key, class Value>
class Node{

    public:
        Value value;
        Key key;
        Node* previous = nullptr;
        Node* next = nullptr;

        Node<Key, Value>(Key k, Value v){
            key = k;
            value = v;
        }
};

// template<class N, class I, class L, class C, class S>
template<class Key, class Value>
class MyMap{

    public:

        Node<Key, Value>* head = nullptr;
        Node<Key, Value>* tail = nullptr;
        int len = 0;

        // int* arr_of_keys = NULL;  // pointer of arrays wich is using in function keys() and contains all keys
        // int* arr_of_values = NULL;   // pointer of arrays wich is using in function vallues() and contains all keys
        Node<Key, Value>* address_of_repeated_key = nullptr;  // initialising in the find() function and save the address of the repeated nodes

        MyMap<Key, Value>(){
            // cout << "Non argument" << endl;
        }

        MyMap<Key, Value>(MyMap& map){

            Node<Key, Value>* h = map.head;
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

        void push_back(Key k, Value v){

            if(isEmpty()){          
                head = tail = new Node<Key, Value>(k, v);         // create the first element
                len++;
            }else if(find(k)){
                address_of_repeated_key -> value = v;    // check if keys repeated, change only the value
            }else{
                Node<Key, Value>* node = new Node<Key, Value>(k, v);
                tail -> next = node;
                node -> previous = tail;
                tail = node;
                len++;
            }   
        }

        Node<Key, Value> pop_back(){

            if(isEmpty()){
                NotFound emap("pop_back", "Map is empty.", "First push anything.", time(0));
                throw emap;
            }
    
            Node<Key, Value> res = *tail;
            // int res_key = tail -> key;  // in all cases return the value of that tail
            len--;

            if(tail == head){     // check the last element
                delete tail;
                tail = head = nullptr;
                
                // return res_key; 
                return res;
            }

            tail = tail -> previous; 
            delete tail -> next;  
            tail -> next = nullptr; 
            
            return res;
        }

        //--------------front--------------------

        void push_front(Key k, Value v){

            if(isEmpty()){                   // create the first element
                head = tail = new Node<Key, Value> (k, v);
                len++;
            }else if(find(k)){
                address_of_repeated_key -> value = v;    // check if keys repeated, change only the value
            }else{
                Node<Key, Value>* node = new Node<Key, Value>(k, v);
                head -> previous = node;
                node -> next = head;
                head = node;
                len++;
            }   
        }

        Node<Key, Value> pop_front(){

            if(isEmpty()){
                NotFound emap("pop_front", "Map is empty.", "First push anything.", time(0));
                throw emap;
            }

            Node<Key, Value> res = *head;
            // int res_key = head -> value;    // in all cases return the value of that head
            len--;

            if(head == tail){   // check the last element
                
                delete head;
                tail = head = nullptr;
                
                return res;
            }

            head = head -> next;  
            delete head -> previous;
            head -> previous = nullptr;
            return res;
        }

        //-----------------insert----------------------

        void insert(Key k, Value v, int index){

            if(find(k)){                   // check if keys repeated, change only the value
                address_of_repeated_key -> value = v;
                return;
            }

            if(index < 0 ){
                // IndexOutOfBounds<I, L, C, S> exp(index, len, "Index is small 0.", "Index must be great than 0.", time(0));

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

            Node<Key, Value>* addedNode = new Node<Key, Value>(k, v);

            if(index == 0){
                push_front(k, v);
            }else if(index == len-1){  // index starts from 0
                push_back(k, v);
            }else{

                Node<Key, Value>* node = head;               // get node with given index
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

        bool find(Key k){

            for(Node<Key, Value>* node = head; node != nullptr; node = node -> next){
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

        // void print(){

        //     cout << "\nPrint result!!!! \n\n";
            
        //     for(auto h = head; h != nullptr; h = h -> next){
        //         cout << h -> key << ":  " << h -> value << endl;
                
        //     } 

        //     cout << endl << endl;   
        // }

        //-------------operators-------------

        MyMap& operator=(const MyMap& map){

            Node<Key, Value>* h = map.head;
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

            auto temp1 = head;
            auto temp2 = map.head;
            for(int i = 0; i < len; i++){
        
                if(temp1 -> key != temp2 -> key){
                    return false;
                }
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;

            }
            return true;
        }

        Node<Key, Value> operator[](Key k){
            
            if(find(k)){
                return *address_of_repeated_key;;
            }

            NotFound emap("get operator", "Key is not exist.", "First push this key.", time(0), k);
            throw emap;
            
        }

        friend ostream& operator<<(ostream& print, const MyMap& map){
            cout << "\n operator << in map class \n\n";
            
            for(auto h = map.head; h != nullptr; h = h -> next){
                cout << h -> key << ":  " << h -> value << endl;
                
            } 

            cout << endl << endl; 
            return print;  
        }
};

int main(){

    MyMap<int, int> map;

    try{
        map.push_back(1, 1);
        map.push_back(2, 2);
        map.push_back(3, 3);
        // Node<int, int> res = map.pop_back();
        // auto res = map.pop_back();
        // cout << res.key << ": " << res.value << endl;
        // Node<int, int> res_front = map.pop_front();
        // auto res = map.pop_back();
        // cout << res_front.key << ": " << res_front.value << "\t";
        // cout << map.pop_back() << "\t";
        // cout << map.pop_back() << "\t";
        // map.find(1);
        // map.print();
        cout << map;

        // cout << map[2].key << ": " << map[2].value;

        // map.insert(5, 5, 0);

        // cout << map;


    }catch(NotFound emap){
        emap.info();
    }catch(IndexOutOfBounds iexp){
        iexp.info();   
    }catch(exception& ex){
        cout << ex.what();
    }

    return 0;

}