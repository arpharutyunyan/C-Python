#include <iostream>
using namespace std;


int bs(int a[], int n, int start, int end){

    while (start <= end){

        int mid = (start + end) / 2;

        if(n == a[mid]){
            return mid;
        }
        else if(n < a[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }

    }

    // we have 0 index, return -1 for false
    return -1;
    
}


int main(){

    int a [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int start = 0;
    int end = sizeof(a)/sizeof(a[0]) - 1;

    int n = 0;
    cout << "Find number: ";
    cin >> n;

    
    int result = bs(a, n, start, end);

    if (result > -1){

        cout << "a[" << result << "] = " << a[result] << endl; 
    }else{
        cout << "There is no the number " << n << endl;
    }       

    return 0;
}