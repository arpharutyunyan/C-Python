#include <iostream>
using namespace std;


class My_math{

    public:

        static float P;

        static float E;

        static float minimum(float a, float b){
            if(a < b){
                return a;
            }else{
                return b;
            }
        }

        static float maximum(float a, float b){
            if(a > b){
                return a;
            }else{
                return b;
            }
        }

        static float area_circle(float r){
            return My_math::P * r * r;
        }

        static float area(float a, float b){
            return a * b;
        }

        static float perimeter_circle(float r){
            return 2 * My_math::P * r;
        }

        static float perimeter(float a, float b){
            return 2 * (a + b);
        }





};

float My_math::P = 3.14;
float My_math::E = 2.718;

int main(){

    cout << "P = " << My_math::P << endl;
    cout << "e = " << My_math::E << endl;
    cout << "max = " << My_math::maximum(5,2) << endl;
    cout << "min = " << My_math::minimum(5,2) << endl;
    cout << "area of circle = " << My_math::area_circle(10) << endl;
    cout << "area = " << My_math::area(10, 10) << endl;


    return 0;
}