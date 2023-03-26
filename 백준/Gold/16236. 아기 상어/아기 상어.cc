/**
 * 16236. 아기 상어
 */

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int s, cnt, t, d;
pair<int, int> pos, target;
int arr[21][21];
int dist[21][21];
queue<pair<int, int>> q;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(pair<int, int> a) {
    q.push(a);

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i <= 3; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny==a.first && nx==a.second) continue;

            if(ny>0 && ny<=N && nx>0 && nx<=N) {
                if(dist[ny][nx]==0 && arr[ny][nx]<=s) {
                    dist[ny][nx] = dist[y][x]+1;
                    q.push({ny, nx});
                }
            }
        }
    }

    dist[a.first][a.second] = 1000;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    s = 2;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                pos.first = i;
                pos.second = j;
                arr[i][j] = 0;
            }
        }
    }

    while(1) {
        target = {pos.first, pos.second};

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = 0;
            }
        }

        bfs(pos);

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                // 물고기가 없는 칸은 패스
                if(arr[i][j] == 0 || dist[i][j]==0) continue;
                // 물고기가 커서 못먹는 경우 패스
                if (arr[i][j] >= s) continue;

                // 먹을 수 있을 경우, 거리가 가까운 것으로 대상 변경
                if (dist[i][j] < dist[target.first][target.second]) {
                    target = {i, j};
                }
            }
        }

        d = dist[target.first][target.second];
        if(d==1000) break;
        t += d;
        cnt++;
        pos.first = target.first;
        pos.second = target.second;
        arr[pos.first][pos.second] = 0;
        if(cnt==s) {
            cnt = 0;
            s++;
        }

//        cout << pos.first << " " << pos.second << " " << t << "\n";
    }

    cout << t << "\n";
}