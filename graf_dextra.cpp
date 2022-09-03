#include <iostream>
#include <climits>
// #include "pq_dijkstra.h"
// #include "requirements.h"
#include "functionality.h"

using namespace std;

int main(int argc, char** argv){

    if(argc == 2 and ((string)argv[1] == "-h" or (string)argv[1] == "--help")){

        cout << "<name of start city> <name of destination city> \n\n";
        cout << "Choose from this list\n[ashtarak, yerevan, gyumri, artashat, yeghvard, talin, aparan, abovyan, oshakan] \n\n";

    }else if(argc == 3){
    
        int start_index = get_index(argv[1], cities, row);  // get index for start city
        int finish_index = get_index(argv[2], cities, row); // get index for destination city

        if(start_index!= -1 and finish_index!=-1){

            // add first weights
            fill_weights();

            weights[start_index] = 0; // add first weight

            priority_queue(start_index, finish_index); //add priority queue and update weights
            
            print_passed_way(start_index, finish_index); // print finall way
        }else{
            cout << "Please check city. We can't find the given city!\n\n";
        }
        
    }else{
        cout << "Command is not correct.\nRun <-h> or <--help> for helping.\n\n";
    }

    return 0;
}