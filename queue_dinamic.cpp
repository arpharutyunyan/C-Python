#include <iostream>
using namespace std;

class Queue{
    private:
        int* p;
        int len = 5;
        int index_pop = 0;
        int index_push = 0;

    public:
        Queue(){
            p = new int[len];
        }

        void push(int n){
            if(isFull()){
                int* temp = p;
                len *= 2;
                p = new int[len];
                for(int i = 0; i < len / 2; i++){
                    p[i] = temp[i];

                }
            }
            p[index_push++] = n;    
        }

        int pop(){
            int new_index = index_pop++;
            if(index_pop == index_push){
                index_push = 0;
                index_pop = 0;
            }
            
            return p[new_index];
            //return a[new_index];
        }

        bool isEmpty(){
            return index_push == 0;
        }

        bool isFull(){
            return index_push == len;
        }

        int getLen(){
            return len;
        }

};

int main(){

    Queue qu;
    cout << "full " << qu.isFull() << endl;
    cout << "empty " << qu.isEmpty() << endl;
    cout << "len =  " << qu.getLen() << endl;
    
    for(int i = 0; i < 7; i++){
        qu.push(i);
    }
    
    cout << "full " << qu.isFull() << endl;
    cout << "empty " << qu.isEmpty() << endl;
    cout << "len =  " << qu.getLen() << endl;

     for(int i = 0; i < 5; i++){
        cout << "pop " << qu.pop() << endl;
    }
   

    cout << "full " << qu.isFull() << endl;
    cout << "empty " << qu.isEmpty() << endl;
    cout << "len =  " << qu.getLen() << endl;
    
    return 0;
}
