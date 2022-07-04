#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main(){

    string passport = "([A][A-Z][0-9]{7})|([0][0-9]{8})"; // ID 
    string name_sname = "\\b[A-Z][a-z]{3,}\\s+[A-Z][a-z]{5,}(yan)\\b";
    string sdate = "([3][0-1]|[0]?[1-9]|[1-2][0-9])(\\.|\\/|\\-)([0]?[1-9]|[1][0-2])(\\.|\\/|\\-)([1-2]?[0-9]{2,3})";
    string date_reverse = "([1-2]?[0-9]{2,3})(\\.|\\/|\\-)([0]?[1-9]|[1][0-2])(\\.|\\/|\\-)([3][0-1]|[0]?[1-9]|[1-2][0-9])";
    string date = sdate + "|" + date_reverse;
    string ipv4 = "((([2][5][0-5])|([2][0-4][0-9])|([0-1]?[0-9]{1,2}))\\.){3}(([2][5][0-5])|([2][0-4][0-9])|([0-1]?[0-9]{1,2}))";

    string regex_array[4] = {passport, name_sname, date, ipv4};

    string s[14] = {"005491980", "AS1234567", "00", "255.255.255.255", "255.239.1.85", "254.157.200.452", "Arpine Harutyunyan", 
                    "Anna Martirosyan", "Sergey Ivanov", "01.12.03", "31.12.2022", "31.12.3022", "2022/05/12", "1931.10.31"};


    // writting checking phrases from array to source.txt
    ofstream ofs;
    ofs.open("./source.txt");

    for(int i=0; i<14; i++){
        ofs<<(s[i] + "\n");
    }

    ofs.close();


    // reading from source.txt file
    ifstream ifs;
    ifs.open("./source.txt");

    //creating destination.tst file for saveing checked phrases
    ofs.open("./destination.txt", ios::app);

    string phrase;
    smatch sm;

    while (getline(ifs, phrase)){ 

        for(string rex : regex_array){

            regex r(rex);

            if(regex_match(phrase, sm, r)){
                ofs << (phrase + "\n");
            }
        }    
    }

    ofs.close();
    ifs.close();
    
    return 0;
}

