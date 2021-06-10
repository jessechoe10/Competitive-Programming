// Good Editorial: https://leetcode.com/problems/where-will-the-ball-fall/discuss/1250256/Top-Down-C%2B%2B-Solution.-Easy-Explanation
// Problem Link: https://leetcode.com/problems/where-will-the-ball-fall/discuss/1250256/Top-Down-C%2B%2B-Solution.-Easy-Explanation

class Solution {
public:
	int dp[101][101];
	int dfs(vector<vector<int>>& grid, int i, int j, int n, int m){
		if(i == n){
			return dp[i][j] = j;
		}
		if(dp[i][j] != -1){
			return dp[i][j];
		}
		// Redirects to left wall
		if(i < n && i >= 0 && j == 0 && grid[i][j] == -1){
			return dp[i][j] = -1;
		}
		// Redirects to right wall
		if(i < n && i >= 0 && j == m - 1 && grid[i][j] == 1){
			return dp[i][j] = -1;
		}
		// V shaped pattern from left side
		if(i < n && i >= 0 && j < m && j >= 0 && j + 1 >= 0 && j + 1 < m && grid[i][j + 1] == -1 && grid[i][j] == 1){
			return dp[i][j] = -1;
		}
		// V shaped pattern from right side
		if(i < n && i >= 0 && j < m && j >= 0 && j - 1 >= 0 && j - 1 < m && grid[i][j] == -1 && grid[i][j - 1] == 1){
			return dp[i][j] = -1;
		}
		// Spans to the right
		if(j + 1 < m && grid[i][j] == 1){
			return dp[i][j] = dfs(grid, i + 1, j + 1, n, m);
		}
		// Spans to the left
		if(j - 1 >= 0 && grid[i][j] == -1){
			return dp[i][j] = dfs(grid, i + 1, j - 1, n, m);
		}
		return dp[i][j] = -1;
	}
	vector<int> findBall(vector<vector<int>>& grid) {
		vector<int> ballCols;
		int n = grid.size(), m = grid[0].size();
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < m; i++){
			ballCols.push_back(dfs(grid, 0, i, n, m));
		}
		return ballCols;
	}
};