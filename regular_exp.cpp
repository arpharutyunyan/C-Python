#include <iostream>
#include <regex>
using namespace std;


int main(){

    // regex r("[a-zA-Z]*(news|lur|lra|jam)[a-z0-9_]*\\.am");

    // string link = "news_1.am";

    // smatch sm;

    // cout << regex_search(link, sm, r) << endl;



    regex r(" ( ( ( ( \\((\\+)?374\\) )|(\\+)?374))? (\\s)* ( ( \\([1-9]{2}\\) )|[1-9]{2}|( \\([0][1-9]{2}\\)|([0][1-9]{2}) )) (\\s)* ([0-9]{6}|((([0-9]{2}(\\-|\\s)){2}) [0-9]{2}) )");

    string link = "(+374) 94 41-41-41";

    // regex r("([A][A-Z][0-9]{7})|([0][0-9]{8})");
    // string pass = "005491980";

    smatch sm;

    cout << regex_search(link, sm, r) << endl;

    
    return 0;

}