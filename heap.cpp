#include <iostream>
using namespace std;

class Node{

    public:

    int number = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int n){
        number = n;
    }
};

class Heap{

    private:
        Node* root = nullptr;

    public:

        Node* parent = nullptr;

        Heap(){};

        Heap(const Heap& copy){

            if(!isEmpty()){
                destructor(root);
            }

            copy_constructor(copy.root);
           
        }

        void copy_constructor(Node* temp){

            if(temp!=nullptr){

                add(temp->number);
                copy_constructor(temp->left);
                copy_constructor(temp->right);
            }
        }

        Heap(Heap&& second){

            this->root = second.root;
            second.root = nullptr;
            
        }

        
        ~Heap(){

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

        void add(int x){
            add(x, root);
        }

        void add(int x, Node* r){
            if(isEmpty()){
                root = new Node(x);
            }else if(x > r->number){
                if()
            }
            
            
            
            
            
            
            
            
            
            // else if(x > r->number){
            //     if(r->right == nullptr){
            //         r->right = new Node(x);
            //         return;
            //     }
            //     add(x, r->right);
            // }else if(x < r->number){
            //     if(r->left == nullptr){
            //         r->left = new Node(x);
            //         return;
            //     }
            //     add(x, r->left);

            // }
        }

        bool find(int n, bool b){
            if(find(n)!=nullptr){
                return true;
            }else{
                return false;
            }
        }

        Node* find(int n){

            return find(n, root);
        }

        Node* find(int n, Node* temp){
            
            if(temp!=nullptr){
                if(temp -> number == n){
                    return temp;
                }

                if(n > temp->number){ 
                    parent = temp;       
                    return find(n, temp->right);

                }else{
                    parent = temp; 
                    return find(n, temp->left);
                }    
            }else{
                return nullptr;
            }
        }

        void del_leaf(Node* deleted, Node* find=nullptr){

            int num = deleted->number;

            if(deleted->number < parent->number){
                    parent->left = nullptr;
            }else{
                parent->right = nullptr;
            }

            if(find){
                find->number = num;  // then the deleted is leaf give argument only deleted 
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

        // ____________  print  ________________

        void print(){        
            print(root);
        }

        void print(Node* temp){

            if(isEmpty()){
                cout << "Is empty! Nothing to print\n";
                return;
            }

            if(temp != nullptr){

                cout << temp -> number << "\t";  // print the sequence of function calls
                print(temp->left);
                print(temp->right);
            }
        }

        void print_AZ(Node* temp = nullptr){

            if(isEmpty()){
                cout << "Is empty! Nothing to print\n";
                return;
            }

            if(temp == nullptr){            // first initialize for root
                temp = root;
            }

            if(temp->left == nullptr and temp->right == nullptr){   // stop the recursion function
                cout << temp -> number << "\t";  
            }else{
                print_AZ(temp -> left);
                cout << temp -> number << "\t";
                print_AZ(temp -> right);
            }
        }

        void print_ZA(Node* temp = nullptr){

            if(isEmpty()){
                cout << "Is empty! Nothing to print\n";
                return;
            }

            if(temp == nullptr){            // first initialize for root
                temp = root;
            }

            if(temp->left == nullptr and temp->right == nullptr){   // stop the recursion function
                cout << temp -> number << "\t";  
            }else{
                print_ZA(temp->right);
                cout << temp -> number << "\t";  
                print_ZA(temp->left); 

            }           
        }


        //___________________ operators ________________

        Heap& operator=(const Heap& copy){

            if(!isEmpty()){
                destructor(root);
            }

            copy_constructor(copy.root);
            return *this;   
        }

        bool operator==(Heap& second){
            if(&second == this){
                return true;
            }

            return equals(root, second.root);
        }

        bool operator!=(Heap& second){
            if(this == &second){
                return false;
            } 

            return !equals(root, second.root);

        }

        bool equals(Node* self, Node* second){


            if (self!=nullptr and second!=nullptr)      // when we have a Node for checking
            {
                if(self->number == second->number){     // when the numbers are equal, continue to check

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

    Heap h;

    h.add(50);
    h.add(100);
    h.add(30);
    h.add(40);
    h.add(10);
    h.add(90);
    h.add(200);
    h.add(9);
    h.add(15);
    h.add(35);
    h.add(45);
    h.add(70);
    h.add(95);
    h.add(150);
    h.add(250);
    h.add(145);
    h.add(160);
    h.add(11);
    h.add(16);


    return 0;
}
                   