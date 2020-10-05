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

const int maxn = 200005;
vector<int> adj[maxn];
vector<int> vis(maxn);
int num=0,n,m;
vector<int> indeg(maxn,0);
vector<int> res;
void kahn()
{   int i,j;
    queue<int> q;
    repv(i,1,n) if(!indeg[i])  q.push(i);
    while(!q.empty())
    {
        int cur = q.front();
        res.pb(cur);
        q.pop();
        for(int x:adj[cur])
        {
            indeg[x]--;
            if(!indeg[x])
                q.push(x);
        }
    }   
}   
void solve(int cnt)
{
    int i,j,k,q;
    cin>>n>>m;
    rep(i,m)
    {   int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        indeg[b]++;
    }   
    kahn();
    vector<int> dp(maxn,0);
    dp[n] = 1;
    for(i=sz(res)-1; i>=0; i--)
    {
        for(int x:adj[res[i]])
        {
            dp[res[i]] = (dp[res[i]] + dp[x])%mod;
        }
    }
    cout<<dp[1]%mod;
}
signed main()
{
    int t=1;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
    return 0;
}