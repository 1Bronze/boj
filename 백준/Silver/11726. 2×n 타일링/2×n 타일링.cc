/**
 * 11726. 2×n 타일링
 */

#define MAX 1001

#include <iostream>
using namespace std;

int DP[MAX];
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    DP[1] = 1; DP[2] = 2;
    for (int i = 3; i < MAX; i++)
        DP[i] = (DP[i-1] + DP[i-2])%10007;

    cin >> N;
    cout << DP[N];
}