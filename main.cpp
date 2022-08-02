#include <iostream>
using namespace std;
#include "operators.cpp"


int main(){

    Income i1(100.50, 100.0, 100.0, 100.0, 100.0);
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

    Income i5;
    std::cout << " operator bool  \n";
    if(i5){
        i5.print();
    }else{
        std::cout << "false \n";
    }

    // std::cout << "operator float \n";
    // float x = (float)i1;
    // std::cout << x << std::endl;
    // std::cout << typeid(x).name() << std::endl;

    std::cout << "operator int \n";
    int y = (int)i1;
    std::cout << y << std::endl;
    std::cout << typeid(y).name() << std::endl;

    std::cout<<i1;

    std::cin>>i1;
    std::cout<<i1;



    return 0;
}
