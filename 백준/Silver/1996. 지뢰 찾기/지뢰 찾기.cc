/**
 * 1996. 지뢰 찾기
 */

#include <iostream>
using namespace std;

int N;
int arr[1001][1001];

int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char c; cin >> c;
            if(c=='.') arr[i][j] = 0;
            else arr[i][j] = c - '0';
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int sum = 0;
            for(int k = 0; k < 8; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(ny<1 || ny>N || nx<1 || nx>N) continue;
                sum += arr[ny][nx];
            }
            if(arr[i][j]!=0) cout << "*";
            else if(sum<10) cout << sum;
            else cout << 'M';
        }
        cout << "\n";
    }
}