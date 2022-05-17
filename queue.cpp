#include <iostream>
using namespace std;

class Queue{
    private:
        int a[5];
        int index_pop = 0;
        int index_push = 0;

    public:
        void push(int n){
            a[index_push++] = n;
        }

        int pop(){
            int new_index = index_pop++;
            if(index_pop == index_push){
                index_push = 0;
                index_pop = 0;
            }
            
            return a[new_index];
        }

        bool isEmpty(){
            return index_push == 0;
        }

        bool isFull(){
            return index_push == 5;
        }

};

int main(){

    Queue qu;
    cout << "full " << qu.isFull() << endl;
    cout << "empty " << qu.isEmpty() << endl;
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.push(50);
    qu.push(60);
    cout << "full " << qu.isFull() << endl;
    cout << "empty " << qu.isEmpty() << endl;
    qu.pop();
    qu.pop();
    qu.pop();
    qu.pop();
    qu.pop();
    cout << "full " << qu.isFull() << endl;
    cout << "empty " << qu.isEmpty() << endl;
    
    return 0;
}
