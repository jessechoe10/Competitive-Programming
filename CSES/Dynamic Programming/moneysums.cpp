// Problem Link: https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>

using namespace std;

bool dp[101][100001];

int main(){
	int n; cin >> n;
	vector<int> x(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	int maxSum = n * 1000;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= maxSum; j++){
			dp[i][j] = false;
		}
	}
	dp[0][0] = true;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= maxSum; j++){
			dp[i][j] = dp[i - 1][j];
			if((j - x[i - 1] >= 0) && (dp[i - 1][j - x[i - 1]])){
				dp[i][j] = true;
			}
		}
	}
	vector<int> moneySums;
	for(int i = 1; i <= maxSum; i++){
		if(dp[n][i]){
			moneySums.push_back(i);
		}
	}
	cout << moneySums.size() << endl;
	for(int i: moneySums){
		cout << i << " ";
	}
	cout << endl;
}