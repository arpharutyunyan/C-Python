#include <iostream>
#include "convertor.cpp"
#include "convertor_utf16_utf8.cpp"


int main(int argc, char** argv){

    if(argc == 2 and (string)argv[1] == "-h"){

        cout << "./a.out <from utf format> <into utf format> <source txt file name> <destination txt file name> \n";

    }else if(argc == 5){

        if((string)argv[1] == "utf-8" and (string)argv[2] == "utf-16"){

            convert_utf8_utf16(argv[3], argv[4]);

        }else if((string)argv[1] == "utf-16" and (string)argv[2] == "utf-8"){
            
            convert_utf16_utf8(argv[3], argv[4]);

        }else{
            cout << "Command is not correct. \nRun <./a.out -h> for helping." << endl;
        }

    }else{
        cout << "Command is not correct. \nRun <./a.out -h> for helping." << endl;
    }


    return 0;
}