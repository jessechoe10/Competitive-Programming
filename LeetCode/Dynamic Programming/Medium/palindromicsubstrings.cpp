// Problem Link: https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
	int dp[1000][1000];
	int countSubstrings(string s) {
		int n = s.length();
		int res = 0;
		for(int i = n - 1; i >= 0; i--){
			for(int j = i; j < n; j++){
				if(i == j){
					dp[i][j] = 1;
				} else if(i == j - 1){
					dp[i][j] = (s[i] == s[j]);
				} else {
					dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
				}
				res += dp[i][j];
			}
		}
		return res;
	}
};