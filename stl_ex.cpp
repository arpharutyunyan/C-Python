#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main () {
        set <int> s;

        // long start_s = clock();

        for(int i=0; i < 100000; ++i) {
                s.emplace(rand()%10000 +1);
        }

        long start_s = clock();
        for(int i=0; i<10000000; ++i){
            s.find(i);
        }

        long end_s = clock();
        long s_time = end_s - start_s;
        cout << "set time is: " << s_time << endl;


        unordered_set <int> uns;

        // long start_uns = clock();

        for(int i=0; i < 100000; ++i) {
                uns.emplace(rand()%10000 +1);
        }

        long start_uns = clock();

        for(int i=0; i<10000000; ++i){
            s.find(i);
        }

        long end_uns = clock();

        long uns_time = end_uns - start_uns;
        cout << "unoredered set time is: " << uns_time  << endl;
        cout << "diff time is: " << (double)uns_time / s_time  << endl;


        return 0;
}