#include <iostream>
using namespace std;

void print(int* pa, int len);


void st_sort(int* pa, int len){

    cout << "stupid sort" << endl;

    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - 1; j++){
            int* a = pa + j;
            int* b = pa + j + 1;

            if(*a > *b){
                // cout << "a " << a << "=" << *a << endl;
                // cout << "b " << b << "=" << *b << endl;
                // cout << "-------------------------" << endl;
                int temp = *a;
                *a = *b;
                *b = temp;
                // cout << "a " << a << "=" << *a << endl;
                // cout << "b " << b << "=" << *b << endl;
                // cout << "++++++++++++++++++++++++++" << endl;
            }
        }
    }

    print(pa, len);

}

void bubble_sort(int* pa, int len){
    cout << "bubble" << endl;

    for(int i = len - 1; i >= 0; i--){
        for(int j = i - 1; j >= 0; j--){
           
            int* a = pa + j;
            int* b = pa + i;
            if(*a < *b){
                int temp = *a;
                *a = *b;
                *b = temp;
            }
        }
    }

    print(pa, len);
}

void shaker_sort(int* pa, int len){

    cout << "Shaker sort" << endl;

    for(int i = 0; i < len; i++){
        for(int j = 0; j < len - i; j++){
           
            int* a = pa + j;
            int* b = pa + j + 1;
            if(*a > *b){
                int temp = *a;
                *a = *b;
                *b = temp;
            }
        }
    }

    print(pa, len);
}


void print(int* pa, int len){

    for(int i = 0; i < len; i++){
        cout << *pa++ << "\t";
    }

    cout << endl << endl;
}


int main(){

    int a[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    int len = sizeof(a) / sizeof(a[0]);
    cout << "Initial array" << endl;
    print(a, len);

    st_sort(a, len);

    bubble_sort(a, len);

    shaker_sort(a, len);


    return 0;
}