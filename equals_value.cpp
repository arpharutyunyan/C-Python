#include <iostream>
using namespace std;

int main(){

    int a[] = {10, 3, 25, 33, 100, 250, 70};
    int b[] = {22, 3, 14, 33, 25,  70,  250};
    int len = sizeof(a) / sizeof(a[0]);
    int repeated_count = 0;

    for (int i = 0; i < len; i++)
    {
        if (a[i] == b[i])
        {
            repeated_count ++ ;
        }     
    }
    
    cout << "Count of repeated values are: " << repeated_count << endl;

    return 0;
}