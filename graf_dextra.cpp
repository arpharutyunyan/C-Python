#include <iostream>
#include "priority_queue_map.cpp"

using namespace std;

int main(){

    int row = 9;
    int col = 9;

    Priority_queue_map map;

    //weight
    int incidence[row][col] = {
      // 0  1  2  3  4  5  6  7  8
        {0, 5, 0, 0, 0, 0, 45, 0, 15}, //0    Ashtarak
        {5, 0, 0, 0, 0, 0, 0, 12, 0}, //1    Yerevan
        {0, 0, 0, 20, 0, 60, 0, 0, 0}, //2    Gyumri
        {0, 0, 20, 0, 60, 0, 40, 0, 0}, //3    Atashat
        {0, 0, 0, 60, 0, 0, 0, 30, 0}, //4    Yeghvard
        {0, 0, 60, 0, 0, 0, 25, 0, 30}, //5    Talin
        {45, 0, 0, 40, 0, 25, 0, 70, 0}, //6    Aparan
        {0, 12, 0, 0, 30, 0, 70, 0, 0}, //7    Abovyan
        {15, 0, 0, 0, 0, 30, 0, 0, 0}, //8    Oshakan
    };


    int relation[row][col] = {
      // 0  1  2  3  4  5  6  7  8  j
        {0, 1, 0, 0, 0, 0, 1, 0, 1}, //0    Ashtarak  i
        {1, 0, 0, 0, 0, 0, 0, 1, 0}, //1    Yerevan
        {0, 0, 0, 1, 0, 1, 0, 0, 0}, //2    Gyumri
        {0, 0, 1, 0, 1, 0, 1, 0, 0}, //3    Atashat
        {0, 0, 0, 1, 0, 0, 0, 1, 0}, //4    Yeghvard
        {0, 0, 1, 0, 0, 0, 1, 0, 1}, //5    Talin
        {1, 0, 0, 1, 0, 1, 0, 1, 0}, //6    Aparan
        {0, 1, 0, 0, 1, 0, 1, 0, 0}, //7    Abovyan
        {1, 0, 0, 0, 0, 1, 0, 0, 0}, //8    Oshakan
    };

    string cities[9] = {"ashtarak", "yerevan", "gyumri", "artashat", "yeghvard", "talin", "aparan", "abovyan", "oshakan"};


    // show realtion
    for(int i=0; i<row; i++){

        cout << cities[i] << "  -> [";
        for(int j=0; j<col; j++){

            
            if(relation[i][j] > 0){
                cout << cities[j] << ", ";
            }
            
        }

        cout << "]" << endl << endl;
        
    }

    // add to priority queue
    for(int i=0; i<row; i++){

        for(int j=0; j<col; j++){

            
            if(incidence[i][j] > 0){
               
                map.add_with_value(i, incidence[i][j]);
            }
            
        }        
    }

    map.print();

    return 0;
}

