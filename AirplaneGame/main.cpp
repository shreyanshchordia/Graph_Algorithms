#include <iostream>
using namespace std;

#define NUM_DIRS 3
#define DETONATE_RANGE 5

int dir_ref[3] = {-1, 0, 1};


int** detonate(int** arena, int x, int row, int col){
    int** ar = new int*[row];
    for(int i=0;i<row;i++){
        ar[i] = new int[col];
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ar[i][j] = arena[i][j];
        }
    }

    for(int i=x+1;(i< row && i <= x + DETONATE_RANGE); i++){
        for(int j=0; j<col; j++){
            if (ar[i][j] == 2){
                ar[i][j] = 0;
            }
        }
    }
    return ar;
}


int find_max(int** arena, int x, int y, int row, int col, bool detonated, int score){
    if(arena[x][y] == 2) score = score - 1;
    else if(arena[x][y] == 1) score = score + 1;

    if(score < 0){
        return -1;
    }

    else if(x == (row-1)){
        return score;
    }

    int m = -2;

    if (! detonated){
        int** detonated_arena = detonate(arena, x, row, col);
        for(int i=0;i<NUM_DIRS;i++){
            if((y + dir_ref[i]) >= 0 && (y + dir_ref[i]) < col)
                m = max(m, find_max(detonated_arena,(x + 1), (y + dir_ref[i]), row, col, (!detonated), score));
        }
    }

    for(int i=0; i<NUM_DIRS;i++){
        if((y + dir_ref[i]) >= 0 && (y + dir_ref[i]) < col)
            m = max(m, find_max(arena,(x + 1), (y + dir_ref[i]), row, col, detonated, score));
    }
    return m;
}
int main(){
    int t; cin>>t;
    while(t--){
        int row;
        int col = 5;
        cin>>row;
        int** arena = new int*[++row];
        for(int i=0;i<row;i++){
            arena[i] = new int[col];
        }

        for(int i=row-1;i >=0;i--){
            for(int j=0;j<col;j++){
                if(i==0){
                    arena[i][j] = 0;
                }
                else
                    cin>>arena[i][j];
            }
        }

        int x = 0, y = 2;
        bool detonated = false;
        int score = 0;
        int goal = find_max(arena, x, y, row, col, detonated, score);   
        cout<<goal<<endl;
    }
}
