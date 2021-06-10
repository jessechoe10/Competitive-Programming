// Problem Link: https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		set<int> traveled(days.begin(), days.end());
		vector<int> dp(366);
		for(int i = 1; i <= 365; i++){
			dp[i] = dp[i - 1];
			if(traveled.find(i) != traveled.end()){
				dp[i] = min(dp[i - 1] + costs[0], min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
			}
		}
		return dp[365];
	}
};