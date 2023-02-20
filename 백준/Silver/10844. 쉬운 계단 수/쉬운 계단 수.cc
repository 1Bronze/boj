/**
 * 10844. 쉬운 계단 수
 */

#define MAX 101

#include <iostream>
using namespace std;

int DP[MAX][10];
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i < 10; i++) DP[1][i] = 1;
    for (int i = 2; i <  MAX; i++) {
        for (int j = 0; j < 10; j++) {
            if(j==0) DP[i][0] = DP[i-1][1] % 1000000000;
            else if(j==9) DP[i][9] = DP[i-1][8] % 1000000000;
            else DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1]) % 1000000000;
        }
    }

    cin >> N;
    long long result = 0;
    for (int i = 0; i < 10; i++) result += DP[N][i];
    cout << result % 1000000000;
}