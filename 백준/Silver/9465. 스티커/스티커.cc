/**
 * 9465. 스티커
 */

#include <iostream>
#include <algorithm>
using namespace std;

int T,n;
int score[2][100001];
int DP[2][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--) {
        cin >> n;

        for (int i = 1; i <= n; i++)  cin >> score[0][i];
        for (int i = 1; i <= n; i++)  cin >> score[1][i];

        DP[0][1] = score[0][1], DP[1][1] = score[1][1];
        DP[0][2] = DP[1][1] + score[0][2], DP[1][2] = DP[0][1] + score[1][2];

        for (int i = 3; i <= n; i++) {
            DP[0][i] = max(DP[1][i-1] + score[0][i], DP[1][i-2] + score[0][i]);
            DP[1][i] = max(DP[0][i-1] + score[1][i], DP[0][i-2] + score[1][i]);
        }

        cout << max(DP[0][n], DP[1][n]) << "\n";
    }
}