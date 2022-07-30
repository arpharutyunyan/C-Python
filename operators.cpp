#include <iostream>

class Income{

    public:

        double fromShop;
        double fromTenders;
        double fromApps;
        double fromEducation;
        double fromConsultation;

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

        bool operator>(const Income& other){
            std::cout << "------------- operator> ------------------- \n";

            bool first = this->fromShop > other.fromShop && this->fromTenders > other.fromTenders;
            bool second = this->fromApps > other.fromApps && this->fromEducation > other.fromEducation;
            bool third = this->fromConsultation > other.fromConsultation;
            return first && second && third;
        }

        bool operator<(const Income& other){
            std::cout << "------------- operator< ------------------- \n";

            bool first = this->fromShop < other.fromShop && this->fromTenders < other.fromTenders;
            bool second = this->fromApps < other.fromApps && this->fromEducation < other.fromEducation;
            bool third = this->fromConsultation < other.fromConsultation;
            return first && second && third;
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

        void print(){

            std::cout << "fromShop = " << fromShop << std::endl;
            std::cout << "fromTenders = " << fromTenders << std::endl;
            std::cout << "fromApps = " << fromApps << std::endl;
            std::cout << "fromEducation = " << fromEducation << std::endl;
            std::cout << "fromConsultation = " << fromConsultation << std::endl;
        }
};





int main(){

    Income i1(100, 100, 100, 100, 100);
    Income i2 = i1;
    i2 = i1;
    
    Income i3(400, 500, 600, 700, 800);
    Income i4(100, 100, 100, 100, 100);

    // i1.print();
    // i2.print();

    if(i1 == i2){
        std::cout << "true:  are equals \n";
    }else{
        std::cout << "false: are not eqals\n";
    }

    if(i1 == i3){
        std::cout << "true:  are equals \n";
    }else{
        std::cout << "false: are not eqals\n";
    }

    if(i1 != i3){
        std::cout << "true:  are not equals \n";
    }else{
        std::cout << "false: are eqals\n";
    }

    if(i1 < i3){
        std::cout << "true:  small \n";
    }else{
        std::cout << "false: big\n";
    }

    if(i3 > i1){
        std::cout << "true:  big \n";
    }else{
        std::cout << "false: small\n";
    }

    if(i4 <= i1){
        std::cout << "true:  small or equals \n";
    }else{
        std::cout << "false: big\n";
    }

    if(i3 >= i1){
        std::cout << "true:  big or equals \n";
    }else{
        std::cout << "false: small\n";
    }

    std::cout << " multyply  \n";
    Income multyply = i1 * i2;
    multyply.print();

    std::cout << " plus  \n";
    Income plus = i1 + i3;
    plus.print();

    std::cout << " minus  \n";
    Income minus = i1 - i2;
    minus.print();

    std::cout << " divide  \n";
    Income divide = i1 / i2;
    divide.print();

    std::cout << " -=  \n";
    i3 -= i1;
    i3.print();

    std::cout << " +=  \n";
    i3 += i1;
    i3.print();

    std::cout << " /=  \n";
    i3 /= i1;
    i3.print();

    std::cout << " *=  \n";
    i3 /= i1;
    i3.print();

    std::cout << " ++ prefix  \n";
    i1++;
    i1.print();

    std::cout << " ++ postfix  \n";
    ++i3;
    i1.print();

    std::cout << " -- postfix  \n";
    --i3;
    i3.print();

    std::cout << " -- prefix  \n";
    i3--;
    i3.print();



    return 0;
}