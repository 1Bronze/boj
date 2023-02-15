/**
* 1987. 알파벳
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
char board[21][21];
vector<char> v;
int len, result;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int max(int a, int b) {
    return (a>b) ? a:b;
}

void dfs(int y, int x) {
    char val = board[y][x];
    v.push_back(val);
    len += 1;

    result = max(result, len);

    for (int i = 0; i < 4; i++) {
        int nY = y + dy[i];
        int nX = x + dx[i];

        if(nY<0 || nY>=R || nX<0 || nX>=C) continue;

        if(find(v.begin(), v.end(), board[nY][nX])!=v.end()) continue;

        dfs(nY, nX);
    }

    v.pop_back();
    len -= 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0,0);
    cout << result;
}