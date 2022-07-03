#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main(){

    regex passport("([A][A-Z][0-9]{7})|([0][0-9]{8})");  // ID 
    regex name_sname("\\b[A-Z][a-z]{3,}\\s+[A-Z][a-z]{5,}(yan)\\b");
    string sdate = "([3][0-1]|[0]?[1-9]|[1-2][0-9])(\\.|\\/|\\-)([0]?[1-9]|[1][0-2])(\\.|\\/|\\-)([1-2]?[0-9]{2,3})";
    string date_reverse = "([1-2]?[0-9]{2,3})(\\.|\\/|\\-)([0]?[1-9]|[1][0-2])(\\.|\\/|\\-)([3][0-1]|[0]?[1-9]|[1-2][0-9])";
    regex date(sdate + "|" + date_reverse);
    regex ipv4("((([2][5][0-5])|([2][0-4][0-9])|([0-1]?[0-9]{1,2}))(\\.)?){4}"); 
    //regex ipv6(""); 

    smatch sm;

    // string pass = "005491980";
    // string name = "Sergey Ivanov";
    // string d = "31-10-2022";
    // string dr = "1931-10-31";
    // string ipv_4 =  "255.255.255.255";
    // string ipv_6 = "2001:0db8:11a3:09d7:1f34:8a2e:07a0:765d";

    string s[14] = {"005491980", "AS1234567", "00", "255.255.255.255", "255.239.1.85", "254.157.200.452", "Arpine Harutyunyan", 
                    "Anna Martirosyan", "Sergey Ivanov", "01.12.03", "31.12.2022", "31.12.3022", "2022/05/12", "1931.10.31"};


    ofstream ofs;
    ofs.open("./source.txt");

    for(int i=0; i<14; i++){
        ofs<<(s[i] + "\n");
    }

    ofs.close();

    ifstream ifs;
    ifs.open("./source.txt");

    string phrase;
    while (getline(ifs, phrase)){
        ofs.open("./destination.txt", ios::app);
        ofs << (phrase + "\n");
    }
    ofs.close();
    ifs.close();
    
    


    
    //cout << regex_match(dr, sm, date) << endl;

    return 0;
}

