#include <iostream>
using namespace std;

class Person{
    
    public:
        string name;
        string surname;
        int age;

        Person(){
            cout << "Non argument Person\n";
        }

        Person(string name, string surname, int age){
            cout << "Person constructor with argument\n";
            this->name = name;
            this->surname = surname;
            this->age = age;
        }

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

        Specialist(){
            cout << "Non argument Specialist\n";
        }

        Specialist(string name, string surname, int age, int iq, string language) : Person(name, surname, age){

            cout << "Specialist constructor with argument\n";
            this->IQ = iq;
            this->language = language;
        }

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

        Medical(){
            cout << "Non argument Medical\n";
        }

        Medical(string name, string surname, int age, int iq, string language, double salary, int exp_year) : 
                                    Specialist(name, surname, age, iq, language) {

            cout << "Medical constructor with argument\n";
            this->salary = salary;
            this->exp_year = exp_year;
        }

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

        Surgeon(){
            cout << "Non argument Surgeon\n";
        }

        Surgeon(string name, string surname, int age, int iq, string language, double salary, int exp_year, int surg_count) : 
                Medical(name, surname, age, iq, language, salary, exp_year) {

            cout << "Surgeon constructor with argument\n";
            this->surg_count = surg_count;
        }

        void print(){
            Medical::print();

            cout << "-------- Call the print function of Surgeon --------" << endl;

            cout << "surg_count " << surg_count << endl;

        }

};

class Cardio : public Surgeon{
    public:
        string clinic;

        Cardio(){
            cout << "Non argument Cardio\n";
        }

        Cardio(string name, string surname, int age, int iq, string language, double salary, int exp_year, int surg_count, string clinic) : 
                Surgeon(name, surname, age, iq, language, salary, exp_year, surg_count){

            cout << "Cardio constructor with argument\n";
            this->surg_count = surg_count;
        }

        void print(){
            Surgeon::print();
            
            cout << "-------- Call the print function of Cardio --------" << endl;

            cout << "clinic " << clinic << endl;
        }
};



int main(){

    Cardio card("Albert", "Harutyunyan", 30, 100, "English", 1000.0, 5, 20, "Lalala");

    // card.name = "Albert";
    // card.surname = "Harutyunyan";
    // card.age = 30;
    // card.IQ = 100;
    // card.language = "English";
    // card.salary = 1000.0;
    // card.exp_year = 5;
    // card.surg_count = 20;
    // card.clinic = "Lalala";

    card.print();



    return 0;
}
