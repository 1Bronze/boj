#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

vector<int> graph[1001];
bool visited[1001];
deque<int> d;
int N, M, V;

void dfs(int x) {
    visited[x] = true;
    cout << x << " ";

    for(int i=0; i<graph[x].size(); i++) {
        int y = graph[x][i];
        if(!visited[y]) dfs(y);
    }
}

void bfs(int x) {
    visited[x] = true;
    cout << x << " ";
    d.push_back(x);

    while(!d.empty()) {
        for(int i=0; i<graph[d.front()].size(); i++) {
            int y = graph[d.front()][i];
            if(!visited[y]) {
                visited[y] = true;
                cout << y << " ";
                d.push_back(y);
            }
        }
        d.pop_front();
    }
}

int main() {
    cin >> N >> M >> V;

    int x, y;
    for(int i=0; i<M; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i=1; i<=N; i++) {
        visited[i] = false;
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    cout << "\n";

    for (int i=1; i<=N; i++) {
        visited[i] = false;
    }

    bfs(V);
    cout << "\n";

    return 0;
}