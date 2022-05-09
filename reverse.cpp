#include <iostream>
using namespace std;

void reverse(int a[], int i , int j){

    if(i < j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        return reverse(a, i + 1, j - 1);
    }
    
}


void print_result(int a[], int len){
    cout << "print result" << endl;

    for(int i = 0; i < len; i++){
        cout << a[i] << "\t";
    }

    cout << endl << endl;
}


int main(){

    int a[] = {1, 2, 3, 4, 5};

    int first = 0;
    int last = sizeof(a) / sizeof(a[0]);

    reverse(a, first, last - 1);
    print_result(a, last);


    return 0;
}
