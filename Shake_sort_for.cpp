#include <iostream>
using namespace std;
int main()
{
    int a[] = {100, 10, 25, 4, 22, 30, 64};
    int len = sizeof(a)/sizeof(a[0]);
    int count = 0;
    int count_swap = 0;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len - 1 - i; j++){
            count ++;
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                count_swap ++;
            }
        }
    }
    for(int i = 0; i < len; i++){
        cout << a[i] << std::endl;
    }
    cout << count << endl << count_swap<<endl;
    return 0;
}