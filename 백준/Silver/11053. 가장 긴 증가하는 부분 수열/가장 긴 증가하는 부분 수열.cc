/**
 * 11053. 가장 긴 증가하는 부분 수열
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int arr[1001];
int DP[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 1; i <= N; i++) {
        DP[i] = 1;

        for (int j = i-1; j >= 1; j--) {
            if(arr[i] > arr[j])
                DP[i] = max(DP[i], DP[j]+1);
        }
        ans = max(ans, DP[i]);
    }

    cout << ans;
}