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

        void print(Node* temp=nullptr, Node* left=nullptr, Node* right=nullptr){

            if(isEmpty()){
                cout << "Is empty! Nothing to print\n";
                return;
            }

            if(temp == nullptr){            // first initialize for root
                temp = left = right = root;
                cout << left->number << "\t";
                return print(temp, left->left, right->right);
            }

            if(left == nullptr and right == nullptr){   // stop the recursion function
                return;
            }

            if(left != nullptr){
                cout << left->number << "\t";
                left = left->left;
            }
            if(right!=nullptr){
                cout << right->number << "\t";
                right = right->right;
            }
                
                
            return print(temp, left, right);
            
        }


};

int main(){

    Bst bst;

    bst.add(50);
    bst.add(100);
    bst.add(30);
    bst.add(10);
    bst.add(20);
    bst.add(90);
    bst.add(200);
    bst.add(220);

    // bst.print_with_queue();
    bst.print();

    return 0;
}


/*
                    50

            30              100

        10               90      200

            20                         220

*/