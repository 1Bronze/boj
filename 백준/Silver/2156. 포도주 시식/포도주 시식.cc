/**
 * 2156. 포도주 시식
 */

#include <iostream>
#include <algorithm>
using namespace std;

int wine[10001];
int DP[10001];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> wine[i];

    DP[1] = wine[1]; DP[2] = wine[1] + wine[2];
    DP[3] = max(wine[1] + wine[3], wine[2] + wine[3]);
    DP[3] = max(DP[3], wine[1] + wine[2]);

    for (int i = 4; i <= n; i++) {
        DP[i] = max(DP[i-2] + wine[i], DP[i-3] + wine[i-1] + wine[i]);
        DP[i] = max(DP[i], DP[i-1]);
    }

    cout << DP[n];
}