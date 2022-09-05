#include <iostream>
#include <map>


using namespace std;

int main(){

    map<string, int> m;

    m.emplace("runner1", 150);
    m.emplace("runner12", 200);
    m.emplace("runner20", 150);
    m.emplace("runner31", 124);
    m.emplace("runner45", 20);
    m.emplace("runner63", 179);
    m.emplace("runner145", 65);
    m.emplace("runner69", 54);
    m.emplace("runner55", 85);

    multimap<int, string> mm;

    cout << "---------------given map--------------------- \n";
    for(auto& runner : m){
        cout << runner.first << " : " << runner.second << endl;
        mm.emplace(runner.second, runner.first);
    }

    cout << "---------------new map--------------------- \n";
    for(auto& runner : mm){
        cout << runner.second << " : " << runner.first << endl;
    }



    return 0;
}