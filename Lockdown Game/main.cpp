
// The following is a recursion problem called the Lockdown Problem. LINK BELOW is where you can get the question from.
// https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/lockdown-game/description/

#include <iostream>
#include <cstring>
using namespace std;

int search(char* arr, int n){
    for(int i=0; i<n; i++){
        if(arr[i] == 'o') return i+1;
    }
    return -1;
}

int func(char* arr, long i, string s, long j, int n, int& d_size){
    if(d_size == 1) return search(arr, n);

    while(arr[i % n] != 'o') i++;

    if( s[j % s.size()] == 'x') 
        return func(arr, (i+1) % n, s, (j+1) % s.size(), n, d_size);

    else{
        arr[i % n] = '#';
        d_size--;
        return func(arr, (i+1) % n, s, (j+1) % s.size(), n, d_size);
    }
}

int main(){
    int n;
    string s;
    cin>>n>>s;

    char * arr = new char[n];

    memset(arr, 'o', sizeof(arr[0]) * n);

    long i = 0, j = 0;
    int dynamic_size = n;
    cout<<func(arr, i, s, j, n, dynamic_size)<<"\n";

}
