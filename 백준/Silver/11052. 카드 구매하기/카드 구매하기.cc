#include <iostream>
  using namespace std;

  int cards[1001];
  int dp[1001];

  int max(int a, int b) { return a>b ? a:b; }

  int main() {
    int N; cin >> N;
    for(int i=1; i<=N; i++) cin >> cards[i];

    dp[1] = cards[1];

    for(int i=2; i<=N; i++) {
      int result = cards[i];

      for(int j=1; j<i; j++)
        result = max(result, dp[j]+cards[i-j]);

      dp[i] = result;
    }

    cout << dp[N] << endl;
    return 0;
  }