#include <iostream>
using namespace std;

class Person{
    
    public:
        string name;
        string surname;
        int age;

        void print(){
            cout << "-------- Call the print function of PERSON --------" << endl;

            cout << "name " << name << endl;
            cout << "surname " << surname << endl;
            cout << "age " << age << endl;

        }

};

class Specialist : public Person{
    public:
        int IQ;
        string language;

        void print(){

            Person::print();

            cout << "-------- Call the print function of Specialist --------" << endl;

            cout << "IQ " << IQ << endl;
            cout << "language " << language << endl;

        }
};

class Medical : public Specialist{
    public:
        double salary;
        int exp_year;

        void print(){
            Specialist::print();

            cout << "-------- Call the print function of Medical --------" << endl;

            cout << "salary " << salary << endl;
            cout << "exp_year " << exp_year << endl;

        }
};

class Surgeon : public Medical{
    public:
        int surg_count;

        void print(){
            Medical::print();

            cout << "-------- Call the print function of Surgeon --------" << endl;

            cout << "surg_count " << surg_count << endl;

        }

};

class Cardio : public Surgeon{
    public:
        string clinic;

        void print(){
            Surgeon::print();
            
            cout << "-------- Call the print function of Cardio --------" << endl;

            cout << "clinic " << clinic << endl;
        }
};



int main(){

    Cardio card;

    card.name = "Albert";
    card.surname = "Harutyunyan";
    card.age = 30;
    card.IQ = 100;
    card.language = "English";
    card.salary = 1000.0;
    card.exp_year = 5;
    card.surg_count = 20;
    card.clinic = "Lalala";

    card.print();



    return 0;
}
