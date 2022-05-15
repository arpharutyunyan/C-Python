#include <iostream>
using namespace std;

class Square{

    private:
        float length;

        float perimeter(float l){
            return 4 * l;
        }

        float area(float l){
            return l * l;
        }

    public:

        Square(float l){
            cout << "\n-----Constructor of square-----" << endl;
            length = l;
        }

        // Square(){
        //     cout << "---Non argument constructor---" << endl;
        // }

        float getPerimeter(){
            return perimeter(length);
        }

        float getArea(){
            return area(length);
        }

        void print(){
            cout << "Perimeter = " << getPerimeter() << endl << endl;
            cout << "Area = " << getArea() << endl << endl;
        }
        
};

class Rectangular{
    private:
        float length, width;

        float perimeter(float l, float w){
            return 2 * (l + w);
        }

        float area(float l, float w){
            return l * w;
        }


    public:
        Rectangular(float l, float w){
            cout << "\n-----Constructor of rectangular-----" << endl;
            length = l;
            width = w;
        }

        float getPerimeter(){
            return perimeter(length, width);
        }

        float getArea(){
            return area(length, width);
        }

        void print(){
            cout << "Perimeter = " << getPerimeter() << endl << endl;
            cout << "Area = " << getArea() << endl << endl;
        }
    
};

class Circle{
    private:
        const float P = 3.14;
        float radius;

        float length(float r){
            return 2 * P * r;
        }

        float area(float r){
            return P * r * r;
        }

    public:

        Circle(float r){
            cout << "\n-----Constructor of circle-----" << endl;
            radius = r;
        }

        float getLength(){
            return length(radius);
        }

        float getArea(){
            return area(radius);
        }

        void print(){
            cout << "length = " << getLength() << endl << endl;
            cout << "Area = " << getArea() << endl << endl;
        }
};


int main(){

    float length, width, radius;
    cout << "Enter the length of square: ";
    cin >> length;

    // Square sq;
    // cout << sq.getPerimeter(length) << endl << endl;

    // count square perimeter and area
    Square sq1(length);
    // cout << "Perimeter = " << sq1.getPerimeter() << endl << endl;
    // cout << "Area = " << sq1.getArea() << endl << endl;
    sq1.print();

    // count rectangular perimeter and area
    cout << "Enter the length of rectangular: ";
    cin >> length;
    cout << "Enter the width of rectangular: ";
    cin >> width;
    Rectangular rec(length, width);
    rec.print();

    // count  length and area of circle
    cout << "Enter the radius of circle: ";
    cin >> radius;
    Circle c(radius);
    c.print();
    

    return 0;

}