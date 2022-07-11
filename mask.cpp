#include <iostream>
using namespace std;

int main(){

    int ip = 0b11011100100000011000000101011101;
             //0b11011100 10000001 10000001 01011101
  int mask = 0b00000000000000001111000000000000;
            // 0b111100000000000000000000 00000000
    int network = ip & mask;

    cout<<"ip = "<<ip<<endl;
    cout<<"mask = "<<mask<<endl;

    cout<<"network = "<<network<<endl;

    unsigned int ip_shiwt = (ip<<20)>>28;
    cout<<"shiwt = "<<ip_shiwt<<endl;

    return 0;
}