// Problem Link: https://cses.fi/problemset/task/1713

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int maxDiv[MAXN + 1];

void sieve(){
	for(int i = 2; i <= MAXN; i++){
		if(maxDiv[i] == 0){
			for(int j = i; j <= MAXN; j += i){
				maxDiv[j] = i;
			}
		}
	}
}

void solve(){
	int x; cin >> x;
	int ans = 1;
	while(x != 1){
		int prime = maxDiv[x];
		int count = 0;
		while(x % prime == 0){
			x /= prime;
			count++;
		}
		ans *= (count + 1);
	}
	cout << ans << endl;
}

int main(){
	int n; cin >> n;
	sieve();
	for(int i = 0; i < n; i++){
		solve();
	}
}