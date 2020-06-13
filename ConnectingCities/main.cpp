#include <iostream>
#include <cstring>

using namespace std;


class road{

    public:
    long start;
    long end;
    long cost;

    void set(){
        cin>>this->start;
        cin>>this->end;
        cin>>this->cost;
        return;
    }

    // debug
    // void get(){
    //     cout<<this->start<<" "<<this->end<<" "<<this->cost;
    //     return;
    // }
    // debug

    // overriden
    void set(long x, long y, long z){
        this->start  = x;
        this->end = y;
        this->cost = z;
    }
};


void merge(road* array, long left, long mid, long right){

    long x = mid - left + 1;
    long y = right - mid;
    long i = 0, j = 0, k = 0;
    long size = x + y;

    road* merge_array = new road[size];

    while(i < x && j < y){

        if(array[left + i].cost > array[mid + 1 + j].cost){
            long temp = mid+j+1;
            merge_array[k].set(array[temp].start,
                               array[temp].end,
                               array[temp].cost);
            j++;
        }

        else{
            long temp = left + i;
            merge_array[k].set(array[temp].start,
                               array[temp].end,
                               array[temp].cost);
            i++;
        }

        k++;
    }

    while(i < x){
        long temp = left + i;
        merge_array[k].set(array[temp].start,
                           array[temp].end,
                           array[temp].cost);
        i++;
        k++;
    }

    while(j < y){
        long temp = mid + j + 1;
        merge_array[k].set(array[temp].start,
                           array[temp].end,
                           array[temp].cost);
        j++;
        k++;
    }

    for(int i=0; i<size; i++){
        array[left + i].set(merge_array[i].start,
                            merge_array[i].end,
                            merge_array[i].cost);
    }
}


void sort(road* array, long left, long right){

    if(left >= right){
        return;
    }
    
    long mid = (left + right)/2;

    sort(array, left, mid);

    sort(array, mid+1, right);

    merge(array, left, mid, right);

    return;
}


int main(){
    int t; cin>>t;
    while(t--){
        long n, m;
        cin>>n>>m;

        road* array = new road[m];

        for(int i=0; i<m; i++){
            array[i].set();
        }

        int* visited = new int[n];
        memset(visited, 0, n * sizeof(visited[0]));

        cout<<endl;

        // debug
        // for(int i=0; i<m; i++){
        //     array[i].get();
        //     cout<<endl;
        // }
        // debug

        // Kruskal's Algo
        sort(array, 0, m-1);
        long cost = 0;
        for(int i=0; i<m; i++){
            if (visited[array[i].start - 1] == 0 || visited[array[i].end - 1] == 0){
                    cost += array[i].cost;
                    visited[array[i].start - 1] = 1;
                    visited[array[i].end - 1] = 1;
                }
        }

        cout<<cost<<endl;
        
    }
}
