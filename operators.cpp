#include <iostream>

class Income{

    public:

        double fromShop = 0.0;
        double fromTenders = 0.0;
        double fromApps = 0.0;
        double fromEducation = 0.0;
        double fromConsultation = 0.0;

        Income(){
            std::cout << "Non argument constructor \n";
        }

        Income(double fromShop, double fromTenders, double fromApps, double fromEducation, double fromConsultation){
            std::cout << "Constructor with arguments \n";

            this->fromShop = fromShop;
            this->fromTenders = fromTenders;
            this->fromApps = fromApps;
            this->fromEducation = fromEducation;
            this->fromConsultation = fromConsultation;
        }

        Income(const Income& other){
            std::cout << "copy constructor \n";

            this->fromShop = other.fromShop;
            this->fromTenders = other.fromTenders;
            this->fromApps = other.fromApps;
            this->fromEducation = other.fromEducation;
            this->fromConsultation = other.fromConsultation;
        }

        Income& operator=(const Income& other){
            std::cout << "------------- operator= ------------------- \n";

            fromShop = fromShop;
            fromTenders = fromTenders;
            fromApps = fromApps;
            fromEducation = fromEducation;
            fromConsultation = fromConsultation;

            return *this;
        }

        bool operator==(const Income& other){
            std::cout << "------------- operator== ------------------- \n";

            if(&other == this){
                return true;
            }

            bool first = this->fromShop == other.fromShop && this->fromTenders == other.fromTenders;
            bool second = this->fromApps == other.fromApps && this->fromEducation == other.fromEducation;
            bool third = this->fromConsultation == other.fromConsultation;
            return first && second && third;
        }

        bool operator!=(const Income& other){
            std::cout << "------------- operator != ------------------- \n";

            if(&other == this){
                return false;
            }

            return true;
        }

        double sum(const Income& obj){
            
            return obj.fromShop + obj.fromTenders + obj.fromApps + obj.fromEducation + obj.fromConsultation;

        }

        bool operator>(const Income& other){
            std::cout << "------------- operator> ------------------- \n";

            return sum(*this) > sum(other);
        }

        

        bool operator<(const Income& other){
            std::cout << "------------- operator< ------------------- \n";

            return sum(*this) < sum(other);
        }

        bool operator>=(const Income& other){
            std::cout << "------------- operator >= ------------------- \n";

            bool first_and = this->fromShop > other.fromShop && this->fromTenders > other.fromTenders;
            bool second_and = this->fromApps > other.fromApps && this->fromEducation > other.fromEducation;
            bool third_and = this->fromConsultation > other.fromConsultation;

            bool first_or = this->fromShop == other.fromShop && this->fromTenders == other.fromTenders;
            bool second_or = this->fromApps == other.fromApps && this->fromEducation == other.fromEducation;
            bool third_or = this->fromConsultation == other.fromConsultation;
        
            return (first_and && second_and && third_and) or  (first_or && second_or && third_or);   
        }

        bool operator<=(const Income& other){
            std::cout << "------------- operator <= ------------------- \n";

            bool first_and = this->fromShop < other.fromShop && this->fromTenders < other.fromTenders;
            bool second_and = this->fromApps < other.fromApps && this->fromEducation < other.fromEducation;
            bool third_and = this->fromConsultation < other.fromConsultation;

            bool first_or = this->fromShop == other.fromShop && this->fromTenders == other.fromTenders;
            bool second_or = this->fromApps == other.fromApps && this->fromEducation == other.fromEducation;
            bool third_or = this->fromConsultation == other.fromConsultation;
        
            return (first_and && second_and && third_and) or  (first_or && second_or && third_or);                //(&other == this);
        }

        const Income operator*(const Income& other){
            std::cout << "------------- operator * ------------------- \n";

            Income temp;
            temp.fromShop = this->fromShop * other.fromShop;
            temp.fromTenders = this->fromTenders * other.fromTenders;
            temp.fromApps = this->fromApps * other.fromApps;
            temp.fromEducation = this->fromEducation * other.fromEducation;
            temp.fromConsultation = this->fromConsultation * other.fromConsultation;
            return temp;
        }

        const Income operator/(const Income& other){
            std::cout << "------------- operator / ------------------- \n";

            Income temp;
            temp.fromShop = this->fromShop / other.fromShop;
            temp.fromTenders = this->fromTenders / other.fromTenders;
            temp.fromApps = this->fromApps / other.fromApps;
            temp.fromEducation = this->fromEducation / other.fromEducation;
            temp.fromConsultation = this->fromConsultation / other.fromConsultation;
            return temp;
        }

        const Income operator+(const Income& other){
            std::cout << "------------- operator + ------------------- \n";

            Income temp;
            temp.fromShop = this->fromShop + other.fromShop;
            temp.fromTenders = this->fromTenders + other.fromTenders;
            temp.fromApps = this->fromApps + other.fromApps;
            temp.fromEducation = this->fromEducation + other.fromEducation;
            temp.fromConsultation = this->fromConsultation + other.fromConsultation;
            return temp;
        }

