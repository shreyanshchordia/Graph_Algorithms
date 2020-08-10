#include <iostream>
#include <cstring>
using namespace std;

bool isSafe(bool** arr, int i, int j, int n){

    int check[8][2] = {{1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}};
    int a, b;
    for(int x=0; x<8; x++){
        a = i;
        b = j;
        while((a<n && a>= 0) && (b<n && b>=0)){
            if(arr[a][b] != 0) return 0;
            else{
                a += check[x][0];
                b += check[x][1];
            }
        }
    }
    return 1;
}

int n_queen(bool** arr, int i, int n){
    for(int j=0; j<n; j++){
        if(isSafe(arr, i, j, n)){
            arr[i][j] = 1;
            if(i == n-1) return 1;
            int x = n_queen(arr, i+1, n);
            if(x == 1) return 1;
            else{
                arr[i][j] = 0;
                continue;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;

    bool** arr = new bool*[n];
    for(int i=0; i<n; i++){
        arr[i] = new bool[n];
        memset(arr[i], 0, sizeof(arr[i][0]) * n);
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    int answer = n_queen(arr, 0, n);
    if(answer == -1){
        cout<<"Not possible"<<endl;
        return 0;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}
