// Problem Link: https://cses.fi/problemset/task/2413/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll dp[1000000][2];

int main(){
	dp[0][0] = 1, dp[0][1] = 1;
	for(int i = 1; i <= 1e6; i++){
		dp[i][0] = ((dp[i - 1][0] * 4) % MOD + dp[i - 1][1]) % MOD;
		dp[i][1] = ((dp[i - 1][1] * 2) % MOD + dp[i - 1][0]) % MOD;
	}
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		int n; cin >> n;
		cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;
	}
}