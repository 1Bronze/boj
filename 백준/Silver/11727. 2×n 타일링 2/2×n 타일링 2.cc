#include <iostream>
using namespace std;

int main() {
	int n; 
	cin >> n; 

	int dp[1001];
	dp[1] = 1; dp[2] = 3; // n=1, n=2일 때의 2xn 타일링 수

	for (int i = 3; i <= n; i++) { // n-2번 반복
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
		dp[i] = dp[i] % 10007;
	}

	cout << dp[n] ;

	return 0;
}