#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

vector<vector<int> > G;// Adjacency list form of graph
set<int> art_points;    // Store articulation points
vector<pair<int, int> > bridge; // store the bridges in the graph
int discovered[100005], lowest[100005] , timm;

void dfs(int cur, int par)
{
    discovered[cur] = lowest[cur] = timm++;
    int no_of_child = 0;
    for (auto child : G[cur])
    {
        // not visited
        if (discovered[child] == 0)
        {
            dfs(child, cur);
            no_of_child++;
            lowest[cur] = min(lowest[cur], lowest[child]);
            if (par != 0 && lowest[child] >= discovered[cur])
            {
                art_points.insert(cur);
            }

            if (lowest[child] > discovered[cur])
            {
                bridge.pb({cur, child});
            }
            // if no.of child of root>=2 then root is also articulation point
            if (par == 0 && no_of_child >= 2)
                art_points.insert(cur);
        }
        else if (child != par)
        {
            // backedge
            // cycle found
            lowest[cur] = min(lowest[cur], discovered[child]);
        }
    }
}

int main()
{
    int n, m; // no.of vertices and no.of edges
    cin >> n >> m;
    G.resize(n + 1); // 1 based indexing
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
    timm = 1;
    memset(discovered, 0, sizeof(discovered));

    dfs(1, 0); // 1 is root and 0 is the parent of root

    cout << "Articulation Points : ";
    for (auto it = art_points.begin(); it != art_points.end(); it++)
        cout << *it << " ";

    cout << endl;

    cout << "Bridge Edge : " << endl;
    for (int i = 0; i < bridge.size(); i++)
        cout << bridge[i].first << "->" << bridge[i].second << " ";

    return 0;
}