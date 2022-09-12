#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Node{
    public:
        int value = 0;
        int key = 0;
        Node* previous = nullptr;
        Node* next = nullptr;
        Node(int k, int v){
            key = k;
            value = v;
        }
};

class Priority_queue_map{
    public:
        Priority_queue_map(){}

        int(* comparator)(int a, int b);
        Priority_queue_map(int(* c)(int a, int b)){
            comparator = c;
        }

        ~Priority_queue_map(){
            if(!isEmpty()){
                while (head!=tail){
                    head = head -> next;
                    delete head -> previous;
                }
                delete head;
            }
        }

    public:
        Node* head = nullptr;
        Node* tail = nullptr;
        int len = 0;
        Node* address_of_repeated_key = nullptr;

        bool isEmpty(){
            return head == nullptr;
        }

        void push_back(int k, int v){
            if(isEmpty()){
                head = tail = new Node(k, v);         // create the first element
                len++;
            }else if(find(k)){
                address_of_repeated_key -> value = v;    // check if keys repeated, change only the value
            }else{
                Node* node = new Node(k, v);
                tail -> next = node;
                node -> previous = tail;
                tail = node;
                len++;
            }
        }

        void push_front(int k, int v){
            if(isEmpty()){                   // create the first element
                head = tail = new Node(k, v);
                len++;
            }else if(find(k)){
                address_of_repeated_key -> value = v;    // check if keys repeated, change only the value
            }else{
                Node* node = new Node(k, v);
                head -> previous = node;
                node -> next = head;
                head = node;
                len++;
            }
        }

        Node pop(){
            Node deleted_head(head->key, head->value);  // in all cases return the value of that tail
            len--;
            if(head == tail){     // check the last element
                delete head;
                tail = head = nullptr;
                return deleted_head;
            }
            head = head -> next;
            delete head -> previous;
            head -> previous = nullptr;
            // cout << deleted_head.key << " : " << deleted_head.value << endl;
            return deleted_head;
        }

        bool find(int k){
            for(Node* node = head; node != nullptr; node = node -> next){
                if(comparator(k, node -> key) == 0){
                    address_of_repeated_key = node;   // save the adrress of repeated key
                    return true;
                }
            }
            return false;
        }

    public:

        void add_with_value(int k, int v){
            if(isEmpty()){
                push_back(k, v);
                return;
            }
            if(comparator(v, head->value) != 1){
                push_front(k, v);
            }else if(comparator(v, tail->value) != -1){
                push_back(k, v);
            }else{
                if(find(k)){
                    address_of_repeated_key->value = v;
                    return;
                }else{
                    Node* node = head;
                    Node* addedNode = new Node(k, v);
                    while (comparator(v, node->value) != -1){
                        node = node->next;
                    }
                    addedNode -> next = node;
                    addedNode -> previous = node->previous;
                    node -> previous -> next = addedNode;
                    node -> previous = addedNode;
                    len++;
                    return;
                }
            }
        }

        void insert_sort_swap(){
            if(head == tail){
                return;
            }
            for(Node* temp = head->next; temp!=nullptr; temp=temp->next){
                Node* pre = temp->previous;
                while (pre!=nullptr and comparator(pre->value, pre->next->value) == 1){
                    int v = pre->next->value;
                    int k = pre->next->key;
                    pre->next->value = pre->value;
                    pre->next->key = pre->key;
                    pre->value = v;
                    pre->key = k;
                    pre = pre->previous;
                }
            }
        }

        void print(){
            cout << "\nPrint result!!!! \n\n";
            for(Node* h = head; h != nullptr; h = h -> next){
                cout << h -> key << ":  " << h -> value << endl;
            }
            cout << endl << endl;
        }
};

const int row = 9;
const int col = 9;

//weight
const vector< vector<int> > incidence {
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

const vector<string> cities {"ashtarak", "yerevan", "gyumri", "artashat", "yeghvard", "talin", "aparan", "abovyan", "oshakan"};
vector<int> weights{};
vector<bool> checked{}; // first the all cityies is not checked
vector<int> passed_way{};

int get_index(const char* city, const vector<string> cities){
    /*
        Get index for given city in array
        params ->   name of city from command line
                    array with all cities name
                    size of given array
        return ->   index, if city exists in array
                    -1, if city does not exist in array
    */
    for(int i=0; i<cities.size(); ++i){
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
        weights.push_back(INT_MAX);
        // weights[i] = INT_MAX;
    }
}

void fill_checked(){
    /*
        In first, array of checked must contain tha false value
    */

    for(int i=0; i<row; i++){
        // checked[i] = false;
        checked.push_back(false);
    }
}

void fill_passed_way(){
    /*
        In first, array of passed_way must contain tha 0 value
    */

    for(int i=0; i<row; i++){
        // passed_way[i] = 0;
        passed_way.push_back(0);
           
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
    Priority_queue_map pq([](int a, int b){
        if(a > b){
            return 1;
        }else if(a == b){
            return 0;
        }else{
            return -1;
        }
    });

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

int main(int argc, char** argv){

    if(argc == 2 and ((string)argv[1] == "-h" or (string)argv[1] == "--help")){
        cout << "<name of start city> <name of destination city> \n\n";
        cout << "Choose from this list\n[ashtarak, yerevan, gyumri, artashat, yeghvard, talin, aparan, abovyan, oshakan] \n\n";
    }else if(argc == 3){

        int start_index = get_index(argv[1], cities);  // get index for start city
        int finish_index = get_index(argv[2], cities); // get index for destination city

        if(start_index!= -1 and finish_index!=-1){
            // add first weights
            fill_weights();
            fill_checked(); //fill checked array with false
            fill_passed_way();

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