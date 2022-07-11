#include <iostream>
using namespace std;

class Person{
    private:
        string name;
        string surname;
        int age;

    public:

        static int count;
        Person(string n, string s, int age){
            name = n;
            surname = s;
            age = age;
        }

        Person(){
            cout << "---Non argument constructor---" << endl;
            count++;
            //cout << "count = " << count << endl;;
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
int Person::count = 0;

int main(){

    
    Person alpinist;
    // alpinist.setName("Anna");
    // cout << alpinist.getName() << endl;

    Person doctor;
    
    // doctor.setAge(25);
    // cout << doctor.getAge() << endl;

    cout << Person::count << endl;

    return 0;
}
