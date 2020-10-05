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
int  dx []    =  { -1 ,  0,  1,  0,  -1, -1, 1,  1};
int  dy []    =  { 0 ,  1,   0, -1,  -1,  1, 1, -1};
char dir[]    =  {'U', 'R', 'D','L' };
/* ------------------------------------------------------- */
const int maxn = 200005;
struct edge
{
    int a,b,w;
};
int par[maxn] , siize[maxn];
int find_par(int x)
{
    if(x==par[x])return x;
    return par[x] = find_par(par[x]);
}
void uni(int x,int y)
{
    int px = find_par(x) , py = find_par(y);
    if(px!=py)
    {
        if(siize[px]>siize[py])
            swap(px,py);
        par[px] = py;
        siize[py] += siize[px];
        siize[px]=0;
    }
}

edge edges[maxn];
bool comp(edge A , edge B)
{   
    return A.w < B.w; 
}

vector<int> vis(maxn , 0);
vector<int> adj[maxn];
void dfs(int n)
{
    vis[n] = 1;
    for(int x:adj[n])
        if(!vis[x])
            dfs(x);
}
void solve(int tc)
{
    int n,i,j,k,m,q;
    cin>>n>>m;
    repv(i,1,n)
        par[i] = i , siize[i] =1;

    int ans=0;
    rep(i,m)
    {
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
        adj[edges[i].a].pb(edges[i].b);
        adj[edges[i].b].pb(edges[i].a);
    }
    int cnt=0;
    repv(i,1,n)
    {
        if(!vis[i])
        {
            cnt++;
            dfs(i);
        }
    }
    if(cnt>1)
    {   cout<<"IMPOSSIBLE";
        return;
    }
    set<int> temp;
    sort(edges,edges+m,comp);
    vector<pii> val;
    rep(i,m)
    {
        if(find_par(edges[i].a)!=find_par(edges[i].b))
        {
            uni(edges[i].a , edges[i].b);
            temp.insert(edges[i].a);
            temp.insert(edges[i].b);
            ans += edges[i].w;
            val.pb({edges[i].a ,edges[i].b});
        }
    }
    if(sz(temp)!=n)
        cout<<"IMPOSSIBLE";
    else
        cout<<ans<<endl;
}
signed main()
{
    int t=1;
    //  cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
    return 0;
}