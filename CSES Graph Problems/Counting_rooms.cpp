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
const int maxn = 1005;
//  ------------------------------------------------------------------
string s[maxn];
vector<vector<int>> vis(maxn , vector<int> (maxn , 0));
int n,m;
bool is_valid(int x ,int y)
{
    if(x<0 || x>=n)
        return false;
    if(y<0 || y>=m)
        return false;
    if(s[x][y]=='#')
        return false;
    return true;
}
 
void dfs(int x , int y)
{
    if(vis[x][y])
        return;
    vis[x][y] = 1;
    if(is_valid(x , y+1))
        dfs(x ,y+1);
    if(is_valid(x,y-1))
        dfs(x,y-1);
    if(is_valid(x-1 ,y))
        dfs(x-1,y);
    if(is_valid(x+1 , y))
        dfs(x+1 ,y);
}
void solve()
{
    int i,j,k;
    cin>>n>>m;
    rep(i,n)
        cin>>s[i];
    k=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(s[i][j]=='.' && !vis[i][j])
            {   
                dfs(i,j);
                k++;
            }   
        }
    }
    cout<<k;
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
