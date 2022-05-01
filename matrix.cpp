#include <iostream>
#include <random>
using namespace std;

int main(){

    int row;
    int col;
    
    cout << "enter row ";
    cin >> row;
    cout << "enter col ";
    cin >> col;
    int a[row][col];

    //fillng array
    for(int i = 0; i < row; i++){

        for(int j = 0; j < col; j++){
            
            a[i][j] = rand() % 100;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl << endl << "Diagonal \n";
    
    // print array
    for(int i = 0; i < row; i++){
        cout << a[i][i] << " ";
    }

    cout << endl << endl;

    // Above of diagonal, summer of even numbers

    cout << " Average summer of numbers in above from diagonal \n";
    int sum_even = 0;
    int count = 0;

    for(int i = 0; i < row; i++){

        for(int j = i + 1; j < row; j++){
            cout << a[i][j]<<" ";

            if(a[i][j] % 2 == 0){
                //cout << a[i][j]<<" ";
                count++;
                sum_even += a[i][j];
            }
        }
        cout << endl;
    }

    float average_sum_even = sum_even / count;

    cout << "Average sum = " << average_sum_even << endl << endl;


    // Below of diagonal, summer of prime and positive numbers

    cout << "Below of diagonal, summer of prime and positive numbers \n";
    int sum = 0;

    for(int i = 0; i < row; i++){

        for(int j = 0; i > j; j++){

            if(a[i][j] > 0){
                bool is_prime = true;

                // check if the number is prime
                for(int num = 2; num < a[i][j]; num ++){
                    if(a[i][j] != num and a[i][j] % num == 0){
                        is_prime = false;
                        break;
                    }
                }

                if(is_prime){
                    //cout << a[i][j]<<" ";
                    sum += a[i][j];
                }
            }
            
            cout << a[i][j]<<" ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "sum of prime number is = " << sum << endl;

    return 0;
}