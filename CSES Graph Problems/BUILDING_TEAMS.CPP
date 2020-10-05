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
const int maxn = 2000005;
//  ------------------------------------------------------------------
vector<int> vis(maxn);
vector<int> adj[maxn];
vector<int> color(maxn , -1);

bool dfs(int n ,int c)
{
    vis[n] = 1;
    color[n] = c;
    for(int x:adj[n])
    {
        if(!vis[x])
        {
            if(dfs(x,!c)==false)
                return false;
        }
        else
        if(color[n]==color[x])
            return false;
    }
    return true;
}

void solve()
{
    int n,i,j,k,m;
    cin>>n>>m;
    rep(i,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }    
    for(i=1; i<=n; i++)
    {
        if(!vis[i])
        {   
            if(dfs(i , 0)==false)
            {   cout<<"IMPOSSIBLE"; return;}
        }
    }
    for(i=1; i<=n; i++)
    {
        if(color[i])
            cout<<1<<" ";
        else
            cout<<2<<" ";
    }
}
signed main()
{
    RAGE;
    int t=1;
    //  cin>>t;
    while(t--)
        solve();

    return 0;
}

