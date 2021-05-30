// Problem Link: https://codeforces.com/problemset/problem/1358/D
// Official Editorial: https://codeforces.com/blog/entry/77869

/*
	YoRepi7's analysis:

	The problem is asking us to find the maximum subarray sum given an infinitely repeating array.

	However, due to the fact that x is less than the sum of d_i for all months, we don't have to account
	for multiple cycles in our infinitely repeating array. Let's just focus on one particular cycle.

	We can look at precisely two of the arrays to account for the possiblilty that the maximum subarray
	includes the end and start of the array.

	However, due to the constraints provided, we must find a linear time solution meaning that we cannot
	use brute force to find the maximum subarray.

	Suppose that we fix the end (right) of the subarray (greedily, we should fix the end of the subarray
	as each d_i).

	To find the start (left) of the subarray, we should use binary search and prefix sums.

	After finding the start of the subarray, it remains to compute the subarray sum between [left, right] 
	using prefix sums. For this part, however, we must apply the (k) * (k + 1) / 2 formula for the sum of the
	first n numbers. We must add (k) * (k + 1) / 2 to each element in the prefix sums array where k represents
	d_i.

	Once we figure out the subarray sum between [left, right], we should compute the maximum of those for
	all values of d_i in the duplicated array.
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(all(X), greater<ll>())
#define ub(a, x) upper_bound(all(a), x) - begin(a)
#define lb(a, x) lower_bound(all(a), x) - begin(a)
#define FASTIO cin.tie(0)->sync_with_stdio(0)

int main(){
	FASTIO;
	ll n, x; cin >> n >> x;
	vector<ll> d(2 * n);
	for(int i = 0; i < n; i++){
		cin >> d[i];
	}
	for(int i = n; i < 2 * n; i++){
		d[i] = d[i - n];
	}
	n *= 2;
	vector<ll> dp1(n + 1, 0);
	for(int i = 1; i <= n; i++){
		dp1[i] = dp1[i - 1] + d[i - 1];
	}
	vector<ll> dp2(n + 1, 0);
	for(int i = 1; i <= n; i++){
		dp2[i] = dp2[i - 1] + ((d[i - 1]) * (d[i - 1] + 1)) / 2;
	}
	ll ans = 0;
	for(int r = 1; r <= n; r++){
		if(dp1[r] - x < 0){
			continue;
		} else {
			int l = ub(dp1, dp1[r] - x);
			l = max(0, l - 1);
			ll extra = (dp1[r] - dp1[l]) - x;
			ll remove = ((extra) * (extra + 1)) / 2;
			ll hugs = (dp2[r] - dp2[l]) - remove;
			ans = max(ans, hugs);
		}
	}
	cout << ans << endl;
}