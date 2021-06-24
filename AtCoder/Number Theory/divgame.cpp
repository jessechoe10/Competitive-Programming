#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pl = pair<ll, ll>;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	map<ll, ll> factors;
	for(ll i = 2; i * i <= n; i++){
		while(n % i == 0){
			factors[i]++;
			n /= i;
		}
	}
	if(n > 1){
		factors[n]++;
	}
	ll ops = 0;
	for(pl a: factors){
		ll sum = 0, cur = 0;
		while(sum <= a.second){
			cur++;
			sum += cur;
		}
		if(sum == a.second){
			ops += cur;
		} else {
			ops += cur - 1;
		}
	}
	cout << ops << endl;
}