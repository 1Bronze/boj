#include <iostream>
using namespace std;

int max(int a, int b) { return a>b ? a:b; }

int main() {
	int n; cin >> n;
	int nums[1000];
	int dp[1000];

	for(int i=0; i<n; i++)
		cin >> nums[i];

	for(int i=0; i<n; i++)
		dp[i] = nums[i];	

	for(int i=1; i<n; i++) {
		for(int j=0; j<i; j++) {
			// 앞의 값들 중 제일 큰 수열에 nums[i]를 연결
			if(nums[i]>nums[j])
				dp[i] = max(dp[i], dp[j]+nums[i]);
		}
	}
	
	int ans = dp[0];
	for(int i=1; i<n; i++)
		ans = max(ans, dp[i]);

	cout << ans << endl;
}