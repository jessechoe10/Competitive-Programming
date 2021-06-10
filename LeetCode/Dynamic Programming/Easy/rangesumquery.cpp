// Problem Link: https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
public:
	vector<int> dp;
	NumArray(vector<int>& nums) {
		dp.resize(nums.size() + 1); dp[0] = 0;
		for(int i = 1; i <= nums.size(); i++){
			dp[i] = dp[i-1] + nums[i-1];
		}
	}
	
	int sumRange(int left, int right) {
		return dp[right + 1] - dp[left];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */