// Problem Link: https://codeforces.com/problemset/problem/1475/D
// Official Editorial: https://codeforces.com/blog/entry/87188

/*
	YoRepi7's analysis:

	Suppose that we fix the memories of the "important applications",
	and only look at the memories of the "regular applications". 
	For each regular application, it suffices to free up as many important
	applications as possible. We can free up the important applications
	until the total memory remaining over all applications gets closer
	to m. We can greedily sort the memories of each list in decreasing
	order and apply two pointers from there.
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int tc){
	int n, m; cin >> n >> m;
	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<ll> reg, imp;
	for(int i = 0; i < n; i++){
		int b; cin >> b;
		if(b == 1) reg.push_back(a[i]);
		else imp.push_back(a[i]);
	}
	sort(reg.begin(), reg.end(), greater<ll>());
	sort(imp.begin(), imp.end(), greater<ll>());
	ll curSum = 0;
	for(ll cur: imp) curSum += cur;
	int j = imp.size() - 1, ans = 2 * n + 1;
	for(int i = 0; i <= reg.size(); i++){
		while(j >= 0 && curSum - imp[j] >= m){
			curSum -= imp[j];
			j--;
		}
		if(curSum >= m){
			ans = min(ans, i + 2 * (j + 1));
		}
		if(i < reg.size()){
			curSum += reg[i];
		}
	}
	if(ans == 2 * n + 1) cout << -1 << endl;
	else cout << ans << endl;
}

int main(){
	int t; cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);
	}
}