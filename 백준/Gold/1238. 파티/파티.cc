/**
 * 1238. 파티
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra(vector<int>& dist, int start);

const int INF = 2147483647;
const int MAX_N = 1001;

// N: 학생의 수, X: 파티가 열리는 마을, M: 단방향 도로의 수
int N, X, M;
vector<pair<int, int>> roads[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> dist(MAX_N);
    vector<int> result(MAX_N);

    cin >> N >> M >> X;
    int u, v, t;
    for (int i = 1; i <= M; i++) {
        cin >> u >> v >> t;
        roads[u].push_back({v, t});
    }

    for (int i = 1; i <= N; i++) {
        dijkstra(dist, i);
        result[i] = dist[X];
    }
    dijkstra(dist, X);

    int max = 0;
    for (int i = 1; i <= N; i++) {
        result[i] += dist[i];
        max = (max<result[i]) ? result[i]:max;
    }
    cout << max;
}

void dijkstra(vector<int>& dist, int start) {

    fill(dist.begin(), dist.end(), INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    int min_cost, now;
    while (!pq.empty()) {
        min_cost = pq.top().first;
        now = pq.top().second;
        pq.pop();

        if(min_cost > dist[now]) continue;

        for (int i = 0; i < roads[now].size(); i++) {
            int next = roads[now][i].first;
            int next_cost = min_cost + roads[now][i].second;

            if(next_cost < dist[next]) {
                dist[next] = next_cost;
                pq.push({dist[next], next});
            }
        }
    }
}