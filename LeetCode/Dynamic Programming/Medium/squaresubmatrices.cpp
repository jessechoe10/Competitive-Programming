// Problem Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones

class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<int>> dp(n + 1);
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= m; j++){
				dp[i].push_back(0);
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}
		
		int len = min(n, m), res = 0;
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				for(int k = 0; k < len; k++){
					int A = min(i + k, n), B = min(j + k, m);
					int sum = dp[A][B] - dp[A][j - 1] - dp[i - 1][B] + dp[i - 1][j - 1];
					int area = (k + 1) * (k + 1);
					if(sum == area){
						res++;
					}
				}
			}
		}
		return res;
	}
};