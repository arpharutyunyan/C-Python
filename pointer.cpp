#include <iostream>
using namespace std;

void print(int a[], int len){

    cout << "Print function \n";

    int* pa = a;

    for(int i = 0; i < len; i++){

        cout << *pa++ << "\t";

    }

    cout << endl << endl;
}

void odd(int a[], int len){

    cout << "\nPrint odd function \n";
    int sum = 0;

    for(int i = 0; i < len; i++){

        int* num_addr = a + i;
        int odd_num = *num_addr;

        if(odd_num % 2 == 1){
            sum += odd_num;
            cout << odd_num << "\t";
        }
    }
    cout << "\nsum = " << sum;
    cout << endl << endl;
}

void even(int* pa, int len){

    cout << "\nPrint even function \n";
    int sum = 0;

    for(int i = 0; i < len; i++){

        int even_num = *(pa + i);

        if(even_num % 2 == 0){
            sum += even_num;
            cout << even_num << "\t";
        }
    }
    cout << "\nsum = " << sum;
    cout << endl << endl;
}

void reverse_with_2_steps(int* pa, int len){

    cout << "\nPrint reverse_with_2_steps function \n";

    for(int i = len; i > len / 2; i--){

        cout << *(pa + len) << "\t";

        pa -=2;
    }

    cout << endl << endl;
}

int maximum(int* pa, int len){

    int max = *pa;

    for(int i = 0; i < len; i++){

        if(*(pa + i) > max){
            max = *(pa + i);
        }
    }

    return max;
}

int minimum(int* pa, int len){

    int min = *pa;

    for(int i = 0; i < len; i++){

        if(*(pa + i) < min){
            min = *(pa + i);
        }
    }

    return min;
}



int main(){

    int a[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int len = sizeof(a) / sizeof(a[0]);

    print(a, len);
    odd(a, len);
    even(a, len);
    even(&a[0], len);
    reverse_with_2_steps(a, len - 1);

    cout << "\nMax function \nmax = " << maximum(a, len) << endl << endl;
    cout << "\nMin function \nmin = " << minimum(a, len) << endl << endl;

    return 0;
}