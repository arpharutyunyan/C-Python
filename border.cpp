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

    int sum = 0;

    for(int i = 0; i < row; i++){

        for(int j = 0; j < col; j++){

            if(i == 0 or i == row - 1 or j == 0 or j  == col - 1){
                cout << a[i][j]<< " ";
                sum += a[i][j];
           
            } else { 
                cout << " " << "  ";}
        }
        cout <<endl;

    }

    float average = sum / ((2 * (row + col)) - 4);
    cout << "Average = " << average << endl;

    return 0;

}