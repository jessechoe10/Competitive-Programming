// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_i

#include <bits/stdc++.h>

using namespace std;

double dp[3000][3000];

int main(){
	int n; cin >> n;
	vector<double> p(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	dp[0][0] = 1.0;
	for(int i = 1; i <= n; i++){
		dp[i][0] = dp[i - 1][0] * p[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i; j++){
			dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i]); 
		}
	}
	double ans = 0.0;
	for(int i = n / 2 + 1; i <= n; i++){
		ans += dp[n][i];
	}
	cout << setprecision(9) << ans << endl;
}