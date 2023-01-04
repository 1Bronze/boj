#include <iostream>
  using namespace std;

  long long dp[101];

  void execute() {
    int num; cin >> num;

    for(int i=1; i<=num; i++) {
        if(i==1) dp[1] = 1;
        else if(i==2) dp[2] = 1;
        else if(i==3) dp[3] = 1;
        else if(i==4) dp[4] = 2;
        else if(i==5) dp[5] = 2;
        else dp[i] = dp[i-1] + dp[i-5];
    }

    cout << dp[num] << endl;
  }

  int main() {
    int N; cin >> N;

    for(int i=0; i<N; i++)
        execute();
  }