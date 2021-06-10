// Problem Link: https://cses.fi/problemset/task/1744

#include <bits/stdc++.h>

using namespace std;

int dp[501][501];

int main(){
	int a, b; cin >> a >> b;
	for(int i = 0; i <= a; i++){
		for(int j = 0; j <= b; j++){
			if(i == j){
				dp[i][j] = 0;
			} else {
				dp[i][j] = 250000;
				for(int k = 1; k < j; k++){
					dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
				}
				for(int k = 1; k < i; k++){
					dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
				}
			}
		}
	}
	cout << dp[a][b] << endl;
}