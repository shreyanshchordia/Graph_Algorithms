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
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define endl '\n'
#define deb(x) cout<<#x<<" = "<<x<<endl
#define gcd __gcd
#define inf LLONG_MAX
#define minf LLONG_MIN 
const int mod = (int)(1e9+7);
const int maxn = 200005;
 
/* ------------------------------------------------------- */
 
 
int n,m;
vector<int> parent(maxn , -1);
vector<int> vis(maxn ,0);
vector<int> adj[maxn];
vector<int> color(maxn , 0);
int  cycle_start=-1 ,cycle_end=-1;
bool dfs(int n)
{
    vis[n] = 1;
    color[n] = 1;
    for(int x:adj[n])
    {
        if(!vis[x])
        {
            parent[x] = n;
            if(dfs(x))
                return true;
        }
        else
        if(color[x]==1)
        {
            cycle_start = x;
            cycle_end = n;
            return true;
        }
    }
    color[n] = 2;
    return false;
}
void solve()
{
    int n,m,i,j,k;
    cin>>n>>m;
    rep(i,m)
    {   
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
 
    repv(i,1,n)
    {
        if(!vis[i] && dfs(i))
        {
            vector<int> cycle;
            cycle.pb(cycle_start);
            int p = cycle_end;
            while(p!=cycle_start)
            {
                cycle.pb(p);
                p = parent[p];
            }
            cycle.pb(cycle_start);
            reverse(all(cycle));
            cout<<sz(cycle)<<endl;
            for(int x:cycle)
                cout<<x<<" ";
            break;
        }
    }
    cout<<"IMPOSSIBLE";
}   
signed main()
{
    RAGE;
    int t=1;
    //  cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
