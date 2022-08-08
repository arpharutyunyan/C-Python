#include <iostream>
using namespace std;

class Specialist{
    public:
        string name;
        string surname;
        int age;
        int iq;

        Specialist(){};

        Specialist(string name, string surname, int age, int iq){
            this->name = name;
            this->surname = surname;
            this->age = age;
            this->iq = iq;
        }

        void print(){
            cout << "------------------------- \n";
            cout << "name: " << name << endl;
            cout << "surname: " << surname << endl;
            cout << "age: " << age << endl;
            cout << "iq: " << iq << endl;
        }

        friend ostream& operator<<(ostream& print, const Specialist& spec){
            cout << "---------- operator<< ------------- \n";
            print << "name: " << spec.name << endl;
            print << "surname: " << spec.surname << endl;
            print << "age: " << spec.age << endl;
            print << "iq: " << spec.iq << endl;
            return print;
        }
};

template <class T>
class Comparator{
    
    public:
        virtual int compare(T a, T b){
            return -1000;
        };
};

class SortByName : public Comparator<Specialist> {
   
    public:
        int compare(Specialist a, Specialist b){
            if(a.name > b.name){
                return 1;
            }else if(a.name == b.name){
                return 0;
            }else{
                return -1;
            }
        }
};

class SortByAge : public Comparator<Specialist> {
   
    public:
        int compare(Specialist a, Specialist b){
            if(a.age > b.age){
                return 1;
            }else if(a.age == b.age){
                return 0;
            }else{
                return -1;
            }
        }
};

template <class Key, class Value>
class Node{

    public:

        Key key;
        Value value;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(Key k, Value v){
            key = k;
            value = v;
        }
};


template <class Key, class Value>
class Bst_map{

    private:
        Node<Key, Value>* root = nullptr;

    public:

        Node<Key, Value>* parent = nullptr;
        Comparator<Key>* comparator;

        Bst_map(Comparator<Key>* c){
            this->comparator = c;
        };

        Bst_map(const Bst_map& copy){

            if(!isEmpty()){
                destructor(root);
            }

            copy_constructor(copy.root);
           
        }

        void copy_constructor(Node<Key, Value>* temp){

            if(temp!=nullptr){

                add(temp->key, temp->value);
                copy_constructor(temp->left);
                copy_constructor(temp->right);
            }
        }


        ~Bst_map(){

            if(!isEmpty()){
                destructor(root);
            }
                    
        }

        void destructor(Node<Key, Value>* temp){
            if(temp!=nullptr){
               
                
                destructor(temp->left);
                destructor(temp->right);

                delete temp;
            }  
            
            root = nullptr;
        }

        bool isEmpty(){
            return root == nullptr;
        }

        void add(Key k, Value v){
            add(k, v, root);
        }

        void add(Key k, Value v, Node<Key, Value>* r){

            if(isEmpty()){
                root = new Node<Key, Value>(k, v);
            }else if(comparator->compare(k, r->key) == 0){
                r->value = v;
                return;
            }else if(comparator->compare(k, r->key) == 1){
                if(r->right == nullptr){
                    r->right = new Node<Key, Value>(k, v);
                    return;
                }
                add(k, v, r->right);
            }else if(comparator->compare(k, r->key) == -1){
                if(r->left == nullptr){
                    r->left = new Node<Key, Value>(k, v);
                    return;
                }
                add(k, v, r->left);
            }
        }

        bool find(Key k, bool b){
            if(find(k)!=nullptr){
                return true;
            }else{
                return false;
            }
        }

        Node<Key, Value>* find(Key k){

            return find(k, root);
        }

        Node<Key, Value>* find(Key k, Node<Key, Value>* temp){
            
            if(temp!=nullptr){
                if(comparator->compare(temp -> key, k) == 0){
                    return temp;
                }

                if(comparator->compare(k, temp->key) == 1){ 
                    parent = temp; 
                    return find(k, temp->right);

                }else{
                    parent = temp; 
                    return find(k, temp->left);
                }    
            }else{
                return nullptr;
            }
        }

