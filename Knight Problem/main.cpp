// KNIGHT PROBLEM 

#include <iostream>
using namespace std;

class move_{
    public:
    int x;
    int y;
    int c;
    move_(int r, int s, int t){
        x = r;
        y = s;
        c = t;
    }
    move_(){
        x = 0;
        y = 0;
        c = 0;
    }
};

class Queue{
    
    struct node{
        move_ val;
        node* next;

        node(){
            val = move_();
            next = NULL;
        }
        node(int x, int y, int z){
            val = move_(x, y, z);
            next = NULL;
        }
    };

    node* start;
    public:

    Queue(){
        start = NULL;
    }

    void push(int x, int y, int c){
        if(start == NULL){
            node* newnode = new node(x, y, c);
            start = newnode;
            return;
        }

        else{
            node* temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }

            node* newnode = new node(x, y, c);
            temp->next = newnode;
        }
    }

    move_ pop(){
        if(start == NULL){
            move_ v = move_();
            return v;
        }

        else{
            move_ v = move_(start->val.x, start->val.y, start->val.c);
            start = start->next;
            return v;
        }
    }

    bool isempty(){
        return (start == NULL);
    }

};

int get_neighbours(Queue &q, move_ m, int end_x, int end_y, int n, bool** visited){
    int x = m.x, y = m.y;
    int directions[8][2] = {
        {-2, -1},
        {-2,  1},
        {-1,  2},
        { 1,  2},
        { 2,  1},
        { 2, -1},
        { 1, -2},
        {-1, -2}
    };

    int i, j;

    for(int index=0; index < 8; index++){
        
        i = x + directions[index][0];
        j = y + directions[index][1];
        if(( i >= 0 && i<n ) && (j>=0 && j<n) && visited[i][j] != 1){
            visited[i][j] = 1;
            q.push(i, j, m.c + 1);
            if(i == end_x && j == end_y) return m.c + 1;
        }
    }

    return -1;
}

int main(){

    // t for testcase
    // n for board size
    int t, n;
    cin>>t>>n;
    
    while(t--){
        int start_x, start_y, end_x, end_y;
        cin>>start_x>>start_y>>end_x>>end_y;

        start_x--; start_y--; end_x--; end_y--;

        // making visited array

        bool** visited = new bool*[n];

        for(int i=0; i<n; i++){

            visited[i] = new bool[n];

            for(int j=0; j<n; j++){
                visited[i][j] = 0;
            }
        }

        // making queue for BFS
        bool flag = 0;

        Queue q;
        q.push(start_x, start_y, 0);

        while(!q.isempty()){

            move_ m = q.pop();

            // generating neighbours

            int i = get_neighbours(q, m, end_x, end_y, n, visited);

            if(i == -1) continue;

            else{
                cout<<i<<" MOVES NEEDED!";
                flag = 1;
            }
        }

        if(flag == 0) cout<<"NOT POSSIBLE";

        cout<<"\n";
    }
    return 0;
}

