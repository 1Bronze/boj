/**
 * 1012. 유기농 배추
 */

#define MAX 50

#include <iostream>
#include <queue>
using namespace std;

int T, N, M, K;
int map[MAX][MAX];
queue<pair<int, int>> q;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x, int cnt) {
    map[y][x] = cnt;
    q.push({y, x});

    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int nextY = curY + dy[i];
            int nextX = curX + dx[i];

            if(nextY >=0 && nextY < N && nextX >= 0 && nextX < M) {
                if(map[nextY][nextX] == -1) {
                    map[nextY][nextX] = cnt;;
                    q.push({nextY, nextX});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                map[i][j] = 0;
            }
        }

        cin >> M >> N >> K;
        for(int i=0; i<K; i++) {
            int x, y; cin >> x >> y;
            map[y][x] = -1;
        }

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(map[i][j]==-1)
                    bfs(i, j, ++cnt);
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}