#include <iostream>
#include <cstring>
using namespace std;
#define NUM_GATES 3
#define NUM_PATTERNS 6

void initialize(int* arr, int n){
    memset(arr, 0, sizeof(arr[0]) * n);
    return;
}


int patterns[NUM_PATTERNS][NUM_GATES] = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
};


int find_closest(int* visited, int index, int n, bool left){
    
    if(left){
        for(int i=index - 1; i>=0; i--){
            if(visited[i] == 0) return i;
        }
    }

    else{
        for(int i=index + 1; i<n; i++){
            if(visited[i] == 0) return i;
        }
    }

    return -1;
}


int edit_visited_and_cost(int* visited, int l, int r, int index){
    int cost;
    if(l == -1){
        visited[r] = 1;
        cost = (r - index);
    }

    else if(r == -1){
        visited[l] = 1;
        cost = (index - l);
    }

    else{
                
        if( (index - l) > (r - index) ){
            visited[r] = 1;
            cost = (r - index);
        } 
        else{
            visited[l] = 1;
            cost = (index - l);
        }
    }
    return cost;
}


int fill_visited(int* visited, int index, int c, int n){

    int cost = c;
    for(int i=0; i<c; i++){
        if(visited[index] == 0){
            visited[index] = 1;
        }

        else{
            bool left;
            int l = find_closest(visited, index, n, left=true);
            int r = find_closest(visited, index, n, left=false);
            cost += edit_visited_and_cost(visited, l, r, index);
        }
    }
    return cost;
}


int* get_array(int* visited, int index, int n){
    int* new_array = new int[n];
    for(int i=0; i<n; i++){
        new_array[i] = visited[i];
    }
    new_array[index] = 1;
    return new_array;
}

int get_score_for_pattern(int gates[NUM_GATES][2], int* visited, int* pattern, int move, int n, int val){

    if(move == NUM_GATES){
        return val;
    }

    int current_gate = gates[pattern[move]][0];
    int count = gates[pattern[move]][1];

    // for n-1 fisherman at the gate
    int cost = fill_visited(visited, current_gate, count-1, n);

    // for last fisherman
    bool left;
    int l = find_closest(visited, current_gate, n, left=true);
    int r = find_closest(visited, current_gate, n, left=false);

    if ( (current_gate - l) == (r - current_gate) ){
        cost += (current_gate - l) + 1;
        int* l_visited = get_array(visited, l, n);
        int* r_visited = get_array(visited, r, n);
        int final_left = get_score_for_pattern(gates, l_visited, pattern, move+1, n, (val + cost) );
        int final_right = get_score_for_pattern(gates, r_visited, pattern, move+1, n, (cost + val) );
        return min(final_left, final_right);
    }

    else{
        cost += (edit_visited_and_cost(visited, l, r, current_gate) + 1);
        return get_score_for_pattern(gates, visited, pattern, move+1, n, (val + cost));
    }
}


int find_cost(int gates[NUM_GATES][2], int* visited, int n){

    int optimum = INT32_MAX;

    for(int i=0; i<NUM_PATTERNS; i++){

        initialize(visited, n);
        int* pattern = patterns[i];
        int val = 0;
        val = get_score_for_pattern(gates, visited, pattern, 0, n, val);
        optimum = min(optimum, val);
    }
    return optimum;
}


int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        int gates[NUM_GATES][2];
        // 3 gates. 1st index for occurance, 2nd index for number of fisherman at the gate

        for(int i=0; i<NUM_GATES; i++){
            int x,y;
            cin>>x>>y;
            gates[i][0] = x-1; // index
            gates[i][1] = y; // count of fishermen at the ith gate
        }

        int* visited = new int[n];

        int val = find_cost(gates, visited, n);
        cout<<val<<endl;
    }
}
