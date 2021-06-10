// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>

using namespace std;

int dp[100000][3], happy[100000][3];

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> happy[i][0] >> happy[i][1] >> happy[i][2];
	}
	for(int i = 0; i < 3; i++){
		dp[0][i] = happy[0][i];
	}
	for(int i = 1; i < n; i++){
		for(int j = 0; j < 3; j++){
			if(j == 0){
				dp[i][j] = max(dp[i - 1][1], dp[i - 1][2]) + happy[i][j];
			} else if(j == 1){
				dp[i][j] = max(dp[i - 1][0], dp[i - 1][2]) + happy[i][j];
			} else {
				dp[i][j] = max(dp[i - 1][0], dp[i - 1][1]) + happy[i][j];
			}
		}
	}
	cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;
}