#include <iostream>
using namespace std;

void swaping(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    int a = 20;
    int b = 50;

    swaping(&a, &b);
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;


    return 0;
}