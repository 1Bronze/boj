/**
 * 11403. 경로 찾기
 */

#include <iostream>
using namespace std;

int graph[101][101];
int N;

void dfs(int start, bool visited[]) {

//    cout << start << " ";

    for (int i = 1; i <= N; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            visited[i] = true;
            dfs(i, visited);
        }
    }
}

int find(int from, int to) {
    bool visited[101];
    for (int i = 1; i <= 100; i++) visited[i] = 0;
    dfs(from, visited);
//    cout << "\n";
    return visited[to];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << find(i, j) << " ";
        }
        cout << "\n";
    }
}