#include <iostream>
using namespace std;

/*
    LIFO    push_front  ->  pop_front
            push_back   ->  pop_back

    FIFO    push_back   ->  pop_front
*/


class Dequeue{
    private:
        int a[5];
        int front = -1;
        int end = -1;

    public:

        bool isEmpty(){
            return front == -1 ;
        }

        bool isFull(){
            // the array fill from front 0 index to 4 (front = 0 and end = 4)   or
            // if pop from front for ex. the front = 3
            // from back if the end + 1 = 5 the end will be = 0, me must fill array untill end = front - 1
            return end - front == 4 or end == front - 1;
        }

        void push_front(int n){
            if(isFull()){
                cout << "Deque is full \n";
                return;
            }else if(front == -1){  // if the first element: index = 0
                front = end = 0;
            }else if (front == 0){  // if index = 0 the front index = -1: for avoiding <index out bound of range> index = 4
                front = 4;
            }else{
                --front;
            }

            a[front] = n;
            //cout << a[front] << endl;
        }

        void push_back(int n){
            if(isFull()){
                cout << "Deque is full \n";
                return;
            }else if(end == -1){
                front = end = 0;
            }else if (end == 4){ // if index = 4 the after index = 5
                end == 0;
            }else{
                end++;
            }

            a[end] = n;
            //cout << a[end] << endl;
        }

        int pop_front(){
            if(isEmpty()){
                cout << "deque is empty \n";
                return -1;  // don't affect on anything
            }else if(front == end){
                front = end = -1;  // if the first elemet in array
                return a[front + 1]; // + 1 for not changing the front index
            }else if(front == 4){
                front = 0;            // if index = 4 the front index = 5
                return a[front + 4];  // return the last element, plus 4 because in line above the front = 0
            }
            return a[front++];
        }
        
        int pop_back(){
            if(isEmpty()){
                cout << "deque is empty \n";
                return -1;
            }else if(front == end){
                front = end = -1;  
                return a[end + 1]; 
            }else if(end == 0){
                end = 4;            // if index = 0 the front index = -1
                return a[end - 4];  // return the first element, minus 4 because in line above the end = 4
            }
            return a[end--];
        }
};


int main(){

    Dequeue dqu;
    cout << "full " << dqu.isFull() << endl;
    cout << "empty " << dqu.isEmpty() << endl;
    
    for(int i = 0; i < 5; i++){
        dqu.push_front(i);
        //dqu.push_back(i);
    }
    
    cout << "full " << dqu.isFull() << endl;
    cout << "empty " << dqu.isEmpty() << endl;

     for(int i = 0; i < 5; i++){
        dqu.pop_front();
        //dqu.pop_back();
    }
   
    cout << "full " << dqu.isFull() << endl;
    cout << "empty " << dqu.isEmpty() << endl;
    
    return 0;
}