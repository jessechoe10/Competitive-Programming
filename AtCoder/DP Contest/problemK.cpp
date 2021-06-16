// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_k

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> dp(k + 1, -1);
	dp[0] = 0;
	for(int i = 1; i <= k; i++){
		dp[i] = 1;
		for(int j = 0; j < n; j++){
			if(a[j] <= i){
				dp[i] = min(dp[i], dp[i - a[j]]);
			}
		}
		dp[i] = !dp[i];
	}
	if(dp[k]){
		cout << "First" << endl;
	} else {
		cout << "Second" << endl;
	}
}