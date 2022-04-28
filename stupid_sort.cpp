#include <iostream>

using namespace std;

int main()
{
    int a[] = {100, 10, 25, 4, 22, 30, 64};
    int len = sizeof(a)/sizeof(a[0]);
    int count = 0;
    int count_swap = 0;
    
    for(int i = 0; i < len - 1 ; i++){
        count ++;
        
        if(a[i] > a[i + 1]){
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
            i = -1;
            
            count_swap ++;
        }

    }
    
    for(int i = 0; i < len; i++){
        cout << a[i] << std::endl;
    }
    
    cout << count << endl << count_swap<<endl;

    return 0;
}