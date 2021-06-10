// Problem Link: https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		int n = arr.size();
		vector<int> dp(n+1, 0);
		for(int i = 1; i <= n; i++){
			int cur = 0;
			for(int j = 1; j <= min(i, k); j++){
				int mx = 0;
				for(int a = 1; a <= j; a++){
					mx = max(mx, arr[i - a]);
				}
				cur = max(mx * j + dp[i - j], cur);
			}
			dp[i] = cur;
		}
		return dp[n];
	}
};