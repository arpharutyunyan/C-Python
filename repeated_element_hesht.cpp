#include <iostream>
using namespace std;

int main(){

    int a[] = {10, 7, 10, 20, 5, 10, 7, 14, 63, 12, 14, 14, 120, 130};

    int size = sizeof(a)/sizeof(a[0]);
    
    int b[size] = {0};
    int index = 0;

    // Filling b array

    for(int i = 0; i < size; i++){
        
        int j;
        for(j = 0; j < index; j++){

            if(a[i] == b[j]){
               
                break;
            }
        }

        if(j == index){
            
            b[index++] = a[i];
        }
    }

    /////////////////////////////////////////////////////////

    // Filling c array
    int c[index];
    

    for(int i = 0; i < index; i++){
        int count = 0;

        for(int j = 0; j < size; j++){

            if (b[i] == a[j]){
                count ++;
            }        
            
        }

        c[i] = count;
        
    }

    //////////////////////////////////////////////////////////
    
    // print with sorted frequency
    int max_index = 0;

    for(int i = 0; i < index; i++){

        int max = c[0];

        for(int j = 0; j < index; j++){

            if(c[j] > max){
                max = c[j];
                max_index = j;  
            } 
        }

        cout << b[max_index] << "\t" << c[max_index]<<endl;

        c[max_index] = 0;
       
    }

    return 0;
}
