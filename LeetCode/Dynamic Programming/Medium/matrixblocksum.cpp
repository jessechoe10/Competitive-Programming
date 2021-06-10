// Problem Link: https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
		int n = mat.size(), m = mat[0].size();
		vector<vector<int>> dp(n + 1);
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= m; j++){
				dp[i].push_back(0);
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
			}
		}
		vector<vector<int>> blockSum(n);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				int a = max(i - k, 1), b = max(j - k, 1);
				int A = min(i + k, n), B = min(j + k, m);
				blockSum[i - 1].push_back(dp[A][B] - dp[A][b - 1] - dp[a - 1][B] + dp[a - 1][b - 1]);
			}
		}
		return blockSum;
	}
};