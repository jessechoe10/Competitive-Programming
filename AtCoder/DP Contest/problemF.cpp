// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_f

#include <bits/stdc++.h>

using namespace std;

int dp[3001][3001];
string s, t, ans;

void solve(int i, int j){
	if(i < 1 || j < 1) return;
	if(s[i - 1] == t[j - 1]){
		ans += s[i - 1];
		solve(i - 1, j - 1);
		return;
	}
	if(dp[i - 1][j] > dp[i][j - 1]) solve(i - 1, j);
	else solve(i, j - 1);
}

int main(){
	cin >> s >> t;
	int n = s.length();
	int m = t.length();
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i - 1] == t[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	solve(n, m);
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}