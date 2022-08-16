#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include "convertor_utf8_utf16le.h"
#include "convertor_utf8_utf16be.h"
#include "convertor_utf16le_utf8.h"
#include "convertor_utf16be_utf8.h"


int main(int argc, char** argv){

    if(argc == 2 and (string)argv[1] == "-h"){

        cout << "./a.out <from utf format> <into utf format> <source txt file name> <destination txt file name> \n";

    }else if(argc == 5){

        if((string)argv[1] == "utf-8" and (string)argv[2] == "utf-16le"){

            convert_utf8_utf16le(argv[3], argv[4]);
            cout << "Writing is completed. \n";

        }else if((string)argv[1] == "utf-8" and (string)argv[2] == "utf-16be"){

            convert_utf8_utf16be(argv[3], argv[4]);
            cout << "Writing is completed. \n";

        }else if((string)argv[1] == "utf-16le" and (string)argv[2] == "utf-8"){
            
            convert_utf16le_utf8(argv[3], argv[4]);
            cout << "Writing is completed. \n";

        }else if((string)argv[1] == "utf-16be" and (string)argv[2] == "utf-8"){
            
            convert_utf16be_utf8(argv[3], argv[4]);
            cout << "Writing is completed. \n";

        }else if((string)argv[1] == "utf-16" and (string)argv[2] == "utf-8"){
            
            FILE* fr = fopen(argv[3], "r");
            unsigned short arr[1];
            fread(arr, 2, 1, fr);
            fclose(fr);
            if(arr[0] == 65279){
                convert_utf16le_utf8(argv[3], argv[4]);
                cout << "Writing is completed. \n";
            }else if(arr[0] == 65534){
                convert_utf16be_utf8(argv[3], argv[4]);
                cout << "Writing is completed. \n";
            }
            
            

        }else{
            cout << "Command is not correct. \nRun <./a.out -h> for helping." << endl;
        }

    }else{
        cout << "Command is not correct. \nRun <./a.out -h> for helping." << endl;
    }


    return 0;
}