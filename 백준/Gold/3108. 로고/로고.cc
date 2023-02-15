/**
* 3108. 로고
*/

#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[2001][2001];
queue<pair<int, int>> q;
int result;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
    if (y < 0 || x < 0 || x > 2000 || y > 2000) return;
    if (arr[y][x] == 2 || arr[y][x] == 0) return;

    arr[y][x] = 2;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int x1, y1, x2, y2;
    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        x1 = (x1 + 500) * 2;
        y1 = (y1 + 500) * 2;
        x2 = (x2 + 500) * 2;
        y2 = (y2 + 500) * 2;

        for (int j = x1; j <= x2; j++) {
            arr[y1][j] = 1;
            arr[y2][j] = 1;
        }

        for (int j = y1; j <= y2; j++) {
            arr[j][x1] = 1;
            arr[j][x2] = 1;
        }
    }

    q.push(make_pair(1000, 1000));

    for (int i = 0; i <= 2000; i++) {
        for (int j = 0; j <= 2000; j++) {
            if(arr[i][j]!=1) continue;
            dfs(i, j);
            result++;
        }
    }

    if(arr[1000][1000]==2) result--;
    cout << result;
}