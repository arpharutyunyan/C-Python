#include <iostream>
using namespace std;

class Stack{
    private:
        int a[5];
        int index = 0;

    public:
        void push(int n){
            a[index++] = n;
        }

        int pop(){
            return a[--index];
        }

        bool isEmpty(){
            return index <= 0;
        }

        bool isFull(){
            return index == 5;
        }

};

int main(){

    Stack st;
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    cout << "full " << st.isFull() << endl;
    cout << "empty " << st.isEmpty() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << "full " << st.isFull() << endl;
    cout << "empty " << st.isEmpty() << endl;
    
    return 0;
}
