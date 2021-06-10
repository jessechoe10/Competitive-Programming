// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int dist(int height1, int height2){
	return abs(height1 - height2);
}

int main(){
	int n, k; cin >> n >> k;
	vector<int> h(n);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	vector<int> dp(n, 0);
	for(int i = 1; i < n; i++){
		int cost = INF;
		for(int j = 1; j <= k; j++){
			if(i - j >= 0){
				cost = min(cost, dp[i - j] + dist(h[i], h[i - j]));
			}
		}
		dp[i] = cost;
	}
	cout << dp[n - 1] << endl;
}