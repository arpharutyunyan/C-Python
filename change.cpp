#include <iostream>
using namespace std;

int main()
{
    int selected_number;
    float result;
    float amd;
    float USD = 476.0;
    float RUB = 6.20;
    float EUR = 525.0;
    float GBP = 627.0;
    cout<<"How much AMD do yot whant change? ";
    cin>>amd;
    cout<<"What do you whant?"<<endl;
    cout<<"1.USD,  2. RUB, 3.EUR, 4. GBP"<<endl;
    cin>>selected_number;
    switch (selected_number){
        case 1:
            result = amd / USD;
            break;
        case 2:
            result = amd / RUB;
            break;
        case 3:
            result = amd / EUR;
            break;
        case 4:
            result = amd / GBP;
            break;
    }
    cout<<"You can take "<<result;
    return 0;
}