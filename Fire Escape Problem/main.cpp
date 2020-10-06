https://www.codechef.com/problems/FIRESC
#include<bits/stdc++.h>
using namespace std;
vector<int>a[100001];
int vis[100001];
int m1;
//create adjecency list
void dfs(int node){
    vis[node]=1;
    m1++;
    for(int x:a[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n,e,x,y;
    cin>>n>>e;
    for(int i=1;i<=n;i++){
        vis[i]=0;
        a[i].clear();
    }
    long long int res=1;
   for(int i=1;i<=e;i++){
        cin>>x>>y;
        a[y].push_back(x);
        a[x].push_back(y);}
        int c=0;
        for(int i=1;i<=n;i++){
           // int m1=1;
            if(!vis[i]){
                 m1=0;
                dfs(i);
                  c++;
                  res=(res*m1)%(1000000007);
            }

        }
       cout<<c<<" "<<res<<endl;
    }
}
