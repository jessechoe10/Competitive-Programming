// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_e

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e12;

int main(){
	int n, w; cin >> n >> w;
	int v = 0;
	vector<int> wi(n), vi(n);
	for(int i = 0; i < n; i++){
		cin >> wi[i] >> vi[i];
		v += vi[i];
	}
	vector<ll> dp(v + 1);
	for(int i = 1; i <= v; i++) dp[i] = INF;
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		int w_i = wi[i], v_i = vi[i];
		for(int j = v; j >= v_i; j--){
			dp[j] = min(dp[j], dp[j - v_i] + w_i);
		}
	}
	for(int i = v; i >= 0; i--){
		if(dp[i] <= w){
			cout << i << endl;
			break;
		}
	}
}