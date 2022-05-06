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

    int x = 1;
    int rowStart = 0;
    int rowEnd = col - 1;
    int colStart = 0;
    int colEnd = row - 1;

    while(x <= row * col){

        for (int i = rowStart; i <= rowEnd and x <= row * col; i++){
            a[colStart][i] = x++;
        }

        for(int i = colStart + 1; i <= colEnd and row * col; i++){
            a[i][rowEnd] = x++;
        }

        for(int i = rowEnd - 1; i >= rowStart and row * col; i--){
            a[colEnd][i] = x++;
        }

        for(int i = colEnd - 1; i > colStart and row * col; i--){
            a[i][rowStart] = x++;
        }

        rowStart++;
        colStart++;
        rowEnd--;
        colEnd--;
    }
    
    

    // print  array
    for(int i = 0; i < row; i++){

        for(int j = 0; j < col; j++){
            
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    
    return 0;

}