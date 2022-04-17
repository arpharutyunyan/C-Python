#include <iostream>
using namespace std;

int main()
{
    float result;
    
    float USD = 476.0;
    float RUB = 6.20;
    float EUR = 525.0;
    float GBP = 627.0;
    
    while (true)
    {
        float amd;
        
        cout<<"How much AMD do you whant to change? \n";
        cin>>amd;

        string selected_currency = ""; 
        while (selected_currency != "USD" && selected_currency != "RUB" && //
                selected_currency != "EUR" && selected_currency != "GBP")
        {
            cout<<"What do you whant? [USD, RUB, EUR, GBP] \n";
            cin>>selected_currency;
        }
        
        
        char currency = selected_currency[0];

        switch (currency){
        case 'U':
            result = amd / USD;
            break;
        case 'R':
            result = amd / RUB;
            break;
        case 'E':
            result = amd / EUR;
            break;
        case 'G':
            result = amd / GBP;
            break;
        }

        cout<<"You can take " << result<<endl;

        string any_change;
            
        while (any_change != "yes" && any_change != "no"){
            
            cout<<"Do you whant any currency:  yes/no \n";
            cin>>any_change;
        }

        if (any_change == "no"){
            break;
        }
    }
    
    return 0;
}