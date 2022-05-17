#include <iostream>
using namespace std;

class Dequeue{
    private:
        int a[5];
        int front = 1;
        int end = 0;
        int index_pop = 0;
        int index_push = 0;

    public:
        void push_front(int n){
            a[--front] = n;
        }

        void push_back(int n){
            a[end++] = n;
        }

        int pop_front(){
            return a[front++];
        }

        int pop_back(){
            return a[end++];
        }

        bool isEmpty(){
            return index_push == 0;
        }

        bool isFull(){
            return index_push == 5;
        }

};

int main(){

    Dequeue dqu;
    cout << "full " << dqu.isFull() << endl;
    cout << "empty " << dqu.isEmpty() << endl;
    // dqu.push(20);
    // dqu.push(30);
    // dqu.push(40);
    // dqu.push(50);
    // dqu.push(60);
    cout << "full " << dqu.isFull() << endl;
    cout << "empty " << dqu.isEmpty() << endl;
    // dqu.pop();
    // dqu.pop();
    // dqu.pop();
    // dqu.pop();
    // dqu.pop();
    cout << "full " << dqu.isFull() << endl;
    cout << "empty " << dqu.isEmpty() << endl;
    
    return 0;
}
