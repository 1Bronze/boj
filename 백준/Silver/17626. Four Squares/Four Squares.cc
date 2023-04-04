/**
 * 17626. Four Squares
 */

#define MAX 50001

#include <iostream>
using namespace std;

int dp[MAX];
int n;

int min(int& a, int& b) {
    return (a>b) ? a:b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i*i < MAX; i++)
        dp[i*i] = 1;

    for (int i = 2; i < MAX; i++) {
        if(dp[i]==1) continue;

        int val = 50000;
        for (int j = 1; j*j < i; j++)
            val = min(val, dp[j*j]+dp[i-j*j]);

        dp[i] = val;
    }

    cin >> n;
    cout << dp[n];
}