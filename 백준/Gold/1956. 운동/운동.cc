/**
 * 1956. 운동
 */

#include <iostream>
using namespace std;

void floyd();

const int MAX_V = 401;
const int INF = 987654321;

int V, E;
int adj[MAX_V][MAX_V];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < MAX_V; i++)
        for (int j = 0; j < MAX_V; j++)
            adj[i][j] = INF;

    cin >> V >> E;
    int from, to, dist;
    for (int i = 0; i < E; i++) {
        cin >> from >> to >> dist;
        adj[from][to] = dist;
    }

    floyd();

    int result = 987654321;
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++) {
            if(i == j) continue;
            result = min(result, adj[i][j] + adj[j][i]);
        }

    if(result >= 987654321) cout << "-1\n";
    else cout << result << "\n";
}

void floyd() {
    for(int i = 0; i <= V; i++) adj[i][i] = 0;

    for(int k = 0; k <= V; k++)
        for(int i = 0; i <= V; i++)
            for(int j = 0; j <= V; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}