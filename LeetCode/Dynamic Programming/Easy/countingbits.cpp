// Problem Link: https://leetcode.com/problems/counting-bits/

class Solution {
public:
	vector<int> countBits(int num) {
		if(num == 0){
			return {0};
		}
		vector<int> dp(num + 1);
		dp[0] = 0, dp[1] = 1;
		int pow2 = 2;
		for(int i = 2; i <= num; i++){
			if(i == pow2 * 2){
				pow2 = i;
			}
			dp[i] = dp[i - pow2] + 1;
		}
		return dp;
	}
};