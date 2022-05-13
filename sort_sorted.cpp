#include <iostream>

using namespace std;

void sort(int a[], int len){
    cout << "Shaker" << endl;

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

void sort(int a[], int len, string sort_name){
    cout << "stupid" << endl;

    for(int i = 0; i < len - 1 ; i++){
        for(int j = 0; j < len - 1 ; j++){
            
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

        }
    }

}

void sort(int a[], int len, bool bubble){
    cout << "bubble" << endl;
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){

            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;

            }
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
    int a[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    int b[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    int c[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    int len = sizeof(a)/sizeof(a[0]);

    sort(a, len);
    print_arr(a, len);
    cout << "---------------------------" << endl;

    string sort_name = "st_sort";
    sort(b, len, sort_name);
    print_arr(b, len);

    cout << "---------------------------" << endl;
    bool bubble = true;
    sort(c, len, bubble);
    print_arr(c, len);

    return 0;
}