// Problem Link: // Problem Link: https://atcoder.jp/contests/dp/tasks/dp_l

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[3000][3000];

int main(){
	int n; cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(dp, 0, sizeof(dp));
	for(int j = 0; j < n; j++){
		for(int i = j; i >= 0; i--){
			if(i == j){
				dp[i][i] = a[i];
			} else {
				dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
			}
		}
	}
	cout << dp[0][n - 1] << endl;
}