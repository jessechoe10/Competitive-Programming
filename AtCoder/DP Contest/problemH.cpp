// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_h

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[1000][1000], grid[1000][1000];

int main(){
	int h, w; cin >> h >> w;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			char c; cin >> c;
			grid[i][j] = (c == '.');
		}
	}
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < h; i++){
		if(grid[i][0]) dp[i][0] = 1;
		else break;
	}
	for(int i = 0; i < w; i++){
		if(grid[0][i]) dp[0][i] = 1;
		else break;
	}
	for(int i = 1; i < h; i++){
		for(int j = 1; j < w; j++){
			if(grid[i][j]){
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
				dp[i][j] %= MOD;
			} else {
				dp[i][j] = 0;
			}
		}
	}
	cout << (dp[h - 1][w - 1]) % MOD << endl;
}