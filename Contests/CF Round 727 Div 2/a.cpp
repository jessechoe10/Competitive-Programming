#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(){
	ll n, x, t; cin >> n >> x >> t;
	if(t < x){
		cout << 0 << endl;
		return;
	} else {
		ll full = t / x;
		if(n < full){
			cout << (n - 1) * (n) / 2 << endl;
		} else {
			ll ans = full * (n - full);
			ll x = n - full;
			ans += (n - x - 1) * (n - x) / 2;
			cout << ans << endl;
		}
	}
}

int main(){
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
}
