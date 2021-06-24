#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	if(sum < n){
		cout << 1 << endl;
	} else {
		cout << sum - n << endl;
	}
}

int main(){
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
}
