#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int N, M, K;
char arr[101][101];
int DP[101][101][80];
string word;
int result;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int dfs(int y, int x, int cnt) {

    if(cnt==word.length()) return 1;
    if(DP[y][x][cnt]!=-1) return DP[y][x][cnt];

    DP[y][x][cnt] = 0;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < 4; j++) {
            int nY = y + i*dy[j];
            int nX = x + i*dx[j];

            if(nY>0 && nY<=N && nX>0 && nX<=M) {
                if(arr[nY][nX] == word[cnt])
                    DP[y][x][cnt] += dfs(nY, nX, cnt+1);
            }
        }
    }

    return DP[y][x][cnt];
}

void Input() {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> word;
    memset(DP, -1, sizeof(DP));
}

void Solution() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if(arr[i][j] == word[0]) {
                result += dfs(i, j, 1);
            }
        }
    }
    cout << result;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
}