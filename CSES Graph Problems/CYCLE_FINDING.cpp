#include "bits/stdc++.h"
using namespace std;
typedef long double ld;
#define int long long
typedef pair<int,int> pii;
#define RAGE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for(i=0; i <n; i++)
#define repv(i,k,n) for(int i=k; i<=n; i++)
#define pb push_back
#define inf LLONG_MAX
/* ------------------------------------------------------- */
const int maxn = 200005;
struct edge
{
    int a,b,w;
};
edge edges[maxn];
int n,m;
vector<int> dis(maxn ,inf);
vector<int> par(maxn , -1);
void bellman_ford(int start)
{
    int i,j,x;
    dis[start]=0;
    rep(i,n)
    {
        x = -1; // to observe a change in the nth cycle. 
        rep(j,m)
        {
            if(edges[j].a == edges[j].b && edges[j].w < 0)
            {   cout<<"YES\n"; 
                cout<<edges[j].a<<" "<<edges[j].b; return;
            }
            if(dis[edges[j].a]!=inf && dis[edges[j].b]>dis[edges[j].a]+edges[j].w)
            {   
                dis[edges[j].b] = dis[edges[j].a] + edges[j].w;
                x = edges[j].b;
                par[edges[j].b] = edges[j].a;
            }
        }
    }
    if(x==-1)
    {   cout<<"NO";return;}
    
    repv(i,1,n)
    {
        x = par[x];
    }
    vector<int> cycle;
    int temp = x;
    while(1)
    {
        cycle.pb(temp);
        if(temp==x && sz(cycle)>1)
            break;
        temp = par[temp];
    }
    reverse(all(cycle));
    cout<<"YES"<<endl;
    for(int x:cycle)
        cout<<x<<" ";
 
}
void solve(int tc)
{
    int i,j,k;
    cin>>n>>m;
    rep(i,m)
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
    bellman_ford(edges[0].a);
}   
signed main()
{
    RAGE;
    int t=1;
    //  cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
    return 0;
}