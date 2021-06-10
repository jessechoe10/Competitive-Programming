// Problem Link: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n + 1, 0);
		for(int i = 1; i <= n; i++){
			dp[i] = dp[i-1] + nums[i-1];
		}
		int curMin = dp[0], ans = nums[0];
		for(int i = 1; i <= n; i++){
			ans = max(ans, dp[i] - curMin);
			curMin = min(dp[i], curMin);
		}
		return ans;
	}
};