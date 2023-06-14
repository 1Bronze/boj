/**
 * 1326. 폴짝폴짝
 */

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 10001

int N, a, b;
int bridge[MAX];
//int graph[MAX][MAX];
int visited[MAX];
queue<int> q;

void bfs(int start);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(visited, visited+MAX, -1);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> bridge[i];
    cin >> a >> b;

    bfs(a);
    cout << visited[b] << "\n";
}


void bfs(int start) {

    q.push(start);
    visited[start] = 0;

    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for (int to = 1; to <= N; to++) {
            if((from-to)%bridge[from] != 0) continue;
            if(visited[to] != -1) continue;

            visited[to] = visited[from] + 1;
            q.push(to);
        }
    }
}