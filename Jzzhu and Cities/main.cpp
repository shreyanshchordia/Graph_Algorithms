/**
*First, using Dijkstra shortest path arrival is determined for each point, and obtaining the shortest end of each;
*Next we through each rail, if the point is greater than the shortest path to reach undoubtedly deleted directly.
*if equal to a shortest distance point and the point of penetration is greater than 1, indicating that multiple lines can be reached at the same distance, may be omitted.
*
*Taking into account the rail and road can sit at the same time, and the title has multiple edges.
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define ms(x, n) memset(x,n,sizeof(x));
typedef  long long LL;
const int inf = 1 << 30;
const LL maxn = 1e6 + 10;

int head[maxn], ecnt;
struct Edge{
    int u, v, w, next;
}es[maxn];
void addEdge(int u, int v, int w){
    es[ecnt].u = u, es[ecnt].v = v, es[ecnt].w = w;
    es[ecnt].next = head[u], head[u] = ecnt++;
}
int N, M, K;
int d[maxn];
bool used[maxn];
typedef pair<int, int> P;
int in[maxn]; // Penetration
void dijkstra(int s) {
    // s is obtained from the shortest path to each point
    ms(used, 0);
    fill(d, d + maxn, inf);
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(d[s] = 0, s));
    while(!q.empty()) {
        P cur = q.top();
        q.pop();
        int u = cur.second;
        if(used[u])
            continue;
        used[u] = true;
        // traverse all points and cur.second contiguous and updates from
        for(int i = head[u]; i != -1; i=es[i].next){
            int v = es[i].v, w = es[i].w;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push(P(d[v], v));
                in[v] = 1;
            }
            else if(d[v] == d[u]+w)
                ++in[v];
        }
    }
}
int s[maxn], y[maxn];
int main() {
    ms(head, -1); ecnt = 0;
    int a, b, c;
    cin >> N >> M >> K;
    for(int i = 1; i <= M; ++i){
        cin >> a >> b >> c;
        addEdge(a, b, c);
        addEdge(b, a, c);
    }
    for(int i = 1; i <= K; ++i){
        cin >> s[i] >> y[i];
        addEdge(1, s[i], y[i]);
        addEdge(s[i], 1, y[i]);
    }
    dijkstra(1);
    int ans = 0;
    for(int i = 1; i <= K; ++i){
        if(d[s[i]] < y[i])
            ++ans;
        else if(d[s[i]] == y[i] && in[s[i]]>1)
            --in[s[i]], ++ans; // greater than 1 illustrates how the route up
    }
    cout << ans << endl;

    return 0;
}
