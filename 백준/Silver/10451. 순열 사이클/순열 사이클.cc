#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[1001];
bool visited[1001];
int T, N;

void dfs(int x) {
    visited[x] = true;

    for(int i=0; i<graph[x].size(); i++) {
        int y = graph[x][i];
        if(!visited[y]) dfs(y);
    }
}

int main() {
    cin >> T;

    for(int i=1; i<=T; i++) {
        cin >> N;

        int x;
        for(int j=1; j<=N; j++) {
            cin >> x;
            graph[j].push_back(x);
            graph[x].push_back(j);
        }

        for (int j=1; j<=N; j++) {
            visited[j] = false;
            sort(graph[j].begin(), graph[j].end());
        }

        int result = 0;

        for(int j=1; j<=N; j++) {
            if(!visited[j]) {
                dfs(j);
                result++;
            }
        }

        cout << result << "\n";

        for(int j=1; j<=N; j++) graph[j].clear();
    }
    return 0;
}