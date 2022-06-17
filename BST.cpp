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

class Bst{

    private:
        Node* root = nullptr;

    public:

        Node* parent = nullptr;

        Bst(){};

        Bst(const Bst& copy){

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

        
        ~Bst(){

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
                if(r->right == nullptr){
                    r->right = new Node(x);
                    return;
                }
                add(x, r->right);
            }else if(x < r->number){
                if(r->left == nullptr){
                    r->left = new Node(x);
                    return;
                }
                add(x, r->left);

            }
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

        void del_leaf(Node* leaf){

            if(leaf->number < parent->number){
                    parent->left = nullptr;
                }else{
                    parent->right = nullptr;
                }

                delete leaf;
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

        Bst& operator=(const Bst& copy){

            if(!isEmpty()){
                destructor(root);
            }

            copy_constructor(copy.root);
            return *this;   
        }

        bool operator==(Bst& second){
            if(&second == this){
                return true;
            }

            return equals(root, second.root);
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

        void del(int x){

            Node* finded = find(x);

            if(finded==nullptr){
                return;
            }

            // if(finded->left==nullptr and finded->right==nullptr){

            //     del_leaf(finded);
            //     return;
            // }

            Node* temp = finded;
            bool oneLeaf = false;

            if(parent==nullptr){
                parent=root->right;
                temp = parent->left;
            }

            while (temp!=nullptr){
            
                if(temp->left!=nullptr and temp->right!=nullptr){
                    oneLeaf = false;

                    if(temp->number < parent->number){
                        
                        parent = temp;
                        temp = temp->left;
                        
                    }else{
                       
                        parent = temp;
                        temp = temp->right;
                    }
                }else if(temp->left==nullptr and temp->right==nullptr){

                    if(!oneLeaf){
                        if(temp->number < parent->number){
                            temp = parent->right;
                            if(temp->left!=nullptr or temp->right!=nullptr){
                                parent = temp;
                                temp = temp->left;
                                continue;
                            }
                        }else{
                            temp = parent->left;
                            if(temp->left!=nullptr or temp->right!=nullptr){
                                parent = temp;
                                temp = temp->right;
                                continue;
                            }
                        }
                    }else{
                        if(parent->number < finded->number){
                            if(temp->number < parent->number){   // else temp = temp
                                temp = parent;
                            }
                        }else{
                            if(temp->number > parent->number){   // else temp = temp
                                temp = parent;
                            }
                        }
                    }
                   

                    finded->number = temp->number;
                    del_leaf(temp);

                    return;

                }else{
                    parent = temp;
                    oneLeaf = true;

                    if(temp->left==nullptr){
                       
                        temp = temp->right;
                    }else{

                        temp = temp->left;
                    }
                }
            }
            

        }

/*
                       50
                
            30                    100

     10          40           90           200

 9     15      35   45    70    95    150     250
    11     17                      145     160
*/       
};

int main(){

    

    Bst bst;

    bst.add(50);
    bst.add(100);
    bst.add(30);
    bst.add(40);
    bst.add(10);
    bst.add(90);
    bst.add(200);
    bst.add(9);
    bst.add(15);
    bst.add(35);
    bst.add(45);
    bst.add(70);
    bst.add(95);
    bst.add(150);
    bst.add(250);
    bst.add(145);
    bst.add(160);
    bst.add(11);
    bst.add(17);
    

    // Bst x(bst);

    // cout << "\nbst \n";
    bst.print();

    // cout << "\nx \n";
    // x.print();

    // x = bst;
    // cout << "\n= \n";
    // x.print();

    // Bst y;
    // y=x;
    // y.add(50);
    // y.add(30);
    // y.add(300);

    // if(x == y){
    //     cout << "\nTrue \n";
    // }else{
    //     cout << "\nFalse \n";
    // }
    // cout << "----------A-Z-----------\n"; 
    // bst.print_AZ();

    // cout << "\n----------Z-A-----------\n"; 
    // bst.print_ZA();

    // bool find = bst.find(50);
    // if(find){
    //     cout << "\nTrue \n";
    // }else{
    //     cout << "\nFalse \n";
    // }

    // if(bst.del(40)){
    //     cout << "\nTrue \n";
    // }else{
    //     cout << "\nFalse \n";
    // }

    cout << "\n";
    // bst.del(30);
    // bst.del(40);
    // bst.del(90);
    // bst.del(200);
    // bst.del(30);
    bst.del(50);


    bst.print();

    return 0;
}