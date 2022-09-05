#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> v = {10, 10, 20, 10, 20, 10, 20, 3, 5, 5, 0};

    cout << "----------------- vector ----------------\n\n";
    set<int> s;

    for(auto i : v){
        cout << i << "\t";
        s.emplace(i);
    }

    cout << "\n\n----------------- set ----------------\n\n";
    for(auto i : s){
        cout << i << "\t";
    }

    cout << "\n\n----------------- map ----------------\n\n";
    map<int, int> m;
    for(auto i : s){
        int value = count(v.begin(), v.end(), i);
        m.emplace(i, value);
    }

    for(auto i : m){
        cout << i.first << " : " << i.second << endl;
    }





    return 0;
}
