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
    int rowEnd = row - 1;
    int colStart = 0;
    int colEnd = col - 1;

    while(x <= row * col){

        for (int i = colStart; i <= colEnd and x <= row * col; i++){
            a[rowStart][i] = x++;
        }

        for(int i = rowStart + 1; i <= rowEnd and row * col; i++){
            a[i][colEnd] = x++;
        }

        for(int i = colEnd - 1; i >= colStart and row * col; i--){
            a[rowEnd][i] = x++;
        }

        for(int i = rowEnd - 1; i > rowStart and row * col; i--){
            a[i][colStart] = x++;
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