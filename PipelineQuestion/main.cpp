#include <iostream>
#include <cstring>
using namespace std;

int dir_ref[4][2]=  {
                        {0,-1},
                        {-1,0},
                        {0, 1},
                        {1, 0}
                    };

int in_out[8][2][4] = {
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },{
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    },{
        {0, 1, 0, 1},
        {0, 1, 0, 1}
    },{
        {1, 0, 1, 0},
        {1, 0, 1, 0}
    },{
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    },{
        {1, 1, 0, 0},
        {0, 0, 1, 1}
    },{
        {0, 1, 1, 0},
        {1, 0, 0, 1}
    },{
        {0, 0, 1, 1},
        {1, 1, 0, 0}
    }
};

class Queue{
    int* x_q;
    int* y_q;
    int* d_q;
    int f;
    int b;
    public:
    Queue(int val){
        this->x_q = new int[val];
        this->y_q = new int[val];
        this->d_q = new int[val];
        this->f = 0;
        this->b = -1;
    }

    void pop(int &x, int &y, int& d){
        if(this->b < this->f){
            x = -1;
            y = -1;
            d = -1;
            cout<<this->f<<" "<<this->b<<endl;
        }
        else{
            x = this->x_q[(this->f)];
            y = this->y_q[(this->f)];
            d = this->d_q[(this->f)++];
            //cout<<this->f<<" "<<this->b<<endl;
            return;
        }
    }

    void push(int x, int y, int d){
        this->x_q[++(this->b)] = x;
        this->y_q[(this->b)] = y;
        this->d_q[(this->b)] = d;
        //cout<<this->f<<" "<<this->b<<endl;
        return;
    }

    int empty(){
        if(this->b < this->f){
            return 1;
        }
        else{
            return 0;
        }
    }
};


void print(int** matrix, int row, int col){
    for(int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    return;
}

void find_directions(int* arr, int** matrix, int** visited, int x, int y, int row, int col){
    for(int i=0;i<4;i++){
        int a = (x + dir_ref[i][0]);
        int b = (y + dir_ref[i][1]);
        if((0<= a  && a < row) && (0<= b && b < col)){
            if(visited[a][b] == 1) continue;
            else{
                if(in_out[matrix[a][b]][0][i] && in_out[matrix[x][y]][1][i]){
                    arr[i] = 1;
                }
            }
        }
    }
}

int find_paths(int** matrix, int row, int col, int start, int end, int depth){
    int** visited = new int*[row];
    for(int i=0 ; i<row; i++){
        visited[i] = new int[col];
        for(int j=0;j<col;j++){
            visited[i][j] = 0;
        }
    }

    Queue q(row*col + 1);

    q.push(start, end, depth); // start
    visited[start][end] = 1;

    while(!q.empty()){
        int a = 0, b = 0, c = 0;
        q.pop(a, b, c);
        if((c-1)>0){
            int arr[4] = {0};
            find_directions(arr, matrix, visited, a, b, row, col);
            for(int i=0;i<4;i++){
                if(arr[i]==1){
                    int x = a + dir_ref[i][0];
                    int y = b + dir_ref[i][1];
                    visited[x][y] = 1;
                    q.push(x, y, c-1);
                }
            }
        }
        else continue;
    }

    int count = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            count+= visited[i][j];
        }
    }

    return count;
}

int main(){
    int t; cin>>t;
    while(t--){
        int row, col, x, y, probe; 
        cin>>row>>col>>x>>y>>probe;
        
        // making matrix
        int** matrix = new int* [row];
        for(int i=0;i<row;i++){
            matrix[i] = new int[col];
        }

        // taking input
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin>>matrix[i][j];
            }
        }

        // calculating reachable elements
        if(matrix[x][y]==0) cout<<0<<endl;
        else
            cout<<find_paths(matrix, row, col, x, y, probe)<<endl;
    }
}
