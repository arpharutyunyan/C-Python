#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
        // set <int> s;

        // long start_s = clock();

        // for(int i=0; i < 100000; ++i) {
        //         s.emplace(rand()%10000 +1);
        // }

        // long start_s = clock();
        // for(int i=0; i<10000000; ++i){
        //     s.find(i);
        // }

        // long end_s = clock();
        // long s_time = end_s - start_s;
        // // cout << "set time is: " << s_time << endl;


        // unordered_set <int> uns;

        // long start_uns = clock();

        // for(int i=0; i < 100000; ++i) {
        //         uns.emplace(rand()%10000 +1);
        // }

        // long start_uns = clock();

        // for(int i=0; i<10000000; ++i){
        //     s.find(i);
        // }

        // long end_uns = clock();

        // long uns_time = end_uns - start_uns;
        // cout << "unoredered set time is: " << uns_time  << endl;
        // cout << "diff time is: " << (double)uns_time / s_time  << endl;

        // vector<int> v(10, 777);

        // for(int i=0; i<v.size(); ++i){
        //     cout << v[i] << "\t";
        // }

        // cout << "\n\n----------------------------------------\n";

        // vector<int> v2(10, 0);
        // fill(v2.begin(), v2.end(), 22);

        // for(int i=0; i<v2.size(); ++i){
        //     cout << v2[i] << "\t";
        // }

        // cout << "\n\n----------------------------------------\n";

        // vector<int> v3 = {0, 22, 1, 45, 145, 32, 47, 1254};
        // sort(v3.begin(), v3.end());

        // auto f = binary_search(v3.begin(), v3.end(), 32121);
        // cout << "f == " << f << endl;

        string a = "affffggggghhhhhgh";
        string b = "affffffffffffffffffffffggggghhhhhgh";

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for(char i : a){
                cout << i << "\t";
        }

        cout << "\n---------------------------------\n\n";
        for(char i : b){
               cout << i << "\t";
        }

        
        // int a_size = a.size();
        // int b_size = b.size();
        // bool res = s.size() == min(a_size, b_size);
        // cout << "bool res = " << res << endl;

        return 0;
}