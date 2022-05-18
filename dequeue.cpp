#include <iostream>
using namespace std;

class Dequeue{
    private:
        int a[5];
        int front = 0;
        int end = 0;

    public:

    //---------LIFO-------------
        void push_front(int n){
            // if(front >= 0 and front < 5){
            //     // a[front++] = n;
            //     a[++front] = n;
            // }

            a[front++] = n;
        }

        int pop_front(){
            // if(front >= 0 and front < 5){
            //     //a[front++] = n;
            // }
            return a[--front];
        }

        int pop_back(){
            // if(end < 0 and end > 5){
            //     return;
            // } 
            return a[--end];
        }

        

    //-------------FIFO--------------
        void push_back(int n){
            // if(end >= 0 and end < 5){
            //     a[end++] = n;
            // }
            a[end++] = n;
        }

    
        bool isEmpty(){
            return front == 0 and end == 0;
        }

        bool isFull(){
            return front > 0 or end > 0;
        }

};

int main(){

    Dequeue dqu;
    cout << "full " << dqu.isFull() << endl;
    cout << "empty " << dqu.isEmpty() << endl;
    // dqu.push_front(20);
    // dqu.push_front(30);
    // dqu.push_front(20);
    // dqu.push_front(30);
    // dqu.push_front(20);
    dqu.push_back(40);
    dqu.push_back(50);
    dqu.push_back(40);
    dqu.push_back(50);
    dqu.push_back(40);
    cout << "full " << dqu.isFull() << endl;
    cout << "empty " << dqu.isEmpty() << endl;
    // dqu.pop_front();
    // dqu.pop_front();
    // dqu.pop_front();
    // dqu.pop_front();
    // dqu.pop_front();
    dqu.pop_back();
    dqu.pop_back();
    dqu.pop_back();
    dqu.pop_back();
    dqu.pop_back();
    cout << "full " << dqu.isFull() << endl;
    cout << "empty " << dqu.isEmpty() << endl;
    
    return 0;
}
