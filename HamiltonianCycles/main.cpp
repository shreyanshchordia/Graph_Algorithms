// finding hamiltonian cycles
// NOTE - Since I didnt't have test cases to try on, hence this code may fail on edge cases (0 filled arrays, {0,1} vertex graphs, etc)

#include <iostream>
#include <cstring>
using namespace std;

bool visited_all(int* visited, int V){ // checks if all points are visited

    for(int i=0; i<V; i++){
        if(visited[i] == 0) return false;
    }

    return true;
}

int add_path(int* path, int index, int V){ // adds a point to the path 
                                           // and returns index at which path is added
    for(int i=0; i<V; i++){
        if(path[i] == 0){
            path[i] = index + 1;
            return i;
        }
    }
    return -1; // should never reach here
}

// Using DFS algorithm. Hence Backtracking
int finding_paths(int** graph, int x, int* visited, int* path, int V, bool found, int& count){
    if (found){
        for(int i=0; i<V; i++){
            cout<<path[i]<<" ";
        }
        cout<<1<<endl;
        return ++count;
    }

    if (! visited_all(visited, V)){

        for(int i=0; i<V; i++){
            
            if(graph[x][i]==1 && visited[i] != 1){
                
                bool add;
                // establishing new path
                visited[i] = 1;
                int index = add_path(path, i, V);

                // moving ahead on the chosen path
                finding_paths(graph, i, visited, path, V, found, count);

                // backtracking 
                visited[i] = 0; 
                path[index] = 0;
            }
        }
    }

    else{
        if(graph[x][0] == 1){
            bool f;
            finding_paths(graph, x, visited, path, V, f=true, count);
        }
    }

    return count;
}

int main(){
    int t; cin>>t;
    while(t--){
        int V; cin>>V; // vertices

        int** graph = new int*[V];

        for(int i=0;i<V;i++){
            graph[i] = new int[V]; // building the graph
        }

        for (int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                cin>>graph[i][j]; // getting values for the graphs
            }
        }

        int* visited = new int[V];
        memset(visited, 0, V * sizeof(int)); // creating the visited array

        int* path = new int[V];
        memset(path, 0, V * sizeof(int)); // creating array for saving paths

        bool found = false;
        visited[0] = 1; // since we start from the first vertex, it is considered visited
        path[0] = 1; // framing the paths that will be found
        int count = 0;
        cout<<"\n"<<finding_paths(graph, 0, visited, path, V, found, count)<<" paths found!\n";
    }
}
