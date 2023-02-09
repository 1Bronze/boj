/**
* 2667 단지번호붙이기
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 26
using namespace std;

int n;
int map[MAX][MAX];
bool done[MAX][MAX];
vector<int> result;
int tmp;

void connect(int r, int c) {
    done[r][c] = true;
    tmp++;

    if(map[r-1][c] && !done[r-1][c] && r!=1) connect(r-1, c); // 왼쪽 탐색
    if(map[r+1][c] && !done[r+1][c] && r!=n) connect(r+1, c); // 오른쪽 탐색
    if(map[r][c-1] && !done[r][c-1] && c!=1) connect(r, c-1); // 위 탐색
    if(map[r][c+1] && !done[r][c+1] && c!=n) connect(r, c+1); // 아래 탐색
}

int main() {
    cin >> n;

    char c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            map[i][j] = c - '0';
            done[i][j] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            tmp = 0;
            if(map[i][j] && !done[i][j]) {
                connect(i, j);
                result.push_back(tmp);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for(int num : result) {
        cout << num << "\n";
    }
}