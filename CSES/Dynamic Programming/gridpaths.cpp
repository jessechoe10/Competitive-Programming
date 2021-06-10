// Problem Link: https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[1000][1000], grid[1000][1000];

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c; cin >> c;
			grid[i][j] = (c == '.') ? 1 : 0; 
		}
	}
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(grid[i][j]){
				if(i > 0){
					(dp[i][j] += dp[i - 1][j]) %= MOD;
				}
				if(j > 0){
					(dp[i][j] += dp[i][j - 1]) %= MOD;
				}
			} else {
				dp[i][j] = 0;
			}
		}
	}
	cout << dp[n - 1][n - 1] << endl;
}
