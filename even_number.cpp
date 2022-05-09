#include <iostream>
#include <random>
using namespace std;

// filling array
void create_array(int arr[], int len = 10){

    for(int i = 0; i < len; i++){
        arr[i] = rand() % 20;
    }
}

// print array with given size
void print_arr(int arr[], int len){

    for(int i = 0; i < len; i++){
        cout << arr[i] << "\t";
    }

    cout << endl;
}

//finding even number 
void even_num(int arr[], int even_arr[], int len = 10){

    cout << "array with even number" << endl;

    int index = 0;  // get index for filling even_array

    for(int i = 0; i < len; i++){
         if(arr[i] % 2 == 0){
             even_arr[index] = arr[i];
             index++;
         }
    }

    // call print function for even_array with size = index
    print_arr(even_arr, index);
}


//finding odd number 
void odd_num(int arr[], int odd_arr[], int len = 10){

    cout << "array with odd number" << endl;

    int index = 0;  // get index for filling odd_array

    for(int i = 0; i < len; i++){
         if(arr[i] % 2 == 1){
             odd_arr[index] = arr[i];
             index++;
         }
    }

    // call print function for odd_array with size = index
    print_arr(odd_arr, index);
}

int main(){

    int given_array[10];
    int odd[10];
    int even[10];

    create_array(given_array);
    print_arr(given_array, 10);

    even_num(given_array, odd);
    odd_num(given_array, even);
    

    return 0;
}