// Problem Link: https://codeforces.com/problemset/problem/1409/E
// Official Editorial: https://codeforces.com/blog/entry/82284

/*
	YoRepi7's analysis:

	We can ignore the y-coordinates in this problem since it suffices to put the platforms at -10^9. Thus, we
	should only consider the x-coordinates in this problem. Obviously, the platforms must be between at least
	one point (with respect to the x-coordinate of that point). Thus, it suffices to find the length of the
	maximum platform continaing a single x-coordinate. However, the problem indicates that there could be up
	to two platforms; thus, it suffices to store the maximum platform after each x-coordinate and add it to
	the total platform length at a given index i. We can compute the maximum length of the containing x_i using
	binary search. The total runtime of this algorithm is O(n log n) since we must sort the x-coordinates prior
	to applying our algorithm above. 
*/

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
