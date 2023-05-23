/**
 * 1562. 계단 수
 */

#include <iostream>
using namespace std;

#define MOD 1000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // DP[i][j][k]
    // 길이가 i인 숫자 + 일의 자리가 j인 숫자 + 숫자가 0~9를 모두 포함하는지 확인하는 j
    int DP[101][101][1024];

    int N;
    cin >> N;

    for(int i = 1; i <=10; i++) DP[1][i][1<<i] = 1;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 1024; k++) {
                if(j < 9) {
                    int next_k = k | (1 << (j+1));
                    DP[i+1][j+1][next_k] += DP[i][j][k];
                    DP[i+1][j+1][next_k] %= MOD;
                }

                if(j > 0) {
                    int next_k = k | (1 << (j-1));
                    DP[i+1][j-1][next_k] += DP[i][j][k];
                    DP[i+1][j-1][next_k] %= MOD;
                }
            }

    int answer = 0;
    for (int i = 0; i < 10; i++) {
        answer += DP[N][i][1023];
        answer %= MOD;
    }

    cout << answer << "\n";
}