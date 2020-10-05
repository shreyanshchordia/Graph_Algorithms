#include "bits/stdc++.h"
using namespace std;
typedef long double ld;
#define int long long
typedef pair<int,int> pii;
#define RAGE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for(i=0; i <n; i++)
#define repv(i,k,n) for(int i=k; i<=n; i++)
#define pb push_back
#define mp make_pair
#define F  first
#define S  second
#define sz(x)  (int)x.size()
#define all(v) v.begin(),v.end()
#define endl '\n'
#define inf   LLONG_MAX
#define minf  LLONG_MIN 
/* ------------------------------------------------------- */
const int maxn = 1e5;
struct edge
{
    int a,b,w;
};
int n,m;
edge edges[maxn];
vector<int> dis(maxn , inf);
vector<int> par(maxn , -1);
vector<int> adj1[maxn] , adj2[maxn];
vector<int> vis1(maxn) , vis2(maxn);

void dfs1(int start)
{
    vis1[start] = 1;
    for(int x:adj1[start])
        if(!vis1[x])dfs1(x);
}
void dfs2(int n)
{
    vis2[n] = 1;
    for(int x:adj2[n])
        if(!vis2[x])dfs2(x);
}
void bellman_ford(int start)
{
    int i,j;
    dis[start]=0;
    int x=-1;
    rep(i,n)
    {
        x = -1;
        rep(j,m)
        {
            if(dis[edges[j].a]!=inf && dis[edges[j].b]  > dis[edges[j].a] + edges[j].w && vis1[edges[j].a] && vis2[edges[j].b])
            {
                dis[edges[j].b] = dis[edges[j].a] + edges[j].w;
                x = edges[j].b;
                par[edges[j].b] = edges[j].a;
            } 
        }
    }
    if(x!=-1)
    {
        cout<<-1; return;
    }
    cout<<-1*(dis[n]);
}
void solve(int tc)
{
    int i,j,k,q;
    cin>>n>>m;
    rep(i,m)
    {
        cin>>edges[i].a>>edges[i].b>>edges[i].w  , edges[i].w *=-1;
        adj1[edges[i].a].pb(edges[i].b);
        adj2[edges[i].b].pb(edges[i].a);
    }
    dfs1(1);
    dfs2(n);
    bellman_ford(1);
}   
signed main()
{
    RAGE;
    //db();    
    int t=1;
    //  cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
    //timeit();
    return 0;
}