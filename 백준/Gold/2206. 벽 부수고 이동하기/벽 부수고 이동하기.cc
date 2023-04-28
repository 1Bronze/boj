/**
 * 2206. 벽 부수고 이동하기
 */

#include <iostream>
#include <queue>
using namespace std;

struct point{
    int y;
    int x;
    int flag;
};


int N, M;
int graph[1001][1001];
int visited[1001][1001][2];
queue<point> q;
int result;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs() {

    visited[1][1][0] = 1;
    q.push({1, 1, 0});

    while(!q.empty()) {
        point p = q.front();
        q.pop();

        if(p.y == N && p.x == M) {
            return visited[p.y][p.x][p.flag];
        }

        for (int i = 0; i < 4; i++) {
            int ny = p.y + dy[i];
            int nx = p.x + dx[i];

            if(ny < 1 || ny > N || nx < 1 || nx > M) continue;
            if(visited[ny][nx][p.flag]) continue;

            if(!p.flag && !graph[ny][nx]) { // 0->0
                visited[ny][nx][p.flag] = visited[p.y][p.x][p.flag] + 1;
                q.push({ny, nx, p.flag});
            } else if(!p.flag && graph[ny][nx]) { // 0->1
                visited[ny][nx][p.flag+1] = visited[p.y][p.x][p.flag] + 1;
                q.push({ny, nx, p.flag+1});
            } else if(p.flag && !graph[ny][nx]) { // 1->0
                visited[ny][nx][p.flag] = visited[p.y][p.x][p.flag] + 1;
                q.push({ny, nx, p.flag});
            }
        }
    }

    return -1;
}

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char c;
            cin >> c;
            graph[i][j] = c - '0';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    result = bfs();
    cout << result;
}