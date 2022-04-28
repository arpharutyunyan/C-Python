#include <iostream>

using namespace std;

int main()
{
    int a[] = {10, 20, 30, 10, 20, 30, 40, 50, 60, 90};
    int size = sizeof(a)/sizeof(a[0]);
    int len_diapazon = 1;
    int max = 0;
    int index = 0;
    
    for (int i = 0; i < size - 1; i++ ){
  
        if (a[i] < a[i + 1] and i != size - 2){

            len_diapazon ++;
            
        }else{
            
            if(len_diapazon > max){
            
                max = len_diapazon;
                index = i;
            }
            
            len_diapazon = 1;
        }
        
    }

    cout << max << endl;

    return 0;
}