#include <iostream>
using namespace std;

int maxim(int arr[], int len){
    int max = arr[0];

    for(int i = 0; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

int minim(int arr[], int len){
    int min = arr[0];

    for(int i = 0; i < len; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}

int main(){

    int arr[] = {20, 25, 658, 45, 36, 4, 54, 32, 150, 200, 456};
    int len = sizeof(arr)/sizeof(arr[0]);

    int maximum = maxim(arr, len);
    int minimum = minim(arr, len);

    cout << "max = " << maximum << endl;
    cout << "min = " << minimum << endl;


    return 0;

}