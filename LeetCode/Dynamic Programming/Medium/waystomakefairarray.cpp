// Problem Link: https://leetcode.com/problems/ways-to-make-a-fair-array/

class Solution {
public:
	int waysToMakeFair(vector<int>& nums) {
		int n = nums.size();
		vector<int> odd(n + 1), even(n + 1);
		for(int i = 1; i <= n; i++){
			if((i - 1) % 2 == 0){
				even[i] = nums[i - 1];
			} else {
				odd[i] = nums[i - 1];
			}
		}
		for(int i = 1; i <= n; i++){
			even[i] += even[i - 1];
			odd[i] += odd[i - 1];
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			int evenSum = even[i - 1] + (odd[n] - odd[i]);
			int oddSum = odd[i - 1] + (even[n] - even[i]);
			ans += (evenSum == oddSum);
		}
		return ans;
	}
};