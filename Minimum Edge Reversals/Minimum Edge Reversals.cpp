// C++ program to find min edge reversal to 
// make every node reachable from root 
#include <bits/stdc++.h> 
using namespace std; 
  
// method to dfs in tree and populates disRev values 
int dfs(vector< pair<int, int> > g[], 
        pair<int, int> disRev[], bool visit[], int u) 
{ 
    // visit current node 
    visit[u] = true; 
    int totalRev = 0; 
  
    // looping over all neighbors 
    for (int i = 0; i < g[u].size(); i++) 
    { 
        int v = g[u][i].first; 
        if (!visit[v]) 
        { 
            // distance of v will be one more than distance of u 
            disRev[v].first = disRev[u].first + 1; 
  
            // initialize back edge count same as 
            // parent node's count 
            disRev[v].second = disRev[u].second; 
  
            // if there is a reverse edge from u to i, 
            // then only update 
            if (g[u][i].second) 
            { 
                disRev[v].second = disRev[u].second + 1; 
                totalRev++; 
            } 
            totalRev += dfs(g, disRev, visit, v); 
        } 
    } 
  
    // return total reversal in subtree rooted at u 
    return totalRev; 
} 
  
// method prints root and minimum number of edge reversal 
void printMinEdgeReverseForRootNode(int edges[][2], int e) 
{ 
    // number of nodes are one more than number of edges 
    int V = e + 1; 
  
    // data structure to store directed tree 
    vector< pair<int, int> > g[V]; 
  
    // disRev stores two values - distance and back 
    // edge count from root node 
    pair<int, int> disRev[V]; 
  
    bool visit[V]; 
  
    int u, v; 
    for (int i = 0; i < e; i++) 
    { 
        u = edges[i][0]; 
        v = edges[i][1]; 
  
        // add 0 weight in direction of u to v 
        g[u].push_back(make_pair(v, 0)); 
  
        // add 1 weight in reverse direction 
        g[v].push_back(make_pair(u, 1)); 
    } 
  
    //    initialize all variables 
    for (int i = 0; i < V; i++) 
    { 
        visit[i] = false; 
        disRev[i].first = disRev[i].second = 0; 
    } 
  
    int root = 0; 
  
    // dfs populates disRev data structure and 
    // store total reverse edge counts 
    int totalRev = dfs(g, disRev, visit, root); 
  
    // UnComment below lines to print each node's 
    // distance and edge reversal count from root node 
    /* 
    for (int i = 0; i < V; i++) 
    { 
        cout << i << " : " << disRev[i].first 
              << " " << disRev[i].second << endl; 
    } 
    */
  
    int res = INT_MAX; 
  
    // loop over all nodes to choose minimum edge reversal 
    for (int i = 0; i < V; i++) 
    { 
        // (reversal in path to i) + (reversal 
        // in all other tree parts) 
        int edgesToRev = (totalRev - disRev[i].second) + 
                         (disRev[i].first - disRev[i].second); 
  
        // choose minimum among all values 
        if (edgesToRev < res) 
        { 
            res = edgesToRev; 
            root = i; 
        } 
    } 
  
    // print the designated root and total 
    // edge reversal made 
    cout << root << " " << res << endl; 
} 
  
// Driver code to test above methods 
int main() 
{ 
    int edges[][2] = 
    { 
        {0, 1}, 
        {2, 1}, 
        {3, 2}, 
        {3, 4}, 
        {5, 4}, 
        {5, 6}, 
        {7, 6} 
    }; 
    int e = sizeof(edges) / sizeof(edges[0]); 
  
    printMinEdgeReverseForRootNode(edges, e); 
    return 0; 
} 