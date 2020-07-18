#include <iostream>
using namespace std;


class Queue{

    struct node{
        long data;
        node* next;
        node* prev;
    };
    node* start;

    public:
    Queue(){
        this->start = NULL;
    }

    void add(long x){

        node* newnode = new node;
        newnode->data = x;

        if(this->start == NULL){
            newnode->next = newnode;
            newnode->prev = newnode;
            this->start = newnode;
        }

        else{
            newnode->next = this->start;
            node* previous = this->start->prev;
            this->start->prev = newnode;
            previous->next = newnode;
            newnode->prev = previous;
        }

    }

    bool isempty(){
        if (this->start == NULL){
            return 1;
        }

        else return 0;
    }

    long pop(){
        if (isempty()){
            return -1;
        }

        if (start->next == start){
            long x = start->data;
            start = NULL;
            return x;
        }

        else{
            long x = start->data;
            start->next->prev = start->prev;
            start = start->next;
            start->prev->next = start;
            return x;
        }
    }

    void front(){
        if (isempty()) return;
        node* temp = start;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp!= start);
        cout<<"\n";
    }

    void reverse(){
        if (isempty()) return;
        node* temp = start->prev;
        do{
            cout<<temp->data<<" ";
            temp = temp->prev;
        }while(temp!= start->prev);
        cout<<"\n";
    }
};

long pow(int x, int y){
    long val = 1;
    for(int i=0; i<y; i++) val*= x;
    return val;
}

long get_value(int* arr, int n){
    long v = 0;
    int index = n-1;

    for(int i=0; i<n ; i++){
        v += (arr[i] * pow(10, index));
        index--;
    }

    return v;
}

int* get_arr(long v, int n){
    int* arr = new int[n];
    int index = n-1;
    while(v!=0){

        arr[index--] = v%10;
        v/=10;
    }

    return arr;
}

int* generate_neighbour(long v, int i, int n){
    int* temp = new int[n];
    int* arr = get_arr(v, n);

    for(int j=0; j<n; j++) temp[j] = arr[j];
        
    for(int j=0; j<=i; j++){
        temp[j] = arr[i - j];
    }
    return temp;
}

bool isgoal(int* ref, long v, int n){

    int prev = 100000;
    while(v!=0){
        int digit = (v%10 - 1);
        if(ref[digit] <= prev){
            prev = ref[digit];
        }
        else return 0;

        v/=10;
    }
    return 1;
}

long BFS(int* ref, bool* hashmap, Queue &q, Queue &cost, int n){

    while(!q.isempty()){
        long v = q.pop();
        long c = cost.pop();

        if(hashmap[v] == 1) continue;

        if (isgoal(ref, v, n)) return c;

        hashmap[v] = 1;
            
        for(int i=1; i<n; i++){
            int* temp = generate_neighbour(v, i, n);
            long temp_v  = get_value(temp, n);

            if (hashmap[temp_v] != 1){
                q.add(temp_v);
                cost.add(c+1);
            }
                
        }
    }

    return 0;
}

int find_minimum_moves(int* reference, int* arr, int n){

    long val = pow(10, n);

    // hashmap
    bool* hashmap = new bool[val];
    for(long i=0; i<val; i++) hashmap[i] = 0;

    // queue
    Queue q;
    Queue cost;
    long x = get_value(arr, n);
    q.add(x);
    cost.add(0);
    // BFS
    return BFS(reference, hashmap, q, cost, n);
}

int main(){

    int n;
    cin>> n;
    int* reference = new int[n];
    int* arr = new int[n];

    for(int i=0; i<n; i++){
        cin>> reference[i];
        arr[i] = i+1;
    }

    cout<<find_minimum_moves(reference, arr, n);

    return 0;
}
