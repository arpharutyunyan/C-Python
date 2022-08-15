#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>

using namespace std;

void convert_utf8_utf16(const char* source, const char* destination){

    FILE* fr = fopen(source, "r");

    fseek(fr, 0L, SEEK_END);
    size_t size = ftell(fr);
    fseek(fr, 0L, SEEK_SET);

    cout << "size = " << size << endl;

    unsigned char arr[size];

    fread(arr, 1, size, fr);

    fclose(fr);

    FILE* fw = fopen(destination, "w");

    unsigned short endian = 0xFEFF;  //  big endian, but work like le, because fwrite 2 bytes with inverse one bytes 
    // unsigned short endian = 0xFFFE ;  //  little endian
    fwrite(&endian, 2, 1, fw); 

    unsigned short result;

    for(int i=0; i<size; i++){
        cout << (unsigned short)arr[i] << "\t";

        if(arr[i] >= 0 and arr[i] <= 127){
            cout << " 1 byte \n";
            result = arr[i];
            fwrite(&result, 2, 1, fw);

        }else if(arr[i] >= 192 and arr[i] <= 223){
            cout << "\n 2 byte \n";
            unsigned short first = (arr[i] & 0b00011111) << 6;
            
            unsigned short second = arr[i+1] & 0b00111111;
            result = first | second;
            
            bitset<8>  elem = arr[i];
            cout << "arr[i] " << elem << endl;
            bitset<8>  selem = arr[i+1];
            cout << "arr[i+1] " << selem << endl;
            bitset<16>  a = first;
            cout << "first " << a << endl;
            bitset<16> b = second;
            cout << "second = " << b << endl;
            bitset<16> c = result;
            cout << "result = " << c << endl;

            fwrite(&result, 2, 1, fw);
            
            ++i;

        }else if(arr[i] >= 224 and arr[i] <= 239){
            cout << " 3 byte \n";
            unsigned short first = (arr[i] & 0b00001111) << 12;   // ????
            
            unsigned short second = (arr[i+1] & 0b00111111) << 6;

            unsigned short third = (arr[i+2] & 0b00111111);
            result = first | second | third;
            
            bitset<8>  elem = arr[i];
            cout << "arr[i] " << elem << endl;
            bitset<8>  selem = arr[i+1];
            cout << "arr[i+1] " << selem << endl;
            bitset<8>  thelem = arr[i+2];
            cout << "arr[i+2] " << thelem << endl;
            bitset<16>  a = first;              //  ?????
            cout << "first " << a << endl;
            bitset<16> b = second;
            cout << "second = " << b << endl;
            bitset<16> c = third;
            cout << "third = " << c << endl;
            bitset<16> d = result;
            cout << "result = " << d << endl;

            fwrite(&result, 2, 1, fw);
            
            i += 2;
        }
    }

    fclose(fw);
}

