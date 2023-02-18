/**
* 7569. 토마토
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct locate {
    int y;
    int x;
    int z;
};

int N, M, H;
int box[100][100][100];
queue<locate> q;
int dy[6] = {-1, 0, 1, 0, 0, 0};
int dx[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int day;

void bfs() {
    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int z = q.front().z;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(nx<0 || ny<0 || nz<0 || nx>=M || ny>=N || nz>=H) continue;
            if(box[ny][nx][nz]!=0) continue;

            box[ny][nx][nz] = box[y][x][z] + 1;
            q.push({ny,nx, nz});
        }
    }
}

int main() {
    // M - 열, N - 행, H - 높이
    cin >> M >> N >> H;

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> box[n][m][h];

                if(box[n][m][h]==1)
                    q.push({n, m, h});
            }
        }
    }

    bfs();

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if(box[n][m][h]==0) {
                    cout << "-1";
                    return 0;
                }
                day = max(day, box[n][m][h]);
            }
        }
    }

    cout << day - 1;
}