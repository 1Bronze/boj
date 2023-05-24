/**
 * 1932. 정수 삼각형
 */

#include <iostream>
using namespace std;

int n;
int arr[502][502];
int dp[502][502];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> arr[i][j];

    dp[1][1] = arr[1][1];

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];

    int result = 0;
    for (int i = 1; i <= n; i++)
        result = max(result, dp[n][i]);
    cout << result;
}