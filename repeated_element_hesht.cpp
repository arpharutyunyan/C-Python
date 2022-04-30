#include <iostream>
using namespace std;

int main(){

    int a[] = {10, 7, 10, 20, 5, 10, 7, 14, 63, 12, 14, 14, 120, 130};

    int size = sizeof(a)/sizeof(a[0]);
    
    int b[size] = {0};
    int index = 0;

    for(int i = 0; i < size; i++){
        //bool not_contain = true;
        int j;
        for(j = 0; j < index; j++){

            if(a[i] == b[j]){
                //not_contain = false;
                break;
            }
        }

        if(j == index){
            
            b[index] = a[i];
            index++;
        }
    }

    /////////////////////////////////////////////////////////

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


    for(int i = 0; i < index; i++){
        cout << b[i] << "\t" << c[i]<<endl;
    }




    return 0;
}
