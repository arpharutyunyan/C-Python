#include <iostream>
using namespace std;

class Person{
    private:
        string name;
        string surname;
        int age;

    public:

        //---------Constructor----------
        Person(string n){
            cout << "-----Constructor with name-----" << endl;
            name = n;
        }

        Person(string s, bool b){
            cout << "-----Constructor with surname-----" << endl;
            surname = s;
        }

        Person(int a){
            cout << "-----Constructor with age-----" << endl;
            age = a;
        }

        Person(string n, string s){
            cout << "-----Constructor with name and surname-----" << endl;
            name = n;
            surname = s;
        }

        Person(string n, int a){
            cout << "-----Constructor with name and age-----" << endl;
            name = n;
            age = a;
        }

        Person(){
            cout << "---Non argument constructor---" << endl;
        }

        //----------Setters------------------
        void setName(string s){
            name = s;
        }

        void setSurname(string s){
            surname = s;
        }

        void setAge(int a){
            age = a;
        }

        //-------------Getters-----------------
        string getName(){
            return name;
        }

        string getSurnamme(){
            return surname;
        }

        int getAge(){
            return age;
        }

        //-------------Print-------------------
        void print(){
            cout << "-------- Call the print function --------" << endl;

            cout << "name " << name << endl;
            cout << "surname " << surname << endl;
            cout << "age " << age << endl;

        }

};

int main(){

    Person teacher("Anna");
    cout << teacher.getName() << endl << endl;

    Person actor("Mikayelyan", true);
    cout << actor.getSurnamme() << endl << endl;
    
    Person economist(25);
    cout << economist.getAge() << endl << endl;

    string sn = "Mikayelyan";
    Person doctor("Anna", sn);
    cout << doctor.getName() << endl;
    cout << doctor.getSurnamme() << endl << endl;

    Person developer("Anna", 20);
    cout << developer.getName() << endl;
    cout << developer.getAge() << endl << endl;

    return 0;
}
