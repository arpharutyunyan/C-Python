#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>

using namespace std;
// void convert_utf8_utf16be(const char* source, const char* destination);

// int main(int argc, char** argv){


//     convert_utf8_utf16be(argv[1], argv[2]);


//     return 0;
// }

void convert_utf8_utf16be(const char* source, const char* destination){

    FILE* fr = fopen(source, "r");

    fseek(fr, 0L, SEEK_END);
    size_t size = ftell(fr);
    fseek(fr, 0L, SEEK_SET);

    cout << "size = " << size << endl;

    unsigned char arr[size];

    fread(arr, 1, size, fr);

    fclose(fr);

    FILE* fw = fopen(destination, "w");

    // unsigned short endian = 0xFEFF;  //  big endian 
    unsigned short endian = 0xFFFE ;  //  little endian, but work like be, because fwrite 2 bytes with inverse one bytes
    fwrite(&endian, 2, 1, fw); 

    unsigned short result;

    for(int i=0; i<size; i++){
        // cout << (unsigned short)arr[i] << "\t";

        if(arr[i] >= 0 and arr[i] <= 127){
            // cout << " 1 byte \n";
            result = arr[i] << 8;
            fwrite(&result, 2, 1, fw);

        }else if(arr[i] >= 192 and arr[i] <= 223){
            // cout << "\n 2 byte \n";
            unsigned short first = (arr[i] & 0b00011111) << 6;
            
            unsigned short second = arr[i+1] & 0b00111111;
            result = first | second;
            unsigned short result_first = result << 8;
            unsigned short result_second = result >> 8;

            result = result_first | result_second;

            
            // bitset<8>  elem = arr[i];
            // cout << "arr[i] " << elem << endl;
            // bitset<8>  selem = arr[i+1];
            // cout << "arr[i+1] " << selem << endl;
            // bitset<16>  a = first;
            // cout << "first " << a << endl;
            // bitset<16> b = second;
            // cout << "second = " << b << endl;
            // bitset<16> c = result;
            // cout << "result = " << c << endl;

            fwrite(&result, 2, 1, fw);
            
            ++i;

        }
    }

    fclose(fw);
}


