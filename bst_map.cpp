#include <iostream>
using namespace std;

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

        Bst_map(){};

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
            }else if(k == r->key){
                r->value = v;
                return;
            }else if(k > r->key){
                if(r->right == nullptr){
                    r->right = new Node<Key, Value>(k, v);
                    return;
                }
                add(k, v, r->right);
            }else if(k < r->key){
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
                if(temp -> key == k){
                    return temp;
                }

                if(k > temp->key){ 
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

            if(deleted->key < parent->key){
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
                if((self->key == second->key) and (self->value == second->value)){     // when the numbers are equal, continue to check

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

    Bst_map<int, string> map;
    map.add(50, "aa");
    map.add(60, "bb");
    map.add(97, "cc");
    map.add(97, "cc");
    map.add(60, "cc");
    map.add(25, "cc");
    map.add(200, "cc");
    map.add(700, "cc");
    map.del(20);
    map.del(60);
    map.del(50);
    map.print();

    // Bst_map<int, int> map2 ;
    // map2.add(50, 10);
    // map2.add(60, 20);
    // map2.add(60, 30);
    // if(map == map2){
    //     cout << "\nTrue \n";
    // }else{
    //     cout << "\nFalse \n";
    // }

    // map2.print();
    return 0;
}
