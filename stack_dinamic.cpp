#include <iostream>
using namespace std;

class Stack{
    private:
        int len = 5;
        int* p;
        int index = 0;  // show in which element function stop

    public:

        Stack(){
            p = new int[len];
            
        }

        ~Stack(){
            delete[] p;
        }

        void push(int n){
            if(isFull()){  // if the array is full, add more length 
                int* temp = p;
                len *= 2;
                p = new int[len];
                for(int i = 0; i < len / 2; i++){
                    p[i] = temp[i];

                }
                delete[] temp;  // delete the temp pointer is clear the all memory
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
    
    for(int i = 0; i < 100; i++){   // to fill array   len = 5
        st.push(i);
    }
    
    cout << "full " << st.isFull() << endl;
    cout << "empty " << st.isEmpty() << endl;
    cout << "len =  " << st.getLen() << endl;

    for(int i = 0; i < 1; i++){
        cout << "pop " << st.pop() << endl;
    }
   

    cout << "full " << st.isFull() << endl;
    cout << "empty " << st.isEmpty() << endl;
    cout << "len =  " << st.getLen() << endl;
    
    return 0;
}
