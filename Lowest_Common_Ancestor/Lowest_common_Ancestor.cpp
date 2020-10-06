#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

vector<vector<int> > G; // To store the graph in Adjacency List form.
const int M = 21;
int par[100005][M]; //To store the ith parent of each node(Sparse Table)

// O(n)*M
void calc_sparse_table(int curr, int parent)
{
    par[curr][0] = parent;
    for (int j = 1; j < M; j++)
    {
        par[curr][j] = par[par[curr][j - 1]][j - 1];
    }
    for (auto x : G[curr])
        if (x != parent)
            calc_sparse_table(x, curr);
}



/* LCA Using time in and Out*/

/* In this we only move one node upto its ancestor until
    parent of that node is the ancestor of other too.*/

int timm = 0, timin[100005], timout[100005];

void dfs_time(int curr, int parent)
{
    timin[curr] = ++timm;
    for (auto x : G[curr])
    {
        if (x != parent) {
            dfs_time(x, curr);
        }
    }
    timout[curr] = timm;
}

bool is_ancestor(int u, int v)
{
    return timin[u] <= timin[v] && timout[u] >= timout[v];
}

// O(logn)
int LCA_using_time(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;

    for (int i = M - 1; i >= 0; i--)
    {
        // we are moving only u
        if (!is_ancestor(par[u][i] , par[v][i]))
        {
            u = par[u][i];
        }
    }
    return par[u][0];
}

int main()
{
   
    int n, m;
    cin >> n >> m;
    G.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
    // Assuming 1 is the root node of the tree.

    /* Using time in and out method along with sparse table */

    memset(timin, 0, sizeof(timin));
    memset(timout, 0, sizeof(timout));

    timin[0] = 0; timout[0] = m + 1; // 0 is universal parent
    dfs_time(1, 0);
    calc_sparse_table(1, 0);

    // The below code will return the LCA of two nodes in the graph.
    /*

    cout << LCA_using_time(9, 15) << endl;
    
    */

    return 0;
}
