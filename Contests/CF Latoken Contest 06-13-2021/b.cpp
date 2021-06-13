#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(){
	int n; cin >> n;
	vl a; a.push_back(0);
	ll res = 0;
	for(int i = 0; i < n; i++){
		ll ai; cin >> ai;
		a.push_back(ai);
	}
	a.push_back(0);
	for(int i = 1; i <= n + 1; i++){
		res += abs(a[i] - a[i - 1]);
	}
	for(int i = 1; i <= n; i++){
		if(a[i] > a[i - 1] && a[i] > a[i + 1]){
			res -= min(a[i] - a[i - 1], a[i] - a[i + 1]);
		}
	}
	cout << res << endl;
}

int main(){
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
}
