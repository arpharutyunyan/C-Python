#include <iostream>
using namespace std;

class Stack{
    private:
        int len = 5;
        int* p;
        int index = 0;

    public:

        Stack(){
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
            p[index++] = n;           
        }

        int pop(){

            return p[--index];

        }

        bool isEmpty(){
            return index <= 0;
        }

        bool isFull(){
            return index == len;
        }

        int getLen(){
            return len;
        }


};

int main(){

    Stack st;
    cout << "full " << st.isFull() << endl;
    cout << "empty " << st.isEmpty() << endl;
    cout << "len =  " << st.getLen() << endl;
    
    for(int i = 0; i < 7; i++){
        st.push(i);
    }
    
    cout << "full " << st.isFull() << endl;
    cout << "empty " << st.isEmpty() << endl;
    cout << "len =  " << st.getLen() << endl;

     for(int i = 0; i < 5; i++){
        cout << "pop " << st.pop() << endl;
    }
   

    cout << "full " << st.isFull() << endl;
    cout << "empty " << st.isEmpty() << endl;
    cout << "len =  " << st.getLen() << endl;
    
    return 0;
}
