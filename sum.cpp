#include <iostream>
using namespace std;

// count sum of elements in given array
int summer(int arr[], int len){

    if(len == 0){
        return arr[len];
    }

    return arr[len] + summer(arr, len - 1);
}

// count sum of given range
int summer(int number){

    if(number ==1){
        return 1;
    }

    return number + summer(number - 1);
}

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int len = sizeof(arr) / sizeof(arr[0]) - 1;
    int sum = summer(arr, len);

    cout << "sum = " << sum <<endl;

    // call function for counting sum of 1 - number
    int number = 0;
    cout << "Enter the number: ";
    cin >> number;

    int sum_number = summer(number);
    cout << "sum number = " << sum_number << endl;

    return 0;
}