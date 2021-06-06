// Problem Link: https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

int main(){
	int n, x; cin >> n >> x;
	vector<int> coins(n);
	for(int i = 0; i < n; i++){
		cin >> coins[i];
	}
	vector<int> dp(x + 1, INF);
	dp[0] = 0;
	for(int i = 1; i <= x; i++){
		int curMin = INF;
		for(int j = 0; j < n; j++){
			if(i - coins[j] >= 0){
				curMin = min(curMin, dp[i - coins[j]] + 1);
			}
		}
		dp[i] = curMin;
	}
	if(dp[x] == INF){
		cout << -1 << endl;
	} else {
		cout << dp[x] << endl;
	}
}