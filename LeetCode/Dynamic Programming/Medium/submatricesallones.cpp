// Problem Link: https://leetcode.com/problems/count-submatrices-with-all-ones/
// Good Brute Force: https://leetcode.com/problems/count-submatrices-with-all-ones/discuss/721266/C%2B%2B-Understand-the-brute-force-solution-first!
// Good Solution: https://leetcode.com/problems/count-submatrices-with-all-ones/discuss/1249570/DP-O(N3)-time-O(N2)-space-with-optimizations-or-Python
// Good Solution with Visual: https://leetcode.com/problems/count-submatrices-with-all-ones/discuss/1214068/4-solutions

class Solution {
public:
	int dpline[151][151], dptot[151][151];
	int numSubmat(vector<vector<int>>& mat) {
		int n = mat.size();
		int m = mat[0].size();
		memset(dpline, 0, sizeof(dpline));
		memset(dptot, 0, sizeof(dptot));
		int res = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(mat[i - 1][j - 1] == 1){
					dpline[i][j] = dpline[i][j - 1] + 1;
					int cur = dpline[i][j];
					dptot[i][j] = cur;
					for(int k = i - 1; k >= 1; k--){
						if(dpline[k][j] < cur){
							dptot[i][j] += dptot[k][j];
							break;
						}
						dptot[i][j] += cur;
					}
				}
				res += dptot[i][j];
			}
		}
		return res;
	}
};