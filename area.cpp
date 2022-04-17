#include <iostream>

using namespace std;


int main()
{
    bool flag = true;
    while (flag)
    {
        // string did not work
        // assigned a default character, in case of continuation in line 60 (yes) "figure" does not keep the previous value
        char figure = ' ';

        cout<<"Which area do you whant? \n";

        while (figure != 's' && figure != 'r' && figure != 'c'){
            cout<<"Type the first small font of figure name: [Square, Rectangular, Circle] \n";
            cin>>figure;
        }

        switch(figure){
            case 's':{
                float length_sq;
                cout<<"Enter one leght: ";
                cin>>length_sq;
                cout<<"Square area is "<<length_sq * length_sq<<endl;
                break;
            }
            case 'r':{
                float length_rec;
                float width_rec;
                cout<<"Enter length: ";
                cin>>length_rec;
                cout<<"Enter width: ";
                cin>>width_rec;
                cout<<"Rectangular area is "<<length_rec * width_rec<<endl;
                break;
            }
            case 'c':{
                const float P = 3.14;
                float r;
                cout<<"Enter the radius: ";
                cin>>r;
                cout<<"Result is: "<<P * (r *r)<<endl;
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