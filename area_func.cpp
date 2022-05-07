#include <iostream>

using namespace std;

double area(double length_sq){
    
    return length_sq * length_sq;

}

double area(double r, string figure){
    //float P = 3.14;
    
    return (3.14 * (r *r));
}

double area(double length_rec, double width_rec){
    
    return length_rec * width_rec;
}

double area(double a, double b, bool figure){
    
    return (a * b) / 2;
}

int main()
{
    bool flag = true;
    while (flag)
    {
        // string did not work
        // assigned a default character, in case of continuation in line 60 (yes) "figure" does not keep the previous value
        char figure = ' ';

        cout<<"Which area do you whant? \n";

        while (figure != 's' && figure != 'r' && figure != 'c' && figure!= 't'){
            cout<<"Type the first small font of figure name: [Square, Rectangular, Circle, Ռight triangle] \n";
            cin>>figure;
        }

        switch(figure){
            case 's':{
                double length_sq;
                cout<<"Enter one leght: ";
                cin>>length_sq;
                double area_s = area(length_sq);
                cout<<"Square area is " << area_s <<endl;
                break;
            }
            case 'r':{
                double length_rec;
                double width_rec;
                cout<<"Enter length: ";
                cin>>length_rec;
                cout<<"Enter width: ";
                cin>>width_rec;
                double rectangular = area(length_rec, width_rec);
                cout<<"Rectangular area is "<< rectangular <<endl;
                break;
            }
            case 'c':{
                double r;
                cout<<"Enter the radius: ";
                cin>>r;
                string figure = "r";
                double circle = area(r, figure);
                cout<<"Result is: "<< circle <<endl;
                break;
            }
            case 't':{
                double a, b;
                cout<<"Enter the a: ";
                cin>> a;
                cout<<"Enter the a: ";
                cin>> b;
                bool figure = "t";
                double triangle = area(a, b, figure);
                cout<<"Result is: "<< triangle <<endl;
                break;
            }

            // in this case "default" does not make sense

            // default:
            //     cout<<"choose correct number!"<<endl;
        }

        string continued;
        
        while (continued != "yes" && continued != "no"){
            
            cout<<"Do you whant to continue:  yes/no \n";
            cin>>continued;
        }

        if (continued == "no"){
            flag = false;
        }
    }

    return 0;
}