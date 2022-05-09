/*Below we will define an n-interesting polygon. Your task is to find the area of a polygon for a given n.
A 1-interesting polygon is just a square with a side of length 1. An n-interesting polygon is obtained by taking 
the n - 1-interesting polygon and appending 1-interesting polygons to its rim, side by side. You can see the 1-, 2-, 3- 
and 4-interesting polygons in the picture below. 
For n = 2, the output should be 5
    n = 3                       13
    n = 5                       41
    n = 7000                    97986001
    n = 8000                    127984001
    n = 9999                    199940005
    n = 9998                    199900013
    n = 8999                    161946005
    n = 100                     19801
*/

#include <iostream>
using namespace std;

int solution(int n) {
    if(n == 1){
        return 1;
    }
    return 4 * (n - 1) + solution(n - 1);
}

int main(){

    int number = 0;
    cout << "Enter the number: ";
    cin >> number;

    int sq_count = solution(number);
    cout << "square count = " << sq_count << endl;
    return 0;
}