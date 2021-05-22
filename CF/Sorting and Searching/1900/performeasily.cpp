// Problem Link: https://codeforces.com/contest/1413/problem/C
// Official Editorial: https://codeforces.com/blog/entry/84056

/*
	YoRepi7's analysis:

	Given that the size of a is 6 (which is relatively small), iterating through each 
	of the differences still runs in time. The number of possible differences will be
	precisely 6n operations. The problem asks us to find the minimal possible difference
	between the indices of the frets.

	Assume that we fix the maximal index of the fret. It remains to compute the minimal
	index of the fret. We can compute this fret using binary search to find the closest
	minimal index of the fret to the fixed maximal index.

	However, in order to apply binary search, we must sort both arrays a and b.

	It remains to iterate over each of the possible differences (each of the
	differences represents a fixed maximal index since b_j = a_i + k --> 
	b_j - a_i = k, k represnts an index).

	We can find the closest possible minimal index using binary search. 
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;

using msi = multiset<int>;
using si = set<int>;

using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

using msl = multiset<ll>;
using sl = set<ll>;

#define print(x) cout << x << endl
#define dbg(x) for(auto& a: x) cout << a << " "
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(all(X), greater<ll>())
#define ub(a, x) upper_bound(all(a), x) - begin(a)
#define lb(a, x) lower_bound(all(a), x) - begin(a)
#define FASTIO cin.tie(0)->sync_with_stdio(0)

int main(){
	FASTIO;
	vector<int> a(6);
	for(int i = 0; i < 6; i++){
		cin >> a[i];
	}
	int n; cin >> n;
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	b.push_back(2e9);
	int ans = 2e9;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < n; j++){
			if(b[j] - a[i] >= b[n - 1] - a[5]){
				int cur = b[0] - a[0];
				for(int k = 0; k < 5; k++){
					cur = min(cur, b[ub(b, a[k] + b[j] - a[i])] - a[k + 1]);
				}
				ans = min(ans, b[j] - a[i] - cur);
			}
		}
	}
	cout << ans << endl;
}