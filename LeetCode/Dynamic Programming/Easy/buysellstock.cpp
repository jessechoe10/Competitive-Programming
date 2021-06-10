// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if(prices.size() == 1){
			return 0;
		} else {
			int curMin = prices[0], ans = 0;
			for(int i = 1; i < prices.size(); i++){
				int curProfit = max(0, prices[i] - curMin);
				ans = max(curProfit, ans);
				curMin = min(curMin, prices[i]);
			}
			return ans;
		}
	}
};