#include <iostream>
using namespace std;

int dp[201][201];
int N, K;

int main() {
    cin >> N >> K;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            if(i==1) dp[i][j]=j;
            else if(j==1) dp[i][j]=1;
        }
    }

    for(int i=2; i<=N; i++) {
        for(int j=2; j<=K; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
        }
    }

   cout << dp[N][K] << endl;
}