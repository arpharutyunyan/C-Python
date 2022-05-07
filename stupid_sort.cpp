#include <iostream>

using namespace std;

void st_sort(int a[], int len){
    int count = 0;

    
    for(int i = 0; i < len - 1 ; i++){
        count ++;
        
        if(a[i] > a[i + 1]){
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
            i = -1;
        }

    }

}

void print_arr(int a[], int len){

    for(int i = 0; i < len; i++){
        cout << a[i] << endl;
    }
    
}

int main()
{
    int a[] = {100, 10, 25, 4, 22, 30, 64};
    int len = sizeof(a)/sizeof(a[0]);
    
    st_sort(a, len);
    print_arr(a, len);
    
    return 0;
}