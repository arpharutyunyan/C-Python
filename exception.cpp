#include <iostream>
using namespace std;

int main(){

    int* p;

    try{
        p = new int[1000000000000];
    }
    catch(bad_alloc& e)
    {
        cout << e.what() << '\n';
    }
    
    return 0;
}