#include <iostream>
#include <climits>
#include "pq_dijkstra.h"
#include "requirements.h"

using namespace std;

int get_index(const char* city, const string cities[], int row){
    /*
        Get index for given city in array

        params ->   name of city from command line
                    array with all cities name
                    size of given array    

        return ->   index, if city exists in array
                    -1, if city does not exist in array 
    */

    for(int i=0; i<row; ++i){
        if(cities[i] == city){
            return i;
        }
    }

    return -1;
}

void fill_weights(){
    /*
        In first, array of weights must contain tha max integer
    */

    for(int i=0; i<row; i++){
        weights[i] = INT_MAX;
    }
}

void fill_checked(){
    /*
        In first, array of checked must contain tha false value
    */

    for(int i=0; i<row; i++){
        checked[i] = false;
    }
}

void print_passed_way(int start_index, int finish_index){
    /*
        Print passed way from destination to start city
        passed_way array contains the number of city index which changed that city in which index is stand  

        params ->   index of start city
                    index of destination city   
    */
    
    while (finish_index!=start_index){
        cout << cities[finish_index] << " -> ";
        finish_index = passed_way[finish_index];
    }
    cout << cities[start_index] << endl << endl;
}



void priority_queue(int start_index, int finish_index){
    /*
        Add (city index as key, weight as value) pair in priority queue

        params ->   index of start city
                    index of destination city  
    */

    Priority_queue_map pq;

    pq.add_with_value(start_index, 0); // add first pair

    while (!pq.isEmpty()){

        Node pop = pq.pop();
        checked[pop.key] = true; // add to checked array

        for (int i=0; i<col; ++i){
           if(incidence[pop.key][i] > 0){
        
                if(!checked[i] ){
                    
                    int value = weights[pop.key] + incidence[pop.key][i]; // update value for weights
                    if(value < weights[i]){
                        weights[i] = value;
                        passed_way[i] = pop.key;
                    }
                    
                    if(i != finish_index){
                        pq.add_with_value(i, weights[i]); 
        
                        pq.insert_sort_swap();
                       
                    }
                    
                }          
            }
        }

    }
}