        const Income operator-(const Income& other){
            std::cout << "------------- operator - ------------------- \n";

            Income temp;
            temp.fromShop = this->fromShop - other.fromShop;
            temp.fromTenders = this->fromTenders - other.fromTenders;
            temp.fromApps = this->fromApps - other.fromApps;
            temp.fromEducation = this->fromEducation - other.fromEducation;
            temp.fromConsultation = this->fromConsultation - other.fromConsultation;
            return temp;
        }

        const Income& operator*=(const Income& other){
            std::cout << "------------- operator *= ------------------- \n";

            this->fromShop = this->fromShop * other.fromShop;
            this->fromTenders = this->fromTenders * other.fromTenders;
            this->fromApps = this->fromApps * other.fromApps;
            this->fromEducation = this->fromEducation * other.fromEducation;
            this->fromConsultation = this->fromConsultation * other.fromConsultation;
            return *this;
        }

        const Income& operator/=(const Income& other){
            std::cout << "------------- operator /= ------------------- \n";

            this->fromShop = this->fromShop / other.fromShop;
            this->fromTenders = this->fromTenders / other.fromTenders;
            this->fromApps = this->fromApps / other.fromApps;
            this->fromEducation = this->fromEducation / other.fromEducation;
            this->fromConsultation = this->fromConsultation / other.fromConsultation;
            return *this;
        }

        const Income& operator+=(const Income& other){
            std::cout << "------------- operator += ------------------- \n";

            // Income temp;
            this->fromShop = this->fromShop + other.fromShop;
            this->fromTenders = this->fromTenders + other.fromTenders;
            this->fromApps = this->fromApps + other.fromApps;
            this->fromEducation = this->fromEducation + other.fromEducation;
            this->fromConsultation = this->fromConsultation + other.fromConsultation;
            return *this;
        }

        const Income& operator-=(const Income& other){
            std::cout << "------------- operator -= ------------------- \n";

            // Income temp;
            this->fromShop = this->fromShop - other.fromShop;
            this->fromTenders = this->fromTenders - other.fromTenders;
            this->fromApps = this->fromApps - other.fromApps;
            this->fromEducation = this->fromEducation - other.fromEducation;
            this->fromConsultation = this->fromConsultation - other.fromConsultation;
            return *this;
        }

        Income operator++(int a){
            std::cout << "------------- operator ++ postfix ------------------- \n";

            Income temp = *this;
            this->fromShop += 1;
            this->fromTenders += 1;
            this->fromApps += 1;
            this->fromEducation += 1;
            this->fromConsultation += 1;

            return temp;
        }

        Income& operator++(){
            std::cout << "------------- operator ++ prefix ------------------- \n";

            this->fromShop ++;
            this->fromTenders ++;
            this->fromApps ++;
            this->fromEducation ++;
            this->fromConsultation ++;
            return *this;
        }

        Income& operator--(){
            std::cout << "------------- operator -- prefix ------------------- \n";

            this->fromShop -= 1;
            this->fromTenders -= 1;
            this->fromApps -= 1;
            this->fromEducation -= 1;
            this->fromConsultation -= 1;
            return *this;
        }

        Income operator--(int a){
            std::cout << "------------- operator -- postfix ------------------- \n";

            Income temp = *this;
            this->fromShop -= 1;
            this->fromTenders -= 1;
            this->fromApps -= 1;
            this->fromEducation -= 1;
            this->fromConsultation -= 1;

            return temp;
        }

        operator bool(){
            std::cout << "------------- operator bool ------------------- \n";

            bool first = this->fromShop == 0 && this->fromTenders == 0;
            bool second = this->fromApps == 0 && this->fromEducation == 0;
            bool third = this->fromConsultation == 0;

            if(first && second && third){  // if all 0 it will be false
                return false;
            }else{
                return true;
            }
        }

        operator float(){
            std::cout << "------------- operator float ------------------- \n";

            return (float)(sum(*this));
        }

        operator int(){
            std::cout << "------------- operator int ------------------- \n";

            return (int)(sum(*this));
        }

        operator double(){
            std::cout << "------------- operator double ------------------- \n";

            return (double)(sum(*this));
        }

        friend std::ostream& operator<<(std::ostream& print, const Income obj){
            std::cout << "-------------- operator<< ----------------- \n";
            print << "fromShop = " << obj.fromShop << std::endl;
            print << "fromTenders = " << obj.fromTenders << std::endl;
            print << "fromApps = " << obj.fromApps << std::endl;
            print << "fromEducation = " << obj.fromEducation << std::endl;
            print << "fromConsultation = " << obj.fromConsultation << std::endl;

            return print;
        }

        friend std::istream& operator>>(std::istream& input, Income& obj){
            std::cout << "-------------- operator>> ----------------- \n";

            input >> obj.fromShop;
            input >> obj.fromTenders;
            input >> obj.fromApps;
            input >> obj.fromEducation;
            input >> obj.fromConsultation;

            return input;
        }

        void print(){

            std::cout << "fromShop = " << fromShop << std::endl;
            std::cout << "fromTenders = " << fromTenders << std::endl;
            std::cout << "fromApps = " << fromApps << std::endl;
            std::cout << "fromEducation = " << fromEducation << std::endl;
            std::cout << "fromConsultation = " << fromConsultation << std::endl;
        }
};