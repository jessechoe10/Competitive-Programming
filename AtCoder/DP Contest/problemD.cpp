// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	int n, w; cin >> n >> w;
	vector<ll> dp(w + 1);
	for(int i = 0; i < n; i++){
		int w_i, v_i; cin >> w_i >> v_i;
		for(int j = w; j >= w_i; j--){
			dp[j] = max(dp[j], dp[j - w_i] + v_i);
		}
	}
	ll ans = 0;
	for(int i = 0; i <= w; i++){
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}