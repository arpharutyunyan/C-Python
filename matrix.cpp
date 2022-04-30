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

    for(int i = 0; i < row; i++){

        for(int j = 0; j < col; j++){
            
            a[i][j] = rand()%100;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    for(int i = 0; i < row; i++){

        // for(int j = 0; j < col; j++){
            
        //     if(i == j){
        //         cout << "diagonal " << a[i][j] << "\t";
        //     }
        // }

        cout << a[i][i] << " ";
    }

    return 0;
}