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
#define gcd __gcd
#define inf LLONG_MAX
#define minf LLONG_MIN 
const int mod = (int)(1e9+7);

int dx[]    =  {-1, 0, 1,  0, -1, -1, 1,  1};
int dy[]    =  { 0, 1, 0, -1, -1,  1, 1, -1};
char dir[]  =  {'U','R','D','L'};
const int maxn = 2005;
// ---------------------------------------------------------------------------------
int n,m;
string s[maxn];
vector<vector<int>> dist(maxn , vector<int> (maxn , -1));
vector<vector<int>> vis(maxn , vector<int> (maxn , 0));
vector<vector<int>> side(maxn ,vector<int> (maxn ,  -1));
bool is_valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    if(vis[x][y] || s[x][y]=='#')
        return false;
    return true;
}
void bfs(int x,int y)
{
    queue<pii> q;
    q.push({x,y});
    dist[x][y] = 0;
    while(!q.empty())
    {
        int cx = q.front().F;
        int cy = q.front().S;
        q.pop();
        for(int i=0; i<4; i++)
        {
            if(is_valid(cx + dx[i] , cy + dy[i]))
            {
                int nx = cx + dx[i] , ny = cy + dy[i];
                q.push({nx,ny});
                vis[nx][ny] = 1;
                dist[nx][ny] = dist[cx][cy] + 1;
                side[nx][ny] = i;
            }
        }
    }
}

void solve()
{
    int i,j,k;
    cin>>n>>m;
    rep(i,n)
        cin>>s[i];
    pair<int,int> start , end;
    rep(i,n)
    {
        rep(j,m)
        {
            if(s[i][j]=='A')
                start.F = i , start.S = j;
            if(s[i][j]=='B')
                end.F = i , end.S = j;
        }
    }
    bfs(start.F , start.S);
    if(dist[end.F][end.S]==-1)
    {
        cout<<"NO";
        return;
    }
    side[start.F][start.S] = inf;
    /*
    rep(i,n)
    {
        rep(j,m)
        {
            if(i==start.F && j==start.S)
                cout<<'%';
            else
            if(i==end.F && j==end.S)
                cout<<'!';
            else
            if(side[i][j]==-1)
                cout<<'*';
            else
                cout<<dir[side[i][j]];
        }
        cout<<endl;
    }
    */
    cout<<"YES"<<endl;
    string ans  = "";
    i = end.F , j = end.S;
    while(i!=start.F || j!=start.S)
    {
        if(dir[side[i][j]]=='U')
        {   ans += 'U';     i++; }
        else
        if(dir[side[i][j]]=='R')
        {   ans += 'R'; j--;     }
        else
        if(dir[side[i][j]]=='L')
        {   ans += 'L'; j++;     }
        else
        if(dir[side[i][j]]=='D')
        {   ans += 'D'; i--;     }
    }
    reverse(all(ans));
    cout<<sz(ans)<<endl;
    cout<<ans;
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
