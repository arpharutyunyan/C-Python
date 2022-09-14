#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isSimple(int num){

    for(int i=2; i<sqrt(num)+1; ++i){

        if(num%i == 0){
            return false;
        }
    }

    return true;
}

void simple_num(const vector<int> v, vector<int>& simp_num, bool (*func)(int num)){

    for(int i=0; i<v.size(); ++i){
        if(func(v[i])){
            simp_num.push_back(v[i]);
            // cout << v[i] << "\t";
        }
    }
}

int main(){

    const vector<int> v{0, 5, 6, 9, 4, 7, 11, 16, 13, 19};

    vector<int> simp_num{};

    simple_num(v, simp_num, isSimple);

    for(auto i : simp_num){
        cout << i << "\t";
    }

    return 0;
}