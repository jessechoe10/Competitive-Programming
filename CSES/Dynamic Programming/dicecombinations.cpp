// Problem Link: https://cses.fi/problemset/task/1633/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main(){
	ll n; cin >> n;
	vector<ll> dp(n + 1);
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; (j <= i && j <= 6); j++){
			dp[i] += dp[i - j];
		}
		dp[i] %= MOD;
	}
	cout << dp[n] << endl;
}