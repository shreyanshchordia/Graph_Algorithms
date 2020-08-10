#include <iostream>
using namespace std;

long m = 1000000007;

string func(long long a, long long b){

    string s;
    if(a%b == 0){
        s = "1";
        while(a != 1){
            s += "0";
            a--;
        }
    }

    else{
        string r;
        r = func(b % m, a%b % m);
        int multiple = a/r.size();
        int remainder = a%r.size();
        for(int i=0; i<multiple; i++){
            s += r;
        }
        s += r.substr(0, remainder);
    }
    return s;
}

long long binary_to_digit(string s){
    long long x = 0;
    long long index = 1;
    for(int i=s.size()-1; i>=0; i--){
        x += ((int)(s[i] - '0') % m * index) % m;
        index = (index*2) % m;
    }

    return x % m;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a, b;
        cin>>a>>b;

        cout<<binary_to_digit(func(a % m, b % m))<<"\n";
    }
}
