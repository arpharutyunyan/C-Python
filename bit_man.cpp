#include <iostream>
using namespace std;

void two_byte(unsigned short a) {
        
    cout << "a = " << a << endl;
    cout << "a = " << 0b1101010110110001 << endl;

    unsigned short first = a & 0b0000000000111111;
    unsigned short second = (a & 0b0001111100000000)>>2;

    unsigned short res = first | second;

    cout << "res = " << 0b0000010101110001 << endl;
    cout << "res = " << res << endl;

}

void three_byte(unsigned int a) {
        
    cout << "a = " << a << endl;
    cout << "a = " << 0b111001011011000110110101 << endl;

    unsigned short first = a & 0b000000000000000000111111;
    unsigned short second = (a & 0b000000000011111100000000)>>2;
    unsigned short third = (a & 0b000011110000000000000000)>>4;

    unsigned short res = first | second | third;

    cout << "res = " << 0b000000000101110001110101<< endl;
    cout << "res = " << res << endl;
}

void four_byte(unsigned int a) {
        
    cout << "a = " << a << endl;
    cout << "a = " << 0b11110010100110001001101010110111 << endl;

    unsigned int first = a & 0b00000000000000000000000000111111;
    unsigned int second = (a & 0b00000000000000000011111100000000)>>2;
    unsigned int third = (a & 0b00000000001111110000000000000000)>>4;
    unsigned int four = (a & 0b00000111000000000000000000000000)>>6;

    unsigned int res = first | second | third | four;

    cout << "res = " << 0b00000000000010011000011010110111<< endl;
    cout << "res = " << res << endl;
}

int main(){

    //  unsigned short num = 0b1101010110110001;
    // unsigned int num = 0b111001011011000110110101;
    unsigned int num = 0b11110010100110001001101010110111;


                 //0                  //127
    if(num >= 0b00000000 and num <= 0b01111111){
        cout << " 1 byte \n";
                       //192                //223
    }else if(num >= 0b11000000 and num <= 0b11011111){
        cout << " 2 byte \n";
        two_byte(num);
                       //224               //239
    }else if(num >= 0b11100000 and num <= 0b11101111){
        cout << " 3 byte \n";
        three_byte(num);
                       //240                 //247
    }else if(num >= 0b11110000 and num <= 0b11110111){
        cout << " 4 byte \n";
        four_byte(num);
    }

    // two_byte(num);
    // three_byte(num);
    four_byte(num);
      

    return 0;
}