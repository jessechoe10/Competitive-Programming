// Problem Link: https://cses.fi/problemset/task/1639/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dp[5001][5001];

int main(){
	string a; cin >> a;
	string b; cin >> b;
	int n = a.size(), m = b.size();
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = 1e9;
		}
	}
	dp[0][0] = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i){
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			}
			if(j){
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			}
			if(i && j){
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
			}
		}
	}
	cout << dp[n][m] << endl;
}