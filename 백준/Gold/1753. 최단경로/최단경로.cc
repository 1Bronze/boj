/**
 * 1753. 최단경로
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define V_MAX 20001
#define INF 2147483647

void dijkstra(vector<int>& dist, int start);

vector<vector<pair<int, int>>> adj(V_MAX);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    vector<int> dist(V_MAX);

    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(dist, K);

    for (int i = 1; i <= V; i++) {
        if(dist[i] == 2147483647) {
            cout << "INF\n";
            continue;
        }
        cout << dist[i] << "\n";
    }
}

void dijkstra(vector<int>& dist, int start) {

    fill(dist.begin(), dist.end(), INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while(!pq.empty()) {

        int min_cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(min_cost > dist[now]) continue;

        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i].first;
            int next_cost = min_cost + adj[now][i].second;

            if(next_cost < dist[next]) {
                dist[next] = next_cost;
                pq.push({dist[next], next});
            }
        }
    }
}