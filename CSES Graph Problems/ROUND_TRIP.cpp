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
#define fill(x , a) x.assign(a)
#define deb(x) cout<<#x<<" = "<<x<<endl
int mod = 1e9+7;
int power(int x,int n)
{   if(n==0)    return 1;
    if(n==1)    return x%mod;
    if(n%2==0)  {   int y = power(x,n/2)%mod;return (y*y)%mod;}
    if(n&1)     {   int y = power(x,n-1);return (x%mod * y%mod)%mod;}
    return 0;
}
int dx[]    =  {-1, 0, 1, 0,-1,-1,1, 1};
int dy[]    =  { 0, 1, 0,-1,-1, 1,1,-1};
const int maxn = 100005;
//  ------------------------------------------------------------------
vector<int> vis(maxn , 0);
vector<int> adj[maxn];

vector<int> cycle;
bool dfs(int n,int p)
{   vis[n] = 1;
    cycle.pb(n);
    for(int x:adj[n])
    {
        if(vis[x] && x!=n && p!=x)
        {   cycle.pb(x);
            return 1;
        }
        if(!vis[x] && dfs(x,n))
            return 1;   
    }
    // IF CYCLE NOT FOUND DELETE THE LAST ELEMENT.
    cycle.pop_back();
    return 0;
}
void solve()
{
    int n,i,j,k,m;
    cin>>n>>m;
    rep(i,m)
    {   int a,b;
        cin>>a>>b;
        a-- ,b--;
        adj[a].pb(b) , adj[b].pb(a);
    }
    for(i=0; i<n; i++)
    {   
        if(!vis[i])
        {          
            cycle = vector<int> ();
            if(dfs(i,-1))
            {   
                k = cycle.back();
                j=0;
                while(cycle[j]!=k)
                    j++;
                cout<<sz(cycle)-j<<endl;
                for(; j<sz(cycle); j++)
                    cout<<cycle[j]+1<< " ";
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}
signed main()
{
    RAGE;

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        
    int t=1;
    //  cin>>t;
    while(t--)
        solve();

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif


    return 0;
}

