#include <iostream>
using namespace std;

class Deque{
    private:
        int* p;
        int len = 5;
        int front = -1;
        int end = -1;

    public:

        Deque(){
            p = new int[len];
        }

        bool isEmpty(){
            return front == -1 and end == -1;
        }

        bool isFull(){
            // the array fill from front 0 index to 4 (front = 0 and end = 4)   or
            // if pop from front for ex. the front = 3
            // from back if the end + 1 = 5 the end will be = 0, me must fill array untill end = front - 1
            return end - front == len - 1 or end == front - 1;
        }

        void push_front(int n){
            if(isFull()){
                cout << "Deque is full \n";
                int* temp = p;
                len *= 2;
                p = new int[len];
                for(int i = 0; i < len / 2; i++){
                    p[len / 2 + i ] = temp[i];

                }
                front = len / 2; // array added front the base array, thats why var front = len / 2

            }else if(front == -1){  // if the first element: index = 0
                front = end = 0;
            }else if (front == 0){  // if index = 0 the front index = -1: for avoiding <index out bound of range> index = 4
                front = len - 1;
            }else{
                --front;
            }

            p[front] = n;
        }

        void push_back(int n){
            if(isFull()){
                int* temp = p;
                len *= 2;
                p = new int[len];
                for(int i = 0; i < len / 2; i++){
                    p[i] = temp[i];

                }
                end++;
            }else if(end == -1){
                front = end = 0;
            }else{
                end++;
            }
            p[end] = n;
        }

        int pop_front(){
            if(isEmpty()){
                cout << "deque is empty \n";
                return -1;  // don't affect on anything
            }else if(front == end){
                front = end = -1;  // if the first elemet in array
                return p[front + 1]; // + 1 for not changing the front index
            }else if(front == len - 1){
                front = 0;            // if index = 4 the front index = 5
                return p[front + len - 1];  // return the last element, plus 4 because in line above the front = 0
            }
            return p[front++];
        }
        
        int pop_back(){
            if(isEmpty()){
                return -1;
                cout << "deque is empty \n";
            }else if(front == end){
                front = end = -1; 
                return p[end + 1];  
            }else if(end == 0){
                end = len - 1;            // if index = 0 the front index = -1
                return p[end - (len - 1)];  // return the first element, minus 4 because in line above the end = 4
            }
            return p[end--];
        }

        int getLen(){
            return len;
        }
};


int main(){

    Deque dqu;
    cout << "full " << dqu.isFull() << endl;
    cout << "empty " << dqu.isEmpty() << endl;
    cout << "len =  " << dqu.getLen() << endl;
    
    for(int i = 0; i < 8; i++){
        dqu.push_front(i);
        //dqu.push_back(i);
    }
    
    cout << "full " << dqu.isFull() << endl;
    cout << "empty " << dqu.isEmpty() << endl;
    cout << "len =  " << dqu.getLen() << endl;

     for(int i = 0; i < 5; i++){
        cout << "pop = " << dqu.pop_front() << endl;
        //cout << "pop = " << dqu.pop_back() << endl;

    }
   
    cout << "full " << dqu.isFull() << endl;
    cout << "empty " << dqu.isEmpty() << endl;
    cout << "len =  " << dqu.getLen() << endl;
    
    return 0;
}