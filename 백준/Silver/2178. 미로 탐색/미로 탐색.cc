/**
* 2178 미로탐색
*/

#include <iostream>
#include <deque>
using namespace std;

int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int graph[101][101];
deque<pair<int, int>> q;

void bfs() {
    int x, y, nx, ny;
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop_front();

        for(int i=0; i<4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny>=1 && nx>=1 && ny<=n && nx<=m) {
                if(graph[ny][nx] == 1) {
                    graph[ny][nx] = graph[y][x] + 1;
                    q.push_back(make_pair(ny, nx));
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            graph[i][j] = c - '0';
        }
    }

    q.push_back(make_pair(1, 1));
    bfs();
    cout << graph[n][m];

    return 0;
}