// Problem Link: https://leetcode.com/problems/count-sorted-vowel-strings

class Solution {
public:
		int dfs(int cur, int level, int n){
				if(level == n){
						return cur;
				} else {
						if(cur == 1){
							return 1;
						} else if(cur == 2){
							return dfs(1, level + 1, n) + dfs(2, level + 1, n);
						} else if(cur == 3){
							return dfs(1, level + 1, n) + dfs(2, level + 1, n) + dfs(3, level + 1, n);
						} else if(cur == 4){
							return dfs(1, level + 1, n) + dfs(2, level + 1, n) + dfs(3, level + 1, n) + dfs(4, level + 1, n);
						} else {
							return dfs(1, level + 1, n) + dfs(2, level + 1, n) + dfs(3, level + 1, n) + dfs(4, level + 1, n) + dfs(5, level + 1, n);
						}
				}
		}
		int countVowelStrings(int n) {
				n--;
				if(n == 0){
						return 5;
				} else {
						return dfs(1, 1, n) + dfs(2, 1, n) + dfs(3, 1, n) + dfs(4, 1, n) + dfs(5, 1, n);
				}
		}
};