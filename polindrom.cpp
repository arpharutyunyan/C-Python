#include <iostream>
using namespace std;

bool is_polindrom(string s, int i, int j){

    if( i > j){
        return true;
    }

    if(s[i] != s[j]){
        return false;
    }

    return is_polindrom(s, i + 1, j - 1);

}


void print_result(bool b){

    if(b){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
}


int main(){

    string s = "aabbaa";
    string s1 = "abac";

    int first = 0;
    int last = s.size() - 1;

    bool is_polindrom_result = is_polindrom(s, first, last);
    print_result(is_polindrom_result);

    bool is_polindrom_result1 = is_polindrom(s1, 0, s1.size() - 1);
    print_result(is_polindrom_result1);



    return 0;
}