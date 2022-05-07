#include <iostream>

using namespace std;

void shaker_sort(int a[], int len){

    bool b = true;
    int count_while = 0;
    int count = 0;
    
    while(b){
        
        b = false;
    
        for(int j = 0; j < len - 1 - count_while; j++){
            
            count ++;
            
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                b = true;
            } 
   
        }
        
        count_while++;
    }
}


void print_arr(int a[], int len){

    for(int i = 0; i < len; i++){
        cout << a[i] << endl;
    }
}

int main()
{
    int a[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};

    int len = sizeof(a)/sizeof(a[0]);

    shaker_sort(a, len);
    print_arr(a, len);


    return 0;
}