// Problem Link: https://leetcode.com/problems/airplane-seat-assignment-probability/

class Solution {
public:
	double nthPersonGetsNthSeat(int n) {
		if(n == 1){
			return n;
		} else {
			return 0.5;
		}
	}
};