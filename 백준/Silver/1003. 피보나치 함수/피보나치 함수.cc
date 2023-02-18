/**
 * 1003. 피보나치 함수
*/

#include <iostream>
#include <string>
using namespace std;

int T, N;
int DP[41][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    DP[0][0] = 1, DP[1][1] = 1;

    for (int i = 2; i <= 40; i++) {
        DP[i][0] = DP[i-1][0] + DP[i-2][0];
        DP[i][1] = DP[i-1][1] + DP[i-2][1];
    }

    while(T--) {
        cin >> N;
        cout << DP[N][0] << " " << DP[N][1] << "\n";
    }

    return 0;
}