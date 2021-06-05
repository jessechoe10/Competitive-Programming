// Problem Link: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

class Solution {
public:
	int dp[3][1001];
	int drop(int eggs, int floorsRemaining){
		if(eggs == 1 || floorsRemaining <= 1){
			return floorsRemaining;
		}
		if(dp[eggs][floorsRemaining] > 0){
			return dp[eggs][floorsRemaining];
		}
		int ans = 1001;
		for(int i = 1; i <= floorsRemaining; i++){
			ans = min(ans, 1 + max(drop(eggs - 1, i - 1), drop(eggs, floorsRemaining - i)));
		}
		dp[eggs][floorsRemaining] = ans;
		return ans;
	}
	int twoEggDrop(int n) {
		return drop(2, n);    
	}
};