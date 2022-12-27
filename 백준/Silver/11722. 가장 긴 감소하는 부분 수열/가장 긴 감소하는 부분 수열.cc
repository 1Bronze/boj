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
		dp[i] = 1;	

	for(int i=1; i<n; i++) {
		for(int j=0; j<i; j++) {
			// nums[i]가 nums[j]보다 작다면, dp[i]는 jp[j] 뒤에 nums[j]가 붙어 jp[j]+1
			if(nums[i]<nums[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
	}
	
	int ans = dp[0];
	for(int i=1; i<n; i++)
		ans = max(ans, dp[i]);

	cout << ans << endl;
}