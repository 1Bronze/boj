#include <iostream>
using namespace std;

int main() {
	int cnt; 
	cin >> cnt; 

	for(int i=1; i<=cnt; i++) {
		int dp[11];		
		
		int n;
		cin >> n;

		for(int j=1; j<=n; j++) {
			dp[1]=1; dp[2]=2; dp[3]=4;
			if(j>3) dp[j] = dp[j-3] + dp[j-2] + dp[j-1];
		}

		cout << dp[n] << endl;
	}
}