/**
 * 1504. 특정한 최단 경로
 *
 * FROM -> A -> B -> TO
 * FROM -> B -> A -> TO
 *
 * 구할 것은
 * FROM -> A
 * FROM -> B
 * A -> B
 * B -> A
 * A -> TO
 * B -> TO
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 99999999
#define MAX_N 801

void dijkstra(vector<int> &dist, int start);

vector<pair<int, int>> adj[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, E;
    cin >> N >> E;

    vector<int> dist(N + 1);

    int from, to, weight;
    for (int i = 0; i < E; i++) {
        cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }

    int A, B;
    cin >> A >> B;

    int dist1 = 0, dist2 = 0;

    dijkstra(dist, 1);
    dist1 += dist[A];
    dist2 += dist[B];
//    cout << "(1->A) " << dist[A] << "\n";
//    cout << "(1->B) " << dist[B] << "\n";
    dijkstra(dist, A);
    dist1 += dist[B];
    dist2 += dist[N];
//    cout << "(A->B) " << dist[B] << "\n";
//    cout << "(A->N) " << dist[N] << "\n";
    dijkstra(dist, B);
    dist1 += dist[N];
    dist2 += dist[A];
//    cout << "(B->A) " << dist[A] << "\n";
//    cout << "(B->N) " << dist[N] << "\n";

    int result = min(dist1, dist2);
    if(result < INF) cout << result << "\n";
    else cout << "-1\n";
}

void dijkstra(vector<int> &dist, int start) {

    fill(dist.begin(), dist.end(), INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(dist[here] < cost) continue;

        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;

            if(nextDist < dist[there]) {
                dist[there] = nextDist;
                pq.push({nextDist, there});
            }
        }
    }
}