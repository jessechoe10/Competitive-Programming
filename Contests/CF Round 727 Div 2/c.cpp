#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll ceil(ll a, ll b){
	if(a % b == 0){
		return (a / b);
	} else {
		return (a / b) + 1;
	}
}

void solve(){
	int n; ll k, x; cin >> n >> k >> x;
	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<ll> diff;
	ll groups = 0;
	for(int i = 1; i < n; i++){
		if(a[i] - a[i - 1] > x){
			diff.push_back(a[i] - a[i - 1]);
			groups++;
		}
	}
	sort(diff.begin(), diff.end());
	for(ll d: diff){
		if(ceil(d, x) - 1 <= k){
			groups--;
			k -= (ceil(d, x) - 1);
		}
	}
	cout << groups + 1 << endl;
}

int main(){
	// int t; cin >> t;
	// for(int i = 0; i < t; i++){
	// 	solve();
	// }
	solve();
}
