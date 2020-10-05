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
const int maxn = 200005;
 
/* ------------------------------------------------------- */
 
 
 
int n,m;
vector<int> in_deg(maxn ,0);
vector<int> adj[maxn];
vector<int> res;
bool kahn(int n)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    repv(i,1,n)
        if(!in_deg[i])pq.push(i);
    while(!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        res.pb(cur);
        for(int x:adj[cur])
        {
            in_deg[x]--;
            if(!in_deg[x])
                pq.push(x);
        }
    }
    return sz(res)==n;
}
void solve()
{
    int i,j,k;
    cin>>n>>m;
    rep(i,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        in_deg[b]++;
    }
    if(kahn(n))
    {
        for(int x:res)
            cout<<x<<" ";
    }
    else
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
