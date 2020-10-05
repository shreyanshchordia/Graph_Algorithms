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
/* ------------------------------------------------------- */
 
 
int n,m,k;
vector<pii> adj[maxn];
vector<int> dis[maxn];
 
void dijkstra(int start)
{
    priority_queue<pii ,vector<pii>,greater<pii>>  pq;
    pq.push({0,start});
    while(!pq.empty())
    {
        int cur = pq.top().S ,d_cur = pq.top().F; 
        pq.pop();
        if(sz(dis[cur]) >=k )
            continue;
        dis[cur].pb(d_cur);
        for(auto it:adj[cur])
        {
            int x = it.F , len = it.S;
            pq.push({d_cur+len , x});
        }
    }
}
void solve()
{
    int i,j;
    cin>>n>>m>>k;
    rep(i,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
    }
    dijkstra(1);
    i=0;
    for(int x:dis[n])
        cout<<x<<" ";
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