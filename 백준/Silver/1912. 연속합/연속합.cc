/**
 * 1912. 연속합
 */

#define MAX 100001

#include <iostream>
using namespace std;

int n, ans = -987654321;
int arr[MAX];
int DP[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) {

        DP[i] = max(DP[i-1]+arr[i], arr[i]);
        ans = max(ans, DP[i]);
    }

    cout << ans;
    return 0;
}