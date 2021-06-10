// Problem Link: https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[100000][101];

int main(){
	int n, m; cin >> n >> m;
	int x_0; cin >> x_0;
	if(x_0 == 0){
		for(int i = 1; i <= m; i++){
			dp[0][i] = 1;
		}
	} else {
		dp[0][x_0] = 1;
	}
	for(int i = 1; i < n; i++){
		int x; cin >> x;
		if(x == 0){
			for(int j = 1; j <= m; j++){
				for(int k: {j - 1, j, j + 1}){
					if(k >= 1 && k <= m){
						(dp[i][j] += dp[i - 1][k]) %= MOD;
					}
				}
			}
		} else {
			for(int k: {x - 1, x, x + 1}){
				if(k >= 1 && k <= m){
					(dp[i][x] += dp[i - 1][k]) %= MOD;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= m; i++){
		(ans += dp[n - 1][i]) %= MOD;
	}
	cout << ans << endl;
}