// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>

using namespace std;

int dist(int height1, int height2){
	return abs(height1 - height2);
}

int main(){
	int n; cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	vector<int> dp(n, 0);
	for(int i = 1; i < n; i++){
		if(i == 1){
			dp[i] = dp[i - 1] + dist(h[i - 1], h[i]);
		} else {
			dp[i] = min(dp[i - 1] + dist(h[i - 1], h[i]), dp[i - 2] + dist(h[i - 2], h[i]));
		}
	}
	cout << dp[n - 1] << endl;
}