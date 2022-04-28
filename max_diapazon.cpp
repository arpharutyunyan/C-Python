#include <iostream>

using namespace std;

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 10, 20, 30, 40, 50, 30, 90}; //100, 110, 120, 130, 140};
    int size = sizeof(a)/sizeof(a[0]);
    int len_diapazon = 1;
    int max = 0;
    int index = 0;
    
    for (int i = 0; i < size - 1; i++ ){
  
        if (a[i] < a[i + 1]){

            len_diapazon ++;

            if(len_diapazon > max){
                
                max = len_diapazon;
                index = i + 1;
                
            }  

        }else{
            
            len_diapazon = 1;
        }  
        
    }

    cout << "max = " << max << endl;
    cout << "index = " << index << endl;
    int b[max];

    

    // for(int i = 0; i < max; i++){
    //     b[i] = a[index - max + i + 1];
    //     cout << b[i] << endl;
    // }


    // fill array from last index
    for(int i = index; i > i - max; i--){

        b[max - 1] = a[i];
        max--;
            
    } 

    for (int i: b){
        cout << i << endl;
    }

    
    return 0;
}