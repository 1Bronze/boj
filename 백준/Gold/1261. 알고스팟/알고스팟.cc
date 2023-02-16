/**
* 1261. 알고스팟
*/

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int maze[101][101];
int result[101][101];
queue<pair<int, int>> q;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dajikstra() {
    result[1][1] = 0;
    q.push(make_pair(1, 1));

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<=0 || ny>M || nx<=0 || nx>N) continue;

            int tmp;
            if(maze[ny][nx]==1) tmp = result[y][x] + 1;
            else tmp = result[y][x];

            if(result[ny][nx]>tmp || result[ny][nx]==2147483647) {
                result[ny][nx] = tmp;
                q.push(make_pair(ny, nx));
            }
        }

    }
}

int main() {
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <=100; j++) {
            result[i][j] = 2147483647;
        }
    }

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    dajikstra();
    cout << result[M][N];
}