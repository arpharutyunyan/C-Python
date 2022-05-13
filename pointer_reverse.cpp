#include <iostream>
using namespace std;

int main(){

    int a[] = {1, 2, 3, 4, 5};
    int len = sizeof(a) / sizeof(a[0]);

    int* p = &a[len - 1]; // a + len

    for(int i = 0; i < len; i++){
        cout << *p-- << endl;
    }


    return 0;
}