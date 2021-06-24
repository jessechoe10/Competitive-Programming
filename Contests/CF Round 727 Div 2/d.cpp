#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pl = pair<ll, ll>;

bool cmp(pl a, pl b){
	if(a.second == b.second){
		return a.first > b.first;
	} else {
		return a.second > b.second;
	}
}

void solve(){
	int n; cin >> n;
	vector<pl> product(n);
	ll ans = 0, prods = 0;
	for(int i = 0; i < n; i++){
		cin >> product[i].first >> product[i].second;
		ans += product[i].first * 2; prods += product[i].first;
	}
	sort(product.begin(), product.end(), cmp);
	for(int i = 0; i < n; i++){
		ll x = prods - product[i].second;
		x = max(0LL, x);
		x = min(x, product[i].first);
		prods -= x;
		ans -= x;
	}
	cout << ans << endl;
}

int main(){
	// int t; cin >> t;
	// for(int i = 0; i < t; i++){
	// 	solve();
	// }
	solve();
}
