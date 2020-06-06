#include <iostream>
#include <cstring>
using namespace std;
#define DEPTH 4

int dir_ref[6][2] = {
    { 1, 0},
    { 0, 1},
    { 0,-1},
    {-1, 0},
};

int even_ref[2][2] = {
    { 1, -1},
    { 1,  1}
};

int odd_ref[2][2] = {
    {-1, -1},
    {-1,  1}
};

int find_best_neighbour(int** space, int** visited,int& best_x, int& best_y, int x, int y, int row, int col, bool isodd){
    // selects best neighbour for a given point
    int temp = -1;
    for(int i=0; i<4; i++){
        int neighbour_x, neighbour_y;
        neighbour_x = x + dir_ref[i][0];
        neighbour_y = y + dir_ref[i][1];

        if( (0<= neighbour_x && neighbour_x < row) &&
            (0<= neighbour_y && neighbour_y < col) &&
            (space[neighbour_x][neighbour_y] != 0) &&
            (visited[neighbour_x][neighbour_y] == 0)){
            
            if (space[neighbour_x][neighbour_y] > temp){

                temp = space[neighbour_x][neighbour_y];
                best_x = neighbour_x;
                best_y = neighbour_y;
            }
        }
    }

    if(! isodd){

        for(int i=0;i<2;i++){
            int neighbour_x, neighbour_y;
            neighbour_x = x + even_ref[i][0];
            neighbour_y = y + even_ref[i][1];

            if( (0<= neighbour_x && neighbour_x < row) &&
                (0<= neighbour_y && neighbour_y < col) &&
                (space[neighbour_x][neighbour_y] != 0) &&
                (visited[neighbour_x][neighbour_y] == 0)){
                
                if (space[neighbour_x][neighbour_y] > temp){

                    temp = space[neighbour_x][neighbour_y];
                    best_x = neighbour_x;
                    best_y = neighbour_y;
                }
            }
        }
    }

    else if(isodd){
        for(int i=0;i<2;i++){
            int neighbour_x, neighbour_y;
            neighbour_x = x + odd_ref[i][0];
            neighbour_y = y + odd_ref[i][1];

            if( (0<= neighbour_x && neighbour_x < row) &&
                (0<= neighbour_y && neighbour_y < col) &&
                (space[neighbour_x][neighbour_y] != 0) &&
                (visited[neighbour_x][neighbour_y] == 0)){
                
                if (space[neighbour_x][neighbour_y] > temp){

                    temp = space[neighbour_x][neighbour_y];
                    best_x = neighbour_x;
                    best_y = neighbour_y;
                }
            }
        }
    }

    return temp;
}

int branching(int** space, int** visited, int row, int col, int d, int score){
    // selects the best neighbour for an already half visited path
    if (d == 0){
        return score;
    }

    int x, y;
    int temp = -1;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){

            if(visited[i][j] == 1){
                // finding the best neighbour for i,j
                int t_x, t_y; 
                int t = find_best_neighbour(space, visited, t_x, t_y, i, j, row, col, j%2);

                if ( t > temp){
                    // if best neighbour of i,j is better
                    // than best neighbour of previous i,j 
                    // then changing the final neighbour selection
                    temp = t; 
                    x = t_x;
                    y = t_y;
                }

            }
        }
    }

    visited[x][y] =1;
    score += space[x][y];

    return branching(space, visited, row, col, d-1, score);
}

int finding_optimum(int ** space, int row, int col){ 
    // finds optimum path of size DEPTH
    int optimum = 0;
    int** visited = new int*[row];
    for(int i=0; i<row; i++){
        visited[i] = new int[col];
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            
            if(space[i][j] != 0){
                
                for(int k=0; k<row; k++){
                    memset(visited[k], 0, col * sizeof(*visited[0])); 
                    // Starting with a new visited array for every point
                }

                visited[i][j] = 1;
                int score;
                int value = branching(space, visited, row, col, DEPTH-1, score=space[i][j]); 
                // Finds the best score when starting with the point i,j
                // Such that if we know the best score for every single i,j we know the best
                // score for the entire space.
                optimum = max(optimum, value);
            
            }

            else continue;
        }
    }

    return (optimum * optimum);
}

int main(){
    int t; cin>>t;
    while(t--){
        int row, col;
        cin>>row>>col;

        int** space = new int*[++row];
        for(int i=0;i<row;i++){
            space[i]  = new int[col];
            memset(space[i], 0, col * sizeof(*space[0]));
        }

        for(int i=0;i<row-1;i++){
            for(int j=0;j<col;j++){

                if(j%2 == 0) cin>> space[i][j];

                else cin>> space[i+1][j];
            }
        }

        cout<<finding_optimum(space, row, col)<<endl;
        
    }
}
