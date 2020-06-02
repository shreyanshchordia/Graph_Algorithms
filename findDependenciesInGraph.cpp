// Problem Statement in the URL below (DFS Question)
// https://www.geeksforgeeks.org/find-dependencies-of-each-vertex-in-a-directed-graph/

#include <iostream>
#include <cstring>
using namespace std;

void add_edge(int** matrix, int x, int y){
    matrix[x][y] = 1;
}

void print(int** matrix, int V){
    for(int i = 0; i<V; i++){
        for(int j = 0; j< V; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void DFS(int** matrix, int i, int* visited, int V){
    for (int j=0; j<V ; j++){
        if(visited[j]!=1 && matrix[i][j]==1){
            visited[j] = 1;
            DFS(matrix, j, visited, V);
        }
    }
    return;
}

int min_dependency(int** matrix, int V){
    int dependency[V] = {0};
    for(int i=0;i<V;i++){
        int visited[V] = {0};
        visited[i] = 1;
        DFS(matrix, i, visited, V);
        int count = 0;
        for(int i=0;i<V;i++) if(visited[i]==1) count++;
        dependency[i] = count-1;
    }
    int minimum = 1e+5;
    for(int i=0;i<V;i++){
        minimum = min(minimum, dependency[i]);
    }
    return minimum;
}

int main(){
    int V;
    cin>>V;
    int** matrix = new int*[V];
    for(int i=0;i<V;i++){
        matrix[i] = new int[V];
        memset(matrix[i],0,V*sizeof(int));
    }
    add_edge(matrix, 0, 1);
    add_edge(matrix, 0, 2);
    add_edge(matrix, 2, 3);
    add_edge(matrix, 4, 5);
    add_edge(matrix, 3, 4);
    add_edge(matrix, 1, 5);
    cout<<(min_dependency(matrix, V));
}
