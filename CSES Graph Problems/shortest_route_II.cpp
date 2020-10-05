/* 
    AABRA KA DABRA.. !! 
*/
#include "bits/stdc++.h"
using namespace std;
typedef long double ld;
typedef pair<int,int> pii;
#define int long long
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

int power(int x,int n)
{   
    if(n==0)    return 1;
    if(n==1)    return x%mod;
    if(n%2==0)  {   int y = power(x,n/2)%mod;return (y*y)%mod;}
    if(n&1)     {   int y = power(x,n-1);return (x%mod * y%mod)%mod;}
    return 0;
}
bool is_power_2(int n)  { return log2(n)==floor(log2(n));}
bool is_prime(int n){   for(int i=2; i*i<=n; i++)   if(n%i==0)  return 0;   return 1;}

int dx[]    =  {-1 ,  0,  1,  0,  -1,  -1,  1,   1};
int dy[]    =  { 0 ,  1,  0, -1,  -1,   1,  1,  -1};
char dir[]  =  {'U','R','D','L'};

const int maxn = 505;

/* ------------------------------------------------------- */


//  problem - > https://cses.fi/problemset/task/1672
int dp[maxn][maxn];
void solve()
{
    int n,i,j,k,m,q;
    memset(dp , 0x3f , sizeof(dp));
    cin>>n>>m>>q;
    rep(i,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dp[a][b] = min(dp[a][b] , c);
        dp[b][a] = min(dp[b][a] , c);
    }
    repv(i,1,n)
        dp[i][i] = 0;
    repv(k,1,n)
    {
        repv(i,1,n)
        {
            repv(j,1,n)
            {
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
            }
        }
    }
    while(q--)
    {   
        int s,t;
        cin>>s>>t;
        if(dp[s][t]>=1e18)
            cout<<-1<<endl;
        else
            cout<< dp[s][t]<<endl;
    }
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
