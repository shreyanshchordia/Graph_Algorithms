#include <bits/stdc++.h>
#define ll long long
#define make(type,x) type x; cin>>x
#define make2(type,x,y) type x,y; cin>>x>>y
#define fr(x,y) for(long long x=0;x<y;x++)
#define INF (ll) 1e18
 
# define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
 
using namespace std;
 
ll n,m;
ll N=1e5+5;
vector <vector <pair <ll,ll> > >vec(N);
vector <ll> d(N,INF);
 
int main(){
    IOS;
    cin>>n>>m;
    fr(i,m){
        make2(ll,x,y); make(ll,len);
        vec[--x].push_back({--y,len});
    }
    d[0]=0;
    set <pair <ll,ll> > q;
    q.insert({0,0});
    while(!q.empty()){
        pair <ll,ll> f=*q.begin(); q.erase(q.begin());
        ll e=f.second;
        for(auto x : vec[e]){
            ll to=x.first; ll len=x.second;
            if(d[e]+len<d[to]){
                q.erase({d[to],to});
                d[to]=d[e]+len;
                q.insert({d[to],to});
            }
        }
    }
    fr(i,n) cout<<d[i]<<" ";
    cout<<endl;
    return 0;
}