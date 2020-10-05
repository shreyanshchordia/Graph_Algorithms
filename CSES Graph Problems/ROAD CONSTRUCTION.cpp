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

const int maxn = 200005;
int n,m;
int par[maxn] , siize[maxn];
int find_par(int x)
{
    if(x==par[x])return x;
    return par[x] = find_par(par[x]);
}
void uni(int x,int y , int& comp , int& mx)
{
    int px = find_par(x) , py = find_par(y);
    if(px!=py)
    {
        if(siize[px]>siize[py])
            swap(px,py);
        par[px] = py;
        siize[py] += siize[px];
        siize[px]=0;
        comp--;
        mx = max(mx , siize[py]);
    }
}
void solve(int tc)
{
    int i,j,k,q;
    cin>>n>>m;
    repv(i,1,n)
        par[i] = i , siize[i] =1;
    int ans=0 , comp = n  ,mx=1;
    rep(i,m)
    {
        int a,b;
        cin>>a>>b;
        uni(a,b,comp , mx);
        cout<<comp<<" "<<mx<<endl;
    }
}
signed main()
{
    int t=1;
    //  cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
    return 0;
}