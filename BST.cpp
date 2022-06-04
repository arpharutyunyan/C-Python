#include <iostream>
using namespace std;

class Node{

    public:

    int number;
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

        bool isEmpty(){
            return root == nullptr;
        }

        void add(int x){
            addRec(x, root);
        }

        void addRec(int x, Node* r){
            if(isEmpty()){
                root = new Node(x);
            }else if(x > r -> number){
                if(r->right == nullptr){
                    r->right = new Node(x);
                    return;
                }
                addRec(x, r -> right);
            }else if(x < r -> number){
                if(r->left == nullptr){
                    r->left = new Node(x);
                    return;
                }
                addRec(x, r-> left);

            }
        }

};

int main(){

    Bst bst;

    bst.add(5);
    bst.add(10);
    bst.add(1);



    return 0;
}