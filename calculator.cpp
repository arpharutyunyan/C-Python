#include <iostream>
#include <vector>

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
    input = "1+2/2-3-2*2/2";

    vector<int> values{};
    vector<char> operators{};

    for(auto i : input){
        if(i >= '0' and i <= '9'){
            values.push_back(((int)i-48));
        }else if(isOperator(i)){
            if(operators.empty() || getPrecedence(i)>getPrecedence(operators[operators.size()-1])){
                operators.push_back(i);
            }else{
                while(!operators.empty() and getPrecedence(i) <= getPrecedence(operators[operators.size()-1])){
                    char last_op = operators[operators.size()-1];
                    operators.pop_back();
                    eval(last_op, values);
                }

                operators.push_back(i);
                
            }
        }
    }

    while(!operators.empty()){  // last checked
        
        char last_op = operators[operators.size()-1];
        operators.pop_back();
        eval(last_op, values);

    }
    

    int result = values[0];
    cout << "result = " << result << endl;


    return 0;
}