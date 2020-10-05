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
const int maxn = 100005;
//  ------------------------------------------------------------------
vector<int> vis(maxn);
vector<int> dist(maxn);
vector<int> adj[maxn];
vector<int> parent(maxn);

void bfs(int n)
{
    queue<int> q;
    vis[n] = 1;
    dist[n] = 0;
    q.push(n);
    parent[n] = n;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int x:adj[v])
        {
            if(!vis[x])
            {
                vis[x] =1;
                dist[x] = dist[v] + 1;
                q.push(x);
                parent[x] = v;
            }
        }
    }
}
void solve()
{
    int n,i,j,k,m;
    vis.assign(maxn , 0);
    dist.assign(maxn , -1);

    cin>>n>>m;
    rep(i,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    bfs(1);
    if(dist[n]==-1)
        cout<<"IMPOSSIBLE"<<endl;
    else
    {   
        cout<<dist[n]+1<<endl;
        vector<int> path;
        for(i=n; i!=1; i = parent[i])
            path.pb(i);
        path.pb(1);
        reverse(all(path));
        for(int x:path)
            cout<<x<<" ";
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
