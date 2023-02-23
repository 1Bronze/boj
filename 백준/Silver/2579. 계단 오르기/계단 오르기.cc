/**
 * 2579. 계단 오르기
 */

#define MAX 301

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int stair[MAX];
int DP[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> stair[i];

    DP[1] = stair[1];
    DP[2] = stair[1] + stair[2];
    DP[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

    for (int i = 4; i <= N; i++)
        DP[i] = max(DP[i-2]+stair[i], DP[i-3]+stair[i-1]+stair[i]);

    cout << DP[N];
}