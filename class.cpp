#include <iostream>
using namespace std;

class Person{
    private:
        string name;
        string surname;
        int age;

    public:

        Person(string n, string s, int age){
            name = n;
            surname = s;
            age = age;
        }

        Person(){
            cout << "---Non argument constructor---" << endl;
        }

        void print(){
            cout << "-------- Call the print function --------" << endl;

            cout << "name " << name << endl;
            cout << "surname " << surname << endl;
            cout << "age " << age << endl;

        }

        void setName(string s){
            name = s;
        }

        void setSurname(string s){
            surname = s;
        }

        void setAge(int a){
            age = a;
        }

        string getName(){
            return name;
        }

        string getSurnamme(){
            return surname;
        }

        int getAge(){
            return age;
        }
};

int main(){

    Person alpinist;
    alpinist.setName("Anna");
    cout << alpinist.getName() << endl;

    Person doctor;
    
    doctor.setAge(25);
    cout << doctor.getAge() << endl;

    return 0;
}
