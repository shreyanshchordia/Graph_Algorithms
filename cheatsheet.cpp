#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << endl;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define INF 1000000000
#define MAXN 1000005
#define EPS 1e-9

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pllll;
typedef std::set<int> si;
typedef std::set<ll> sll;
typedef std::unordered_map<int , int> mii;
typedef std::unordered_map<ll , ll> mllll;
typedef std::unordered_map<char , int> mci;
typedef std::unordered_map<char , ll> mcll;

ll N;
bool seen[MAXN];
vll dist(MAXN), vis(MAXN), rank(MAXN), size(MAXN), parent(MAXN), adj[MAXN];
std::vector<std::tuple<ll, ll, ll>> edges;
std::vector<pllll> adj_dijkstra[MAXN]; //{v, w}

void dfs(int x) {
    std::stack<ll> s;
    seen[x] = true;
    s.push(x);
    while(!s.empty()) {
        ll u = s.top(); s.pop();
        for(auto v : adj[u]) {
            if(seen[v]) continue;
            seen[v] = true;
            s.push(v);
        }
    }
}

void bfs(int x) {
    std::queue<ll> q;
    seen[x] = true;
    dist[x] = 0;
    q.push(x);
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if(seen[v]) continue;
            seen[v] = true;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}

void dijkstra(int s) {
    FOR(i, 0, N) {
        dist[i] = INF;
        vis[i] = false;
    }
    std::priority_queue<pllll> q; //{w, v}
    dist[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        ll u = q.top().se; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto pr : adj_dijkstra[u]) {
            ll v, w;
            std::tie(v, w) = pr;
            if(vis[v]) continue;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({-dist[v], v});
            }
        }
    }
}

void toposort() { //I prefer this since it looks more straightforward than the dfs method
    vll indegree(N);
    FOR(i, 0, N) {
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    std::queue<ll> q;
    FOR(i, 0, N) {
        if(indegree[i] == 0)
            q.push(i);
    }

    vll result;
    while(!q.empty()) {
        ll node = q.front(); q.pop();
        result.pb(node);

        for(auto it : adj[node]){
            indegree[it]--;

            if(indegree[it] == 0)
                q.push(it);
        }
    }

    if(result.size() != N)
        std::cout<<"CYCLE ABAHDHSAJDHSA BRETHIKE KYKLOS AMBER ALERT";
    else
        std::cout<<"No kyklos all good";
}

//UNion psajimo

void init() {
    FOR(i, 0, N) {
        parent[i] = i;
        size[i] = 1;
        rank[i] = 0;
    }
}

ll find(int a) {
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void unite(ll a, ll b) {
    a = find(a);
    b = find(b);

    //By rank
    if(a != b) {
        if(rank[a] < rank[b])
            std::swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b])
            rank[a]++;
    }

    //By size
    if(a != b) {
        if(size[a] < size[b])
            std::swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

bool same(ll a, ll b) {
    return find(a) == find(b);
}

void kruskal() {
    std::sort(all(edges));
    for(auto edge : edges) {
        ll u, v, w;
        std::tie(w, u, v) = edge;
        if(!same(u, v)) unite(u, v);
    }
}

int main()
{
    return 0;
}
