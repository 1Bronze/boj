/**
 * 1463. 1로 만들기
 */

#define MAX 1000001

#include <iostream>
#include <algorithm>
using namespace std;

int DP[MAX];
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    DP[1] = 0; DP[2] = 1; DP[3] = 1;

    for (int i = 4; i < MAX; i++) {
        DP[i] = DP[i-1] + 1;
        if(i%3==0) DP[i] = min(DP[i], DP[i/3] + 1);
        if(i%2==0) DP[i] = min(DP[i], DP[i/2] + 1);
    }

    cin >> N;
    cout << DP[N];
}