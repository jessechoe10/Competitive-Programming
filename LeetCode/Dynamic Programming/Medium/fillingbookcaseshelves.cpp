// Problem Link: https://leetcode.com/problems/filling-bookcase-shelves/

class Solution {
public:
	int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
		int n = books.size();
		vector<int> dp(n + 1, 0);
		for(int i = 1; i <= n; i++){
			dp[i] = dp[i - 1] + books[i - 1][1];
			int width = 0, height = 0;
			for(int j = i - 1; j >= 0; j--){
				width += books[j][0];
				if(width > shelf_width){
					break;
				} else {
					height = max(height, books[j][1]);
					dp[i] = min(dp[j] + height, dp[i]);
				}
			}
		}
		return dp[n];
	}
};