// Problem Link: https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
	static bool compare(string &s1, string &s2){
		return s1.size() < s2.size();
	}
	int longestStrChain(vector<string>& words) {
		sort(words.begin(), words.end(), compare);
		unordered_map<string, int> dp;
		int res = 0;
		for(string w: words){
			for(int i = 0; i < w.length(); i++){
				string predecessor = w.substr(0, i) + w.substr(i + 1);
				dp[w] = max(dp[w], (dp.find(predecessor) == dp.end()) ? 1: dp[predecessor] + 1);
			}
			res = max(res, dp[w]);
		}
		return res;
	}
};