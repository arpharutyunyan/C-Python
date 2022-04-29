#include<iostream>
using namespace std;

int main(){

    int a[] = {10, 7, 10, 20, 5, 10, 7, 14, 63, 12, 14, 14};

    int size = sizeof(a)/sizeof(a[0]);
    int len_new_array = 0;

    // sort the given array

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
        
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;                
            }
        }
    }

    for(int i = 0; i < size; i++){
        cout << a[i] << "\t";
    }

    cout << endl << endl;

    

    // getting size of array for adding not repeated elements

    for(int i = 0; i < size - 1; i++){

        if(a[i] == a[i + 1]){

            len_new_array++;
        }
    }

    len_new_array = size - len_new_array;
    cout << "Size of new array " << len_new_array << endl << endl;



    // Creating new arrays

    int new_array[len_new_array];

    int count_elem[len_new_array];

    int index =  0;
    
    int rep_count = 1;


    for(int i = 0; i < size - 1; i++){

        if(a[i] == a[i + 1]){

            rep_count++;

        }else{
            new_array[index] = a[i];
            count_elem[index] = rep_count;
            index++;
            rep_count = 1;
        }

    }

    // adding last element
    new_array[index] = a[size - 1];
    count_elem[index] = rep_count;



    for(int i = 0; i < len_new_array; i++){
        cout << new_array[i] << "\t" << count_elem[i] << endl;
    }

    return 0;
}