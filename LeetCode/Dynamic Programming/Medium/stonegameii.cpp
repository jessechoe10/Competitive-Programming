// Problem Link: https://leetcode.com/problems/stone-game-ii/

class Solution {
public:
	int dp[101][101];
	int stoneGameII(vector<int>& piles) {
		int n = piles.size();
		vector<int> suffix(n + 1, 0);
		for(int i = n - 1; i >= 0; i--){
			suffix[i] = suffix[i + 1] + piles[i];
		}
		for(int i = 0; i <= n; i++){
			dp[i][n] = suffix[i];
		}
		for(int i = n - 1; i >= 0; i--){
			for(int j = n - 1; j >= 1; j--){
				for(int x = 1; x <= 2 * j && i + x <= n; x++){
					dp[i][j] = max(dp[i][j], suffix[i] - dp[i + x][max(j, x)]);
				}
			}
		}
		return dp[0][1];
	}
};