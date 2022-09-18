#include <iostream>
#include <algorithm>

using namespace std;

struct Pesron{

    public:
        string name;
        string surname;
        int age;

        Pesron(){};

        Pesron(string name, string surname, int age): name(name), surname(surname), age(age){
            // this->name = name;
            // this->surname = surname;
            // this->age = age;
        }

        friend ostream& operator<<(ostream& print, Pesron& per){
            
            cout << "name = " << per.name << endl;
            cout << "surname = " << per.surname << endl;
            cout << "age = " << per.age << endl;

            return print;
        }

};


int main(){

    Pesron p[] = {

        Pesron("name1", "sname1", 1),
        Pesron("name25", "sname25", 25),
        Pesron("name1", "sname1", 1),
        Pesron("name16", "sname16", 16),
        Pesron("name65", "sname65", 65),
        Pesron("name48", "sname48", 48),
        Pesron("name47", "sname47", 47),
        Pesron("name73", "sname73", 73),
        Pesron("name173", "sname173", 173),
        Pesron("name73", "sname73", 73),

    };

    sort(p, p+10, [](const Pesron& pa, const Pesron& pb){
        return pa.name < pb.name;
    });

    cout << "----------------name--------------------\n";

    for(Pesron i : p){
        cout << i << endl;
    }

    cout << "----------------surname--------------------\n";

    sort(p, p+10, [](const Pesron& pa, const Pesron& pb){
        return pa.surname < pb.surname;
    });

    for(Pesron i : p){
        cout << i << endl;
    }

    cout << "----------------age--------------------\n";

    sort(p, p+10, [](const Pesron& pa, const Pesron& pb){
        return pa.age < pb.age;
    });

    for(Pesron i : p){
        cout << i << endl;
    }

    return 0;
}