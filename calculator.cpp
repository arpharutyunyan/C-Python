#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


bool isOperator(char ch) {

    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int getPrecedence(char ch) {

    if (ch == '+' || ch == '-') {
        return 1;
    }
    if (ch == '*' || ch == '/') {
        return 2;
    }

    return 0;
}

int cast(string input){

    int result = 0;

    for(int i=0; i<input.length(); ++i){
        int number = input[i]-48;
        int degree = input.length()-1-i;
        result += number * pow(10, degree);
    }

    return result;
}

void eval(char operation, vector<int>& values) {

    int result = 0;

    int a, b;

    if(!values.empty()){

        b = values[values.size()-1];
        values.pop_back();
    }

    if(!values.empty()){  // if not empty after deleting last number (b)

        a = values[values.size()-1];
        values.pop_back();
    }

    switch (operation) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':

            if(b != 0){
                result = a / b;
            }
            break;
            
    }

    values.push_back(result);
}

int main(){

    string input;

    // cin >> input;
    input = "123+20/2-30+2*20/2";

    vector<int> values{};
    vector<char> operators{};

    int index=0;
    string num = ""; 
    for(int i=0; i<input.length(); ++i){
        if(input[i] >= '0' and input[i] <= '9'){
           
                num += input[i]; //create string
            
        }else if(isOperator(input[i])){

            int number = cast(num);  // cast string to int
            values.push_back(number);
            num = "";  // clear string for casting int

            if(operators.empty() || getPrecedence(input[i])>getPrecedence(operators[operators.size()-1])){
                operators.push_back(input[i]);
            }else{
                while(!operators.empty() and getPrecedence(input[i]) <= getPrecedence(operators[operators.size()-1])){
                    char last_op = operators[operators.size()-1];
                    operators.pop_back();
                    eval(last_op, values);
                }

                operators.push_back(input[i]);
                
            }
        }
    }

    int number = cast(num);  // last checked
    values.push_back(number);

    while(!operators.empty()){  
        
        char last_op = operators[operators.size()-1];
        operators.pop_back();
        eval(last_op, values);

    }
    

    int result = values[0];
    cout << "input is " << input << endl << endl;
    cout << "result = " << result << endl << endl;


    return 0;
}