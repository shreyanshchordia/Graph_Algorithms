#include <iostream>
#include <vector>
#include <queue>

#define INF_TIME 1000000000

using namespace std;

// There are N network nodes, labelled 1 to N.
// Given times, a list of travel times as directed edges times[i] = (u, v, w),
// where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.
// Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal?
// If it is impossible, return -1.

int networkDelayTime(vector<vector<int>>& times, int N, int K) {

    --K; // shift index by 1

    int toK[N]; // toK[N] - how long will it take from i to K (or from K to i)
    int fromTo[N][N]; // fromTo[i][j] - how long will it take from i to j

    for (int i = 0; i < N; ++i){
        toK[i] = INF_TIME;
        for (int j = 0; j < N; ++j){
            fromTo[i][j] = -1;
        }
    }
    toK[K] = 0;


    for (int i = 0; i < times.size(); ++i){
        int u, v, w;
        u = times[i][0] - 1;
        v = times[i][1] - 1;
        w = times[i][2];
        fromTo[u][v] = w;
    }
    fromTo[K][K] = 0;

    // bfs algorithm
    queue<int> q;

    q.push(K);
    while (!q.empty()){
        int now;
        now = q.front();
        q.pop();
        for (int i = 0; i < N; ++i){
            if (fromTo[now][i] >= 0){
                if (toK[now] + fromTo[now][i] < toK[i]){
                    toK[i] = toK[now] + fromTo[now][i];
                    q.push(i);
                }
            }
        }
    }

    int totalTime = 0; // answer
    for (int i = 0; i < N; ++i){
        totalTime = max(totalTime, toK[i]);
    }
    if (totalTime == INF_TIME) totalTime = -1; // this means that some nodes cannot be reached

    return totalTime;
}


int main() {

    int N, E, K;

    cin >> N >> E >> K;

    vector<vector<int>> times;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        times.push_back(vector<int>({u,v,w}));
    }

    cout << networkDelayTime(times, N, K);

    return 0;
}
