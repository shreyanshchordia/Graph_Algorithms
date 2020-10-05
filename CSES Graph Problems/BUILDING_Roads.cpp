// PUSH YOUR LIMITS.!!
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long double ld;
#define int long long
 
#define RAGE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for(i=0; i <n; i++)
#define repv(i,k,n) for(i=k; i<n; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define endl '\n'
int mod = 1e9+7;
int power(int x,int n)
{   if(n==0)    return 1;
    if(n==1)    return x%mod;
    if(n%2==0)  {   int y = power(x,n/2)%mod;return (y*y)%mod;}
    if(n&1)     {   int y = power(x,n-1);return (x%mod * y%mod)%mod;}
    return 0;
}
int dx[]={-1 , 0 , 1 , 0};
int dy[]={ 0 , -1, 0 , 1};
const int maxn = 200005;
//  ------------------------------------------------------------------
int n,m;
vector<int> comp;
vector<int> vis(maxn ,0);
vector<int> adj[maxn];
vector<vector<int>> components;
 
void dfs(int n)
{
    vis[n] = 1;
    comp.pb(n);
    for(int x:adj[n])
    {
        if(!vis[x])
            dfs(x);
    }
}
 
void find_comp()
{
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            comp.clear();
            dfs(i);
            components.pb(comp);
        }
    }
}
 
void solve()
{
    int i;
    cin>>n>>m;
 
    int  a,b;
    rep(i,m)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    find_comp();
    cout<<(sz(components)-1)<<endl;
    if(sz(components)==1)
        cout<<0<<endl;
    else
    {
        for(i=1; i<sz(components); i++)
        {
            cout<<components[i-1][0]<<" "<<components[i][0]<<endl;
        }         
    }
}
signed main()
{
    RAGE;
        
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}