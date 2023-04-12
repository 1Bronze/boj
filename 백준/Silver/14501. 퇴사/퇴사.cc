/**
 * 14501. 퇴사
 */

#include <iostream>
#include <cmath>
using namespace std;

int N;
int T[16], P[16];
int result;

void dfs(int x, int sum) {
    if(x>N) return;

    result = max(result, sum);
    for (int i = x; i < N; i++)
        dfs(i+T[i], sum+P[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> T[i] >> P[i];

    dfs(0, 0);
    cout << result;
}