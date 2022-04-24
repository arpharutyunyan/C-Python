#include <iostream>
using namespace std;

int main(){

    int arr[] = {20, 25, 658, 45, 36, 4, 54, 32, 150, 200, 456};
    int len = sizeof(arr)/sizeof(arr[0]);
    int sizeof_given_range = 0;
    int min, max;

    cout << "Input min value: ";
    cin >> min;
    cout << "Input max value: ";
    cin >> max;

    for(int i = 0; i<len; i++){

        if(arr[i] <= max && arr[i] >= min){
            sizeof_given_range += 1;
        }
    }

    int val_in_range[sizeof_given_range];

    // fill array from last index 
    // avoiding to create a new variable for new array's index
    
    if(sizeof_given_range > 0){

        for(int i = len - 1; i >= 0; i--){    
            if(arr[i] <= max && arr[i] >= min){
                sizeof_given_range -= 1;
                val_in_range[sizeof_given_range] = arr[i];
                //cout << val_in_range[sizeof_given_range] << endl;
            }
        }

        for (int i: val_in_range){
            cout << i << endl;
        }
        
    }else{
        cout << "There is no any value in given range." << endl;
    }

    return 0;
}