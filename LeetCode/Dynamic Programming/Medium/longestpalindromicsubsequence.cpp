// Problem Link: https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
	int dp[1000][1000];
	int longestPalindromeSubseq(string s) {
		int n = s.length();
		for(int i = 0; i < n; i++){
			dp[i][i] = 1;
		}
		for(int i = n - 1; i >= 0; i--){
			for(int j = i + 1; j < n; j++){
				if(s[i] == s[j]){
					dp[i][j] = dp[i + 1][j - 1] + 2;
				} else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][n - 1];
	}
};