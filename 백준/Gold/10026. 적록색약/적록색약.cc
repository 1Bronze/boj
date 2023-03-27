/**
 * 10026. 적록색약
 */

#define MAX 101

#include <iostream>
#include <queue>
using namespace std;

int N;
char graph[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> q;
pair<int, int> result;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool validate(const int& a, const int& b) {
    return (a>=1 && a<=N && b>=1 && b<=N);
}

void bfs1() {
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int ny = y + dy[i];
            int nx = x + dx[i];

            if(!visited[ny][nx] && validate(ny, nx)) {
                if(graph[ny][nx]==graph[y][x]) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }

    result.first++;
}

void bfs2() {
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int ny = y + dy[i];
            int nx = x + dx[i];

            if(!visited[ny][nx] && validate(ny, nx)) {
                if(graph[ny][nx]==graph[y][x]) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }

    result.second++;
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
            if(!visited[i][j]) {
                visited[i][j] = true;
                q.push({i, j});
                bfs1();
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[i][j] = false;
            if(graph[i][j]=='G')
                graph[i][j] = 'R';
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(!visited[i][j]) {
                visited[i][j] = true;
                q.push({i, j});
                bfs2();
            }
        }
    }

    cout << result.first << " " << result.second << "\n";
    return 0;
}