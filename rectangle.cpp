#include <iostream>

using namespace std;

class Rectangle{

    public:
        float width;
        float length;

        Rectangle(){};

        Rectangle(float length, float width){
            this->length = length;
            this->width = width;
        }

        float area(){
            return this->length * this->width;
        }

        float perimeter(){
            return 2 * (this->length + this->width);
        }

        friend ostream& operator<<(ostream& print, Rectangle& rec){
            cout << "------- print in rectangle class -------- \n";
            cout << "width = " << rec.width << endl;
            cout << "length = " << rec.length << endl;
            cout << "are = " << rec.area() << endl;
            cout << "perimeter = " << rec.perimeter() << endl;

            return print;
        }

};

template <class C>
class Comparator{

    public:
        virtual int compare(C a, C b){
            return -1000;
        }
};

class SortByWidth : public Comparator<Rectangle>{
    public:

        int compare(Rectangle a, Rectangle b){
            if(a.width > b.width){
                return 1;
            }else if(a.width == b.width){
                return 0;
            }else{
                return -1;
            }
        }
};

class SortByLength : public Comparator<Rectangle>{
    public:

        int compare(Rectangle a, Rectangle b){
            if(a.length > b.length){
                return 1;
            }else if(a.length < b.length){
                return -1;
            }else{
                return 0;
            }
        }
};

class SortByArea : public Comparator<Rectangle>{
    public:

        int compare(Rectangle a, Rectangle b){
            if(a.area() > b.area()){
                return 1;
            }else if(a.area() < b.area()){
                return -1;
            }else{
                return 0;
            }
        }
};

class SortByPerimeter : public Comparator<Rectangle>{
    public:

        int compare(Rectangle a, Rectangle b){
            if(a.perimeter() > b.perimeter()){
                return 1;
            }else if(a.perimeter() < b.perimeter()){
                return -1;
            }else{
                return 0;
            }
        }
};

// template <class T>
// class Node{

//     public:

//     T number;
//     Node<T>* left = nullptr;
//     Node<T>* right = nullptr;

//     Node<T>(T n){
//         number = n;
//     }
// };

// template <class T>
// class Bst{

//     private:
//         Node<T>* root = nullptr;

//     public:

//         Node<T>* parent = nullptr;
//         Comparator<T>* comparator;

//         Bst<T>(Comparator<T>* c){
//             this->comparator = c;
//         };

//         Bst<T>(const Bst& copy){

//             if(!isEmpty()){
//                 destructor(root);
//             }

//             copy_constructor(copy.root);
           
//         }

//         void copy_constructor(Node<T>* temp){

//             if(temp!=nullptr){

//                 add(temp->number);
//                 copy_constructor(temp->left);
//                 copy_constructor(temp->right);
//             }
//         }

//         Bst(Bst&& second){

//             this->root = second.root;
//             second.root = nullptr;
            
//         }

        
//         ~Bst(){

//             if(!isEmpty()){
//                 destructor(root);
//             }
                  
//         }

//         void destructor(Node<T>* temp){
//             if(temp!=nullptr){
               
                
//                 destructor(temp->left);
//                 destructor(temp->right);

//                 delete temp;
//             }  
            
//             root = nullptr;
//         }

//         bool isEmpty(){
//             return root == nullptr;
//         }

//         void add(T x){
//             add(x, root);
//         }

//         void add(T x, Node<T>* r){
//             if(isEmpty()){
//                 root = new Node<T>(x);
//             }else if(comparator->compare(x, r->number) == 1){
//                 if(r->right == nullptr){
//                     r->right = new Node<T>(x);
//                     return;
//                 }
//                 add(x, r->right);
//             }else if(comparator->compare(x, r->number) == -1){
//                 if(r->left == nullptr){
//                     r->left = new Node<T>(x);
//                     return;
//                 }
//                 add(x, r->left);

//             }
//         }

//         bool find(T n, bool b){
//             if(find(n)!=nullptr){
//                 return true;
//             }else{
//                 return false;
//             }
//         }

//         Node<T>* find(T n){

//             return find(n, root);
//         }

//         Node<T>* find(T n, Node<T>* temp){
            
//             if(temp!=nullptr){
//                 if(comparator->compare(temp -> number, n) == 0){
//                     return temp;
//                 }

//                 if(comparator->compare(n, temp->number) == 1){ 
//                     parent = temp;       
//                     return find(n, temp->right);

//                 }else{
//                     parent = temp; 
//                     return find(n, temp->left);
//                 }    
//             }else{
//                 return nullptr;
//             }
//         }

//         void del_leaf(Node<T>* deleted, Node<T>* find=nullptr){

//             T num = deleted->number;

//             if(comparator->compare(deleted->number, parent->number) == -1){
//                     parent->left = nullptr;
//             }else{
//                 parent->right = nullptr;
//             }

//             if(find){
//                 find->number = num;  // then the deleted is leaf give argument only deleted 
//             }
            
//             delete deleted;
//         }   

//         void del(T x){

//             Node<T>* finded = find(x);

//             if(finded==nullptr){
//                 return;
//             }

//             if(finded->left!=nullptr){
//                 Node<T>* temp = finded->left;
//                 parent = finded;
//                 while(temp->right!=nullptr){
                    
//                     temp = temp->right;
//                 }

//                 del_leaf(temp, finded); 

//             }else if(finded->right!=nullptr){
//                 Node<T>* temp = finded->right;
//                 parent = finded;
//                 while(temp->left!=nullptr){
//                     temp = temp->left;
//                 }

//                 del_leaf(temp, finded);
                
//             }else if(finded->left==nullptr and finded->right==nullptr){
//                 if(finded != root){
//                     del_leaf(finded);
//                 }else{
//                     delete root;
//                 }   
//             }
//         }

//         void print(){        
//             print(root);
//         }

//         void print(Node<T>* temp){

//             if(isEmpty()){
//                 cout << "Is empty! Nothing to print\n";
//                 return;
//             }

//             if(temp != nullptr){

//                 print(temp->left);
//                 cout << temp -> number << "\t";  // print the sequence of function calls
//                 print(temp->right);
//             }
//         }
// };

// int main(){

    // SortByWidth width;
    // SortByLength length;
    // SortByArea area;
    // SortByPerimeter perimeter;

    // Bst<Rectangle> bst(&area);
    // bst.add(Rectangle(10, 100));
    // bst.add(Rectangle(30, 500));
    // bst.add(Rectangle(20, 200));
    // bst.add(Rectangle(50, 550));
    // bst.add(Rectangle(35, 350));
    // bst.add(Rectangle(10, 80));
    // bst.add(Rectangle(6, 50));
    // bst.add(Rectangle(150, 230));
    // bst.add(Rectangle(75, 400));
    // bst.add(Rectangle(205, 45));

    // cout << "-----------find--------------- \n\n";
    // cout << bst.find(Rectangle(10, 80))->number;

    // cout << "------- end find----------- \n\n\n";
    // bst.print();

    // bst.del(Rectangle(6, 50));
    
    // cout << "---------del----------\n\n";
    // bst.print();








//     return 0;
// }