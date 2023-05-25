/**
 * 1865. 웜홀
 * => 기본적인 벨만-포드 문제
 */

#include <iostream>
#include <vector>
using namespace std;

const int INF = 2147483647;
int T, N, M, W;

void solve();
bool bellmanFord(const vector<vector<pair<int,int>>>& adj, vector<int>& dist, int start);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) solve();
}

void solve() {
    // N: 노드 개수, M: 양의 간선 개수, W: 음의 간선 개수
    cin >> N >> M >> W;

    vector<vector<pair<int,int>>> adj(N+1);
    vector<int> dist(N+1);

    int u, v, t;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> t;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    for (int i = 0; i < W; i++) {
        cin >> u >> v >> t;
        adj[u].push_back({v,-t});
    }

    bool hasCycle = false;
    for (int start = 1; start <= N; start++) {
        hasCycle = bellmanFord(adj, dist, start);
        if(hasCycle) break;
    }

    if(hasCycle) cout << "YES\n";
    else cout << "NO\n";
}

bool bellmanFord(const vector<vector<pair<int,int>>>& adj, vector<int>& dist, int start) {

    fill(dist.begin(), dist.end(), INF);
    dist[start] = 0;

    bool updated;
    for (int iter = 0; iter < N; iter++) {

        updated = false;
        for (int here = 1; here <= N; here++) {
            
            if(dist[here] == INF) continue;
            
            for (int i = 0; i < adj[here].size(); i++) {
                
                int there = adj[here][i].first;
                int cost = dist[here] + adj[here][i].second;

                if (dist[there] > cost) {
                    dist[there] = cost;
                    updated = true;
                }
            }
        }

        if (!updated) break;
    }

    return updated;
}