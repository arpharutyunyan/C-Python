#include <iostream>

using namespace std;

const int row = 9;
const int col = 9;

//weight
const int incidence[row][col] = {
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


const string cities[9] = {"ashtarak", "yerevan", "gyumri", "artashat", "yeghvard", "talin", "aparan", "abovyan", "oshakan"};

int weights[row] = {};

bool checked[row] = {}; // first the all cityies is not checked

int passed_way[row] = {0};
