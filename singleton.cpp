#include <iostream>
using namespace std;

class Person{

    string name;
    string surname;
    int age;
    static Person* p;
    static int count;

    private:
        Person(string n, string s, int a){
            name = n;
            surname = s;
            age = a;
            count++;
        }


    public:

        static Person* createPerson(string n, string s, int a){
            if(p == nullptr ){
                p = new Person(n, s, a);
            }

            return p;
        }

        static Person* createLimitedPerson(string n, string s, int a){
            if(count < 3){
                p = new Person(n, s, a);
            }

            return p;
        }

        void print(){
            cout << "name: " << name << endl;
            cout << "surname: " << surname << endl;
            cout << "age: " << age << endl;
        }
};

Person* Person::p = nullptr;
int Person::count = 0;

int main(){

    // Person* p1 = Person::createPerson("Ani", "Margaryan", 25);
    // p1->print();  


    Person* p1 = Person::createLimitedPerson("Anna", "Adamyan", 25);
    p1->print();

    cout << "----------------------------------- \n";

    Person* p2 = Person::createLimitedPerson("Ani", "Margaryan", 25);
    p2->print();

    cout << "----------------------------------- \n"; 

    Person* p3 = Person::createLimitedPerson("John", "Smith", 22);
    p3->print();

    cout << "----------------------------------- \n"; 

    Person* p4 = Person::createLimitedPerson("Mark", "Smith", 15);
    p4->print();




    

    return 0;
}