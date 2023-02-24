/**
 * 1699. 제곱수의 합
 */

#define MAX 100001

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int DP[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) DP[i] = 987654321;
    for (int i = 1; i*i <= N; i++) DP[i*i] = 1;

    for (int i = 1; i <= N; i++) {
        if(DP[i]==1) continue;

        for (int j = 1; j*j < i; j++) {
            DP[i] = min(DP[i], DP[i-j*j]+1);
        }
    }

    cout << DP[N];
    return 0;
}