        void del_leaf(Node<Key, Value>* deleted, Node<Key, Value>* find=nullptr){

            Key k = deleted->key;

            if(comparator->compare(deleted->key, parent->key) == -1){
                //deleted->key < parent->key){
                    parent->left = nullptr;
            }else{
                parent->right = nullptr;
            }

            if(find){
                find->key = k;  // then the deleted is leaf give argument only deleted 
            }
            
            delete deleted;
        }   

        void del(Key x){

            Node<Key, Value>* finded = find(x);

            if(finded==nullptr){
                return;
            }

            if(finded->left!=nullptr){
                Node<Key, Value>* temp = finded->left;
                parent = finded;
                while(temp->right!=nullptr){
                    
                    temp = temp->right;
                }

                del_leaf(temp, finded); 

            }else if(finded->right!=nullptr){
                Node<Key, Value>* temp = finded->right;
                parent = finded;
                while(temp->left!=nullptr){
                    temp = temp->left;
                }

                del_leaf(temp, finded);
                
            }else if(finded->left==nullptr and finded->right==nullptr){
                if(finded != root){
                    del_leaf(finded);
                }else{
                    delete root;
                }   
            }
        }

        void print(){        
            print(root);
        }

        void print(Node<Key, Value>* temp){

            if(isEmpty()){
                cout << "Is empty! Nothing to print\n";
                return;
            }

            if(temp != nullptr){

                cout << temp -> key << " : " << temp->value << "\n";  // print the sequence of function calls
                print(temp->left);
                print(temp->right);
            }
        }

        friend ostream& operator<<(ostream& print_op, const Bst_map& obj){
            cout << "\n operator << in bst_map class \n\n";
            
            print(obj.root);   //?????????????????

            return print_op;
            
        }

        friend std::istream& operator>>(std::istream& input, Bst_map& obj){
            std::cout << "-------------- operator>> ----------------- \n";

            return input;
        }

        Bst_map& operator=(const Bst_map& copy){

            if(!isEmpty()){
                destructor(root);
            }

            copy_constructor(copy.root);
            return *this;   
        }

        bool operator==(Bst_map& second){
            if(&second == this){
                return true;
            }

            return equals(root, second.root);
        }

        bool operator!=(Bst_map& second){
            if(this == &second){
                return false;
            } 

            return !equals(root, second.root);
        }

        bool equals(Node<Key, Value>* self, Node<Key, Value>* second){


            if (self!=nullptr and second!=nullptr)      // when we have a Node for checking
            {
                if((comparator->compare(self->key, second->key) == 0) and (comparator->compare(self->value, second->value))){
                    //(self->key == second->key) and (self->value == second->value)){     // when the numbers are equal, continue to check

                    bool left = equals(self->left, second->left);
    
                    bool right = equals(self->right, second->right);

                    return left and right; 

                }else{
                    return false;    // if the numbers not equal return false
                } 

            }else if (self==nullptr and second==nullptr){   // when we don't have Node for checking and not breaking the function with false
                return true;                                                                
            }else{
                return false;     // when the self = nullptr or second = nullptr
            }
           
        }
};

int main(){

    SortByName  sn;
    SortByAge sa;

    Bst_map<Specialist, int> map(&sn);

    map.add(Specialist("A", "AA", 25, 100), 25);
    map.add(Specialist("C", "CC", 70, 50), 70);
    map.add(Specialist("F", "FF", 21, 97), 21);
    map.add(Specialist("D", "DD", 32, 65), 32);
    map.add(Specialist("Z", "ZZ", 12, 100), 12);
    map.add(Specialist("BB", "BB", 25, 100), 25);
    map.add(Specialist("B", "BBB", 50, 100), 50);
    map.add(Specialist("B", "BBBB", 150, 100), 150);

    cout<<map;

    // map.print();

    // cout << "-----------find--------------- \n\n";
    // cout << map.find(Specialist("Z", "ZZ", 12, 100))->value << endl;
    // cout << map.find(Specialist("D", "DD", 32, 65))->value << endl;
    // cout << map.find(Specialist("BB", "BB", 25, 100))->value << endl;
    // cout << map.find(Specialist("B", "BBBB", 150, 100))->value << endl;

    // cout << "------- end find----------- \n\n\n";

    return 0;
}
