#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[1001];
bool visited[50000];
int N, M;

void dfs(int x) {
    visited[x] = true;

    for(int i=0; i<graph[x].size(); i++) {
        int y = graph[x][i];
        if(!visited[y]) dfs(y);
    }
}

int main() {
    cin >> N >> M;

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

    int result = 0;

    for(int i=1; i<=N; i++) {
        if(!visited[i]) {
            dfs(i);
            result++;
        }
    }

    cout << result;
    return 0;
}