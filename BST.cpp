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

        Node* finded_address = nullptr;
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
                if(temp->left!=nullptr){
                    destructor(temp->left);
                }
                if(temp->right!=nullptr){
                    destructor(temp->right);
                }
                
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

        bool find(int n){
            return find(n, root);
        }

        bool find(int n, Node* temp){
            
            if(temp!=nullptr){
                if(temp -> number == n){
                    finded_address = temp;
                    return true;
                }

                if(n > temp->number){        
                    parent = temp; 
                    return find(n, temp->right);

                }else{
                    parent = temp; 
                    return find(n, temp->left);

                }    
            }else{
                return false;
            }
        }

        // bool find(int n, Node* temp=nullptr){

        //     if(temp == nullptr){
        //         temp = root;
        //     }

        //     if(temp->left != nullptr and temp->right != nullptr){     // stop the recursion function
        //         if(temp -> number == n){
        //             finded_address = temp;
        //             return true;
        //         }

        //         if(n > temp->number){         // checking this condition reduce search in half
        //             return find(n, temp->right);

        //         }else{
        //             return find(n, temp->left);

        //         }
        //     }else{              // check the last row in tree

        //         if(temp->number == n){
        //             finded_address = temp;
        //             return true;
        //         }

        //         return false;   
        //     }   
        // }

        bool del(int x){

            if(find(x)){
                if(finded_address->left==nullptr and finded_address->right==nullptr){
                    delete finded_address; 

                    if(x < parent->number){
                        parent -> left = nullptr;
                    }else{
                        parent -> right = nullptr;
                    }
                    return true;

                }else{
                    Node* child = finded_address->right;
                    if (parent == nullptr){
                        root = parent = child;
                        parent->left = finded_address->left;
                        child = parent->right;
                    }
                    
                    while(child!=nullptr){
                        
                        parent->right = child;
                        parent = child;
                        parent->left = finded_address->left;
                        child = parent->right;
                    } 
                                     
                    delete finded_address;

                    return true;
                }
                
            }
            return false;
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

        bool operator==(Bst second){
            // if(second == this){
            //     return true;
            // }

            return equals(root, second.root);
        }

        bool equals(Node* self, Node* second){


            if (self!=nullptr and second!=nullptr)      // when we have a Node for checking
            {
                if(self->number == second->number){     // when the numbers are equal, continue to check

                    return equals(self->left, second->left);
    
                    return equals(self->right, second->right);

                    
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

    

    Bst bst;

    bst.add(50);
    bst.add(100);
    bst.add(30);
    bst.add(40);
    bst.add(10);
    bst.add(90);
    bst.add(200);

    Bst x(bst);

    cout << "\nbst \n";
    bst.print();

    cout << "\nx \n";
    x.print();

    x = bst;
    cout << "\n= \n";
    x.print();

    Bst y;
    // y=x;
    y.add(50);
    y.add(30);

    // if(x == y){
    //     cout << "\nTrue \n";
    // }else{
    //     cout << "\nFalse \n";
    // }
    // cout << "----------A-Z-----------\n"; 
    // bst.print_AZ();

    // cout << "\n----------Z-A-----------\n"; 
    // bst.print_ZA();

    // bool find = bst.find(205);
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
    bst.del(50);
    // bst.del(40);
    // bst.del(90);
    // bst.del(200);
    // bst.del(30);
    // bst.del(100);


    bst.print();

    return 0;
}


/*
                    50

            30              100

        10     40        90      200

                              150   250  




                               parent->right = child;
                        parent = child;
                        parent->left = finded_address->left;
                        child = parent->right;

*/