// Problem Link: https://leetcode.com/problems/stone-game-vii/

class Solution {
public:
	int prefix[1001];
	int dp[1000][1000];
	int sum(int l, int r){
		return prefix[r + 1] - prefix[l];
	}
	int stoneGameVII(vector<int>& stones) {
		int n = stones.size();
		prefix[0] = 0;
		for(int i = 1; i <= n; i++){
			prefix[i] = prefix[i - 1] + stones[i - 1];
		}
		memset(dp, 0, sizeof(dp));
		for(int i = n - 1; i >= 0; i--){
			for(int j = i + 1; j < n; j++){
				int left = sum(i, j - 1);
				int right = sum(i + 1, j);
				dp[i][j] = max(right - dp[i + 1][j], left - dp[i][j - 1]);
			}
		}
		return dp[0][n - 1];
	}
};