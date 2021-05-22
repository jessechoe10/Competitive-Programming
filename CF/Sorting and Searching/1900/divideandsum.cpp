// Problem Link: https://codeforces.com/problemset/problem/1444/B
// Official Editorial: https://codeforces.com/blog/entry/84248

/*
	YoRepi7's analysis:

	Let's consider two separate arrays L and R...

	L represents the array: a1, a2, ... , an-1, an
	R represents the array: an+1, an+2, ... , a2n-1, a2n

	The problem states that there will be two arrays p, q
	where p is sorted from least to greatest and q is sorted
	from greatest to least.

	If q contains elements from the array R, those will appear
	first in array q before the elements in array L.

	If p contains elements from the array L, those will appear
	first in the array p before the elements in array R.

	Additionally, we know that the elements from array L cannot
	appear first in both arrays p and q. This property is also 
	applied to array R.

	Thus, it can be proven that an element in array R MUST always
	be paired with an element in array L. Since we know that an 
	element in array L is less than an element in array R, it suffices
	to say that every element in array R will be positive and every
	element in array L will be in f(p, q) negative (note: this is because
	x_i must be an element from array p and y_i must be an element from
	array q).

	The number of unique partitions of array a is (2n)C(n), so the answer
	will be the difference between the sum of all of the elements in R and
	the sum of all of the elements in L times (2n)C(n). Note: you must print
	the answer modulo 998244353.

	To improve our binomial coefficient runtime / memory used, please click
	this link: https://cp-algorithms.com/combinatorics/binomial-coefficients.html.
	Specifically, please review "Binomial coefficient modulo large prime" to learn
	about how you can use modular inverses to solve this problem.

	The runtime of this algorithm is O(n log n), which passes in time!
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

const ll MOD = 998244353;

// Choose function copied and pasted from here: https://www.geeksforgeeks.org/binomial-coefficient-dp-9/?ref=rp

ll choose(ll n, ll r){
 
	if (r > n)
		return 0;
	long long int inv[r + 1] = { 0 };
	inv[0] = 1;
	if(r+1>=2)
	inv[1] = 1;

	for (int i = 2; i <= r; i++) {
		inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
	}
 
	int ans = 1;
 
	for (int i = 2; i <= r; i++) {
		ans = ((ans % MOD) * (inv[i] % MOD)) % MOD;
	}
 
	for (int i = n; i >= (n - r + 1); i--) {
		ans = ((ans % MOD) * (i % MOD)) % MOD;
	}
	return ans;
}

void solve(int tc){
	int n; cin >> n;
	vl a(2 * n);
	for(int i = 0; i < 2 * n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll leftSum = 0, rightSum = 0;
	for(int i = 0; i < n; i++){
		leftSum += a[i];
	}
	for(int i = n; i < 2*n; i++){
		rightSum += a[i];
	}
	ll f = rightSum - leftSum; f %= MOD;
	ll combos = choose(2 * n, n) % MOD;
	cout << (combos * f) % MOD << endl;
}

int main(){
	FASTIO;
	solve(1);
}
