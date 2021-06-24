// Problem Link: https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
	static bool cmp(vector<int> a, vector<int> b){
		return a[0] < b[0];
	}
	int dp[1000];
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end(), cmp);
		int n = pairs.size();
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i = 1; i < n; i++){
			for(int j = 0; j < i; j++){
				if(pairs[i][0] > pairs[j][1]){
					dp[i] = max(dp[i], dp[j] + 1);
				} else {
					dp[i] = max(dp[i], dp[j]);
				}
			}
		}
		return dp[n - 1];
	}
};