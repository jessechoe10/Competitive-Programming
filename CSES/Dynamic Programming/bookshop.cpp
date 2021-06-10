// Problem Link: https://cses.fi/problemset/task/1158/

#include <bits/stdc++.h>

using namespace std;

int dp[1001][100001];

int main(){
	int n, x; cin >> n >> x;
	vector<int> h(n), s(n);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= x; j++){
			dp[i][j] = dp[i - 1][j];
			if(j - h[i - 1] >= 0){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
			}
		}
	}
	cout << dp[n][x] << endl;
}