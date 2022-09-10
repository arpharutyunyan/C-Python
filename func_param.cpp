#include <iostream>
using namespace std;

void f(int x){
    cout << "first func: x^2 = " << x * x << endl; 
}

void s(int x){
    cout << "second func: x = " << x << endl; 
}

void k(int arr[], int size, void(* func)(int p)){
    for(int i=0; i<size; ++i){
        func(arr[i]);
    }
}

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5};

    k(arr, 6, f);

    cout << "----------------------- \n";

    k(arr, 6, s);

    cout << "----------------------- \n";

    // lambda
    k(arr, 6, [](int x){
        cout << "x^3 = " << x *x * x << endl;
    });
}