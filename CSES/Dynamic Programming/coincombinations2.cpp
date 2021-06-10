// Problem Link: https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[101][1000001];

int main(){
	int n, x; cin >> n >> x;
	vector<int> c(n);
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - c[i - 1] >= 0){
                dp[i][j] += dp[i][j - c[i - 1]];
                dp[i][j] %= MOD;
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][x] << endl;
}