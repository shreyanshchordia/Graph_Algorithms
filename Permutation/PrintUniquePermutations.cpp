#include <iostream>
using namespace std;

void printPermutations(string s, int i){

    if (i==s.size()- 1){
        cout<<s<<"\n";
        return ;
    }

    char c = s[i];
    for(int j=i; j<s.size(); j++){
        
        if (s[i] != s[j] || i==j){
            s[i] = s[j];
            s[j] = c;
            printPermutations(s, i+1);
            s[j] = s[i];
            s[i] = c;
        }

        else continue;
    }

}

int main(){
    string s;
    cin>>s;

    printPermutations(s, 0);
}
