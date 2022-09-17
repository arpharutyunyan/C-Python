#include <iostream>
// #include <cmath>

using namespace std;

int pow(int num, int degree = 2){

    int res = 1;

    for(int i=1; i<=degree; ++i){
        res *= num;
    }

    return res;

}

int main(){

    string input;

    cout << "input the number \n\n";
    cin >> input;
    cout << endl;

    int result = 0;

    for(int i=0; i<input.length(); ++i){
        int number = input[i]-48;
        int degree = input.length()-1-i;
        result += number * pow(10, degree);
    }

    cout << result << endl;

    return 0;
}

// #include <stdlib.h>
// #include <stdio.h>

// using namespace std;

// int main(){

//     system("./testbash.sh");

//     return 0;


// }