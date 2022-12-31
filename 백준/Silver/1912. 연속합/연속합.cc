#include <iostream>
using namespace std;

int arr[100000];
int dp[100000];

int max(int a, int b) { return (a>b) ? a:b; }

int main() {
	int T; cin >> T;

	for(int i=0; i<T; i++)
		cin >> arr[i];

	dp[0] = arr[0];

	for(int i=1; i<T; i++) {
		if(dp[i-1]<0) dp[i] = arr[i];
		else dp[i] = dp[i-1] + arr[i];
	}

	int result = dp[0];
	for(int i=1; i<T; i++)
		result = max(result, dp[i]);

	cout << result << endl;
}