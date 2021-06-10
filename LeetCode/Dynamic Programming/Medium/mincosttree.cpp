// Problem Link: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

class Solution {
public:
	int maxdp[41][41];
	int dp[41][41];
	int compute(int l, int r){
		if(l == r) return 0;
		if(dp[l][r] != -1) return dp[l][r];
		int ans = 1<<30;
		for(int i = l; i < r; i++){
			ans = min(ans, maxdp[l][i] * maxdp[i + 1][r] + compute(l, i) + compute(i + 1, r));
		}
		dp[l][r] = ans;
		return ans;
	}
	int mctFromLeafValues(vector<int>& arr) {
		int n = arr.size();
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < n; i++){
			maxdp[i][i] = arr[i];
			for(int j = i + 1; j < n; j++){
				maxdp[i][j] = max(maxdp[i][j - 1], arr[j]);
			}
		}
		return compute(0, n-1);
	}
};