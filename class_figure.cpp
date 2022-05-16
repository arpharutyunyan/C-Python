#include <iostream>
using namespace std;

class Square{

    private:
        float length;

    public:

        Square(float l){
            cout << "\n-----Constructor of square-----" << endl;
            length = l;
        }

        // Square(){
        //     cout << "---Non argument constructor---" << endl;
        // }

        float getPerimeter(){
            return 4 * length;
        }

        float getArea(){
            return length * length;
        }

        void print(){
            cout << "Perimeter = " << getPerimeter() << endl << endl;
            cout << "Area = " << getArea() << endl << endl;
        }
        
};

class Rectangular{
    private:
        float length, width;

    public:
        Rectangular(float l, float w){
            cout << "\n-----Constructor of rectangular-----" << endl;
            length = l;
            width = w;
        }

        float getPerimeter(){
            return 2 * (length + width);
        }

        float getArea(){
            return length * width;
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

    public:

        Circle(float r){
            cout << "\n-----Constructor of circle-----" << endl;
            radius = r;
        }

        float getLength(){
            return 2 * P * radius;
        }

        float getArea(){
            return P * radius * radius;
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