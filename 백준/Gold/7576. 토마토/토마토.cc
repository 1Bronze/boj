/**
* 7576. 토마토
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int M, N;
int result = 0;
int graph[1001][1001];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
deque<pair<int, int>> q;

bool validate(int y, int x) {
    if(y>=1 && y<=N && x>=1 && x<=M)
        return true;
    else
        return false;
}

void bfs() {
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop_front();

        for (int i = 0; i <= 3; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (validate(nextY, nextX) && graph[nextY][nextX] == 0) { // 익히기 진행
                graph[nextY][nextX] = graph[y][x]+1;
                q.push_back(make_pair(nextY, nextX));
            }
        }
    }
}


int main() {
    cin >> M >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 1) q.push_back(make_pair(i, j));
        }
    }

    bfs();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {

            if (graph[i][j] == 0) {
                cout << -1;
                return 0;
            }

            if(result < graph[i][j]) {
                result = graph[i][j];
            }
        }
    }
    cout << result - 1;
    return 0;
}