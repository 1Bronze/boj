/**
 * 9461. 파도반 수열
 */

#include <iostream>
using namespace std;

int T, N;
long long DP[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    DP[1] = 1, DP[2] = 1, DP[3] = 1, DP[4] = 2, DP[5] = 2;

    for (int i = 6; i <= 100; i++)
        DP[i] = DP[i-5] + DP[i-1];

    cin >> T;
    while(T--) {
        cin >> N;
        cout << DP[N] << "\n";
    }
}