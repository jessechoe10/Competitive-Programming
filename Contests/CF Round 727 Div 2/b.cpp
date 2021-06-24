#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[26][100001];

void solve(){
	int n, q; cin >> n >> q;
	string s; cin >> s;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(char c = 'a'; c <= 'z'; c++){
			int l = c - 'a';
			dp[l][i] = dp[l][i - 1];
			if(s[i - 1] == c){
				dp[l][i]++;
			}
		}
	}
	for(int i = 0; i < q; i++){
		int l, r; cin >> l >> r;
		int ans = 0;
		for(char c = 'a'; c <= 'z'; c++){
			int repeat = (c - 'a' + 1);
			ans += repeat * (dp[repeat - 1][r] - dp[repeat - 1][l - 1]);
		}
		cout << ans << endl;
	}
}

int main(){
	// int t; cin >> t;
	// for(int i = 0; i < t; i++){
	// 	solve();
	// }
	solve();
}
