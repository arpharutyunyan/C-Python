#include <iostream>
using namespace std;

class Node{

    public:

        int value = 0;
        int key = 0;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int k, int v){
            key = k;
            value = v;
        }
};


class Bst_map{

    private:
        Node* root = nullptr;

    public:

        Node* parent = nullptr;

        Bst_map(){};

        Bst_map(const Bst_map& copy){

            if(!isEmpty()){
                destructor(root);
            }

            copy_constructor(copy.root);
           
        }

        void copy_constructor(Node* temp){

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

        void destructor(Node* temp){
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

        void add(int k, int v){
            add(k, v, root);
        }

        void add(int k, int v, Node* r){

            if(isEmpty()){
                root = new Node(k, v);
            }else if(k == r->key){
                r->value = v;
                return;
            }else if(k > r->key){
                if(r->right == nullptr){
                    r->right = new Node(k, v);
                    return;
                }
                add(k, v, r->right);
            }else if(k < r->key){
                if(r->left == nullptr){
                    r->left = new Node(k, v);
                    return;
                }
                add(k, v, r->left);
            }
        }

        bool find(int k, bool b){
            if(find(k)!=nullptr){
                return true;
            }else{
                return false;
            }
        }

        Node* find(int k){

            return find(k, root);
        }

        Node* find(int k, Node* temp){
            
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

        void del_leaf(Node* deleted, Node* find=nullptr){

            int k = deleted->key;

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

        void del(int x){

            Node* finded = find(x);

            if(finded==nullptr){
                return;
            }

            if(finded->left!=nullptr){
                Node* temp = finded->left;
                parent = finded;
                while(temp->right!=nullptr){
                    
                    temp = temp->right;
                }

                del_leaf(temp, finded); 

            }else if(finded->right!=nullptr){
                Node* temp = finded->right;
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

        void print(Node* temp){

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

        bool equals(Node* self, Node* second){


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

    Bst_map map;
    map.add(50, 10);
    map.add(60, 20);
    map.add(40, 30);
    map.print();

    Bst_map map2 ;
    map2.add(50, 10);
    map2.add(60, 20);
    map2.add(60, 30);
    if(map == map2){
        cout << "\nTrue \n";
    }else{
        cout << "\nFalse \n";
    }

    map2.print();
    return 0;
}
