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

        int len = 0;

        ~Bst(){

            del(root);

        }

        void del(Node* temp){
            if(temp!=nullptr){
                del(temp->left);
                del(temp->right);
            }  

            delete temp;
        }

        bool isEmpty(){
            return root == nullptr;
        }

        void add(int x){
            addRec(x, root);
            ++len;
        }

        void addRec(int x, Node* r){
            if(isEmpty()){
                root = new Node(x);
            }else if(x > r->number){
                if(r->right == nullptr){
                    r->right = new Node(x);
                    return;
                }
                addRec(x, r->right);
            }else if(x < r->number){
                if(r->left == nullptr){
                    r->left = new Node(x);
                    return;
                }
                addRec(x, r->left);

            }
        }


        bool find(int n, Node* temp=nullptr){

            if(temp == nullptr){
                temp = root;
            }


            if(temp->left != nullptr and temp->right != nullptr){     // stop the recursion function
                if(temp -> number == n){
                    return true;
                }

                if(n > temp->number){         // checking this condition reduce search in half
                    find(n, temp->right);
                }else{
                    find(n, temp->left);


                }
            }else{
               return temp->number == n;   // check the last row in tree
            }   

        }

        // ____________  print  ________________


        // this finction create the array with nodes
        // first add  root, then ...
        // choose the element from array using variable index_pop,(the first time it will be root)
        // check if that have right or left node and push(add) in the array with variable index_push
        void print_with_queue(){

            if(isEmpty()){
                cout << "Is empty! Nothing to print\n";
                return;
            }
            
            Node* queue[len];   
            int index_push = 0;  
            int index_pop = 0; 

            Node* temp = root;
            queue[index_pop++] = temp;  // fill the first element(root) in the array
            cout << temp->number << "\t";

            while(index_pop!=len){   //the loop is stoped when the all elements will be checked 
               
                if(temp->left != nullptr){
                    queue[++index_push] = temp->left;
                }
                if(temp->right != nullptr){
                    queue[++index_push] = temp->right;
                }
                
                
                temp = queue[index_pop++];
                cout << temp->number << "\t";
            }
        }

        void print(Node* temp = nullptr){

            if(isEmpty()){
                cout << "Is empty! Nothing to print\n";
                return;
            }

            if(temp == nullptr){            // first initialize for root
                temp = root;
                cout << temp->number << "\t";
            }

            if(temp->left == nullptr and temp->right == nullptr){   // stop the recursion function
                return;
            }


            if(temp->left!=nullptr){
                cout << temp->left -> number << "\t";
                print(temp->left);
            }
            if(temp->right!=nullptr){
                
                cout << temp->right -> number << "\t";
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

    // bst.print_with_queue();
    // bst.print();

    // cout << "----------A-Z-----------\n"; 
    // bst.print_AZ();

    // cout << "\n----------Z-A-----------\n"; 
    // bst.print_ZA();

    bool find = bst.find(10);
    if(find){
        cout << "True \n";
    }else{
        cout << "False \n";
    }

    return 0;
}


/*
                    50

            30              100

        10     40        90      200

*/