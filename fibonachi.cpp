#include <iostream>
using namespace std;

int fib(int n){

    if(n == 1 or n == 2){
        return 1;
    }else{
        return (fib(n - 1) + fib(n - 2));
    }

}

int main(){

    int number = 0;

    cout << "Enter the number: ";
    cin >> number;

    for(int i = 1; i <= number; i++){
        cout << fib(i) << "\t";
        float golden_ratio = (float)fib(i + 1) / fib(i);
        cout << golden_ratio << endl;

    }

    cout << endl;

    return 0;
}
