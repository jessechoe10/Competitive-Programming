#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define print(x) cout << x << endl
#define dbg(x) for(auto& a: x) cout << a << " "
#define all(x) begin(x), end(x)
#define ub(a, x) upper_bound(all(a), x) - begin(a)
#define lb(a, x) lower_bound(all(a), x) - begin(a)

void solve(int tc){
	int n, k; cin >> n >> k;
	vector<int> x(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	for(int i = 0; i < n; i++){
		ll y; cin >> y;
	}
	sort(x.begin(), x.end());
	int ans = 0, dist = 0;
	for(int i = 0; i < n; i++){
		int pos = ub(x, x[i] + k);
		ans = max(ans, pos + dist - i);
		pos = lb(x, x[i] - k);
		dist = max(dist, i - pos + 1);
	}
	cout << ans << endl;
}

int main(){
	int t; cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);
	}
}