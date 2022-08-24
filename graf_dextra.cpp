#include <iostream>

using namespace std;

int main(){

    int row = 9;
    int col = 9;

    int relation[row][col] = {
      // 0  1  2  3  4  5  6  7  8
        {0, 1, 0, 0, 0, 0, 1, 0, 1}, //0    Ashtarak
        {1, 0, 0, 0, 0, 0, 0, 1, 0}, //1    Yerevan
        {0, 0, 0, 1, 0, 1, 0, 0, 0}, //2    Gyumri
        {0, 0, 1, 0, 1, 0, 1, 0, 0}, //3    Atashat
        {0, 0, 0, 1, 0, 0, 0, 1, 0}, //4    Yeghvard
        {0, 0, 1, 0, 0, 0, 1, 0, 1}, //5    Talin
        {1, 0, 0, 1, 0, 1, 0, 7, 0}, //6    Aparan
        {0, 1, 0, 0, 4, 0, 1, 0, 0}, //7    Abovyan
        {1, 0, 0, 0, 0, 5, 0, 0, 0}, //8    Oshakan
    };

    string cities[9] = {"ashtarak", "yerevan", "gyumri", "artashat", "yeghvard", "talin", "aparan", "abovyan", "oshakan"};

    for(int i=0; i<row; i++){

        cout << cities[i] << "  -> [";
        for(int j=0; j<col; j++){

            
            if(relation[i][j]!= 0){
                cout << cities[j] << ", ";
            }
            
        }

        cout << "]" << endl << endl;
        
    }

    return 0;
}

