// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
	int dp[50000][2];
	int maxProfit(vector<int>& prices, int fee) {
		int n = prices.size();
		memset(dp, 0, sizeof(dp));
		dp[0][1] = -prices[0] - fee;
		for(int i = 1; i < n; i++){
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
			dp[i][0] = max(dp[i - 1][0], prices[i] + dp[i][1]);
		}
		return dp[n - 1][0];
	}
};