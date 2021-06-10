// Problem Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution {
public:
	int dp[1001][1001];
	int minimumDeleteSum(string s1, string s2) {
		int n = s1.length(), m = s2.length();
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= m; j++){
				dp[i][j] = 1e9;
			}
		}
		dp[0][0] = 0;
		for(int i = 1; i <= m; i++){
			dp[0][i] = dp[0][i - 1] + int(s2[i - 1]);
		}
		for(int i = 1; i <= n; i++){
			dp[i][0] = dp[i - 1][0] + int(s1[i - 1]);
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + int(s1[i - 1]));
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + int(s2[j - 1]));
				if(s1[i - 1] != s2[j - 1]){
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + int(s1[i - 1]) + int(s2[j - 1]));
				} else {
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
				}
			}
		}
		return dp[n][m];
	}
};