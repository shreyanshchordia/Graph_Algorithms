#include <iostream>
using namespace std;

class Point{
    public:
    int x;
    int y;
    Point(){
        x = -1;
        y = -1;
    }
    Point(int a, int b){
        x = a;
        y = b;
    }
};

Point generate_neighbour(char** char_arr, Point& p, int n, int m, int i){
    int arr[4][2] = {
              {1, 0},
              {0, -1},
              {0, 1},
              {-1, 0},
    };

    Point new_p;
    if ((p.x + arr[i][0] >=0 && p.x + arr[i][0] < n) && (p.y + arr[i][1] >=0 && p.y + arr[i][1] < m) && char_arr[p.x + arr[i][0]][p.y + arr[i][1]]== '.'){
        new_p.x = p.x + arr[i][0];
        new_p.y = p.y + arr[i][1];
        return new_p;
    }

    else return new_p;
}

class Node{
    public:
    Node* next;
    Point p;
    Node(){
        next = NULL;
    }
    Node(int x, int y){
        p.x = x;
        p.y = y;
        next = NULL;
    }
};

class Queue{
    Node* first;
    public:
    Queue(){
        first = NULL;
    }
    void add(Point p){
        if(first == NULL){
            Node* newnode = new Node(p.x, p.y);
            first = newnode;
            return;
        }
        else{
            Node* temp = first;
            while(temp->next!= NULL){
                temp = temp->next;
            }
            Node* newnode = new Node(p.x,p.y);
            temp->next = newnode;
            return;
        }
    }

    Point pop(){
        if (first == NULL) return  Point();

        else{
            Point x = first->p;
            first = first->next;
            return x;
        }

    }

    bool isEmpty(){
        if (first == NULL) return 1;
        else return 0;
    }
};

void BFS(char** arr, Point** prev_arr, Point& start, Point& end, int n, int m){

    if(arr[start.x][start.y] == '#' || arr[end.x][end.y] == '#'){

        cout<<"Impossible"<<"\n";
        return;
    }

    Queue q;
    q.add(start);
    while(!q.isEmpty()){
        if(arr[end.x][end.y] == '#') break;

        Point current = q.pop();

        if(arr[current.x][current.y] == '.'){
            
            for(int i=0; i<4; i++){
                Point neighbour = generate_neighbour(arr, current, n, m, i);
                if (neighbour.x == -1 && neighbour.y == -1 ||
                    (prev_arr[neighbour.x][neighbour.y].x != -1 &&
                    prev_arr[neighbour.x][neighbour.y].y != -1)) continue;

                else{
                    q.add(neighbour);
                    prev_arr[neighbour.x][neighbour.y].x = current.x;
                    prev_arr[neighbour.x][neighbour.y].y = current.y;
                }
            }
            arr[current.x][current.y] = '#';
        }

        else continue;
    }
    if (arr[end.x][end.y] == '#'){
        string s = "";

        int x = end.x;
        int y = end.y;
        // cout<<x<<" "<<y<<"\n";
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<prev_arr[i][j].x<<","<<prev_arr[i][j].y<<" | ";
        //     }
        //     cout<<endl;
        // }
        while(prev_arr[x][y].x != -1 && prev_arr[x][y].y != -1){

            int prev_x = prev_arr[x][y].x;
            int prev_y = prev_arr[x][y].y;
            if(prev_x == x && prev_y == y-1) s += 'R';
            else if(prev_x == x-1 && prev_y == y) s += 'D';
            else if(prev_x == x && prev_y == y+1) s += 'L';
            else s += 'U';

            x = prev_x;
            y = prev_y;
        }

        for(int i=s.size() -1; i>=0; i--){
            cout<<s[i];
        }
        cout<<"\n";
        return;
    }

    else{
        cout<<"Impossible"<<"\n";
        return;
    }
}

void output_path(char** arr, Point &start, Point &end, int n, int m){

    Point** prev_arr = new Point* [n];
    for(int i=0; i<n; i++) prev_arr[i] = new Point[m];

    BFS(arr, prev_arr, start, end, n, m);
    return;
}

int main(){
    int n, m;
    cin>>n>>m;

    char** arr = new char*[n];
    for(int i=0; i<n; i++) arr[i] = new char[m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>arr[i][j];
    
    int t;
    cin>>t;

    Point start;
    Point end;

    for(int i=0; i<t; i++){
        char** t_arr = new char*[n];
        for(int i=0; i<n; i++) t_arr[i] = new char[m];

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                t_arr[i][j] = arr[i][j];

        cin>> start.x>> start.y>> end.x>> end.y;
        start.x --;
        start.y --;
        end.x --;
        end.y --;
        output_path(t_arr, start, end, n, m);

    }


}
