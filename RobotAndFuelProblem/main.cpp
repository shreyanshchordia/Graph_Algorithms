#include <iostream>
#include <time.h>
#include <cstring>
using namespace std;
#define GASOLINE 1
#define DIESAL 2

void initialize(int* arr, int n){
    memset(arr, 0, sizeof(arr[0]) * n);
    return;
}

void generate_neighbours(int* target, int* space, int* visited, int N, int x, int probe, bool gasoline){
    // From gasoline station  robot  has to visit one gasoline car.
    // Similarly from diesal station robot has to visit one diesal car. 
    // From a car, robot  can either go to similar car,
    // or gasoline station,
    // or diesal station.
    if ( x!= 0 && x!= N-1){
        if(probe != 0){
            int check = 0;
            if (gasoline == true) check = GASOLINE;
            else check = DIESAL;
            for(int i=1;i<N-1;i++){
                if(space[i] == check && visited[i] == 0){
                    target[i] = 1;
                }
            }
        }
        if (visited[0] == 0) target[0] = 1;
        if (visited[N-1] == 0) target[N-1] = 1;
    }
    else{
        int check;
        if (x==0) check = GASOLINE;
        else check = DIESAL;
        for(int i=1;i<N-1;i++){
            if(space[i] == check && visited[i] == 0){
                target[i] = 1;
            }
        }
    }
    return;
}

void need_at_gas_stations(int* space, int* visited, int N){
    // if all diesal cars fueled, then visited[N-1] = 1
    // if all gasoline cars fueled, then visited[0] = 1
    bool check = true;
    if(visited[0] == 0){
        for(int i=1;i<N-1;i++){
            if((space[i] == GASOLINE) && visited[i] != 1) {
                check = false;
                break;
            }
        }
        if(check == true) visited[0] = 1; 
    }
    
    check = true;
    if(visited[N-1] == 0){
        for(int i=1;i<N-1;i++){
            if((space[i] == DIESAL) && visited[i] != 1) {
                check = false;
                break;
            }
        }
        if(check == true) visited[N-1] = 1; 
    }
    return;
}

int DFS(int* space, int* visited, int N, int x, int cost, int probe, bool gasoline){
    // Evaluates walking distance for every  possible path
    int* neighbours = new int[N];
    initialize(neighbours, N);

    need_at_gas_stations(space, visited, N);
    
    if (visited[0] == 1 && visited[N-1] == 1) return cost;

    generate_neighbours(neighbours, space, visited, N, x, probe, gasoline);

    if (x == 0 || x == N-1){
        probe = 2;
        if (x==0) gasoline = true;
        else gasoline = false;
    }

    int min_cost = INT32_MAX;

    for(int i=0; i<N; i++){
        if(neighbours[i] == 1){

            int* passing_array = new int[N];
            initialize(passing_array, N);
            for(int j=0; j<N; j++) passing_array[j] = visited[j];

            if (i != 0 && i!= N-1)  passing_array[i] = 1;
            int val = DFS(space, passing_array, N, i, cost + abs(x - i), probe-1, gasoline);
            min_cost = min(min_cost, val);
            delete passing_array;
        }
    }

    return min_cost;
}


int find_optimum(int* space, int N){
    int start = 0;
    int cost = 0;
    int* visited = new int[N];
    initialize(visited, N);

    return DFS(space, visited, N, start, cost, 0, true);
}


int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;

        int* space = new int[n + 2];
        for(int i=1; i<=n; i++){
            cin>>space[i];
        }

        space[0] = 0;
        space[n+1] = 0;
        cout<< find_optimum(space, n+2);
    }
}
