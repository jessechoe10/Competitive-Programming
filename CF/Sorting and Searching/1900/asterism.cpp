// Problem Link: https://codeforces.com/problemset/problem/1444/B
// Official Editorial: https://codeforces.com/blog/entry/84248

/*
	YoRepi7's analysis:

	Due to the relatively small constraints on n, it suffices to solve this problem
	using a quadratic time solution.

	There are two subtasks to this problem:

	1. Check how many valid permutations P exist.
	2. Check if the number of permutations is divisible by p...

	For the first subtask of this problem it suffices to use the fundamental counting
	principle and binary search to compute the number of permutations.

	Initially, we notice that in order for a permutation to be valid x >= a_(i), x + 1 >= a_(i+1),
	x + 2 >= a_(i+2), ... , x + n - 1 >= a_(i+n-1) must be valid for each value of x from x to 
	x + n - 1. 

	In order to compute the number of valid permutations, it remains to check how many values of 
	a_(i) satisfy the property: x + i >= a_(i).

	We can compute the number of values of a_(i) that satisfy the above property by sorting a and 
	applying binary search!

	For the second subtask of this problem we should use modular properties to check if the number
	of permutations is divisible by p.

	Firstly, we must compute the number of permutations by multiplying the count of values of a_(i)
	- fundamental counting principle.

	However, we must take note that if we multiply each value and store it in C, C will significantly
	overflow even with long longs.

	Fortunately, modular arithmetic allows us to reduce C by taking the product C modulus p (C % p).

	This will reduce the product to a value from 0 ... p - 1 which doesn't overflow.

	The property (a * b) mod p = a mod p * b mod p allows us to apply this. All we must do is check if
	C equals 0.

	Additionally, we know for a fact that if x is precisely max(a_i, a_i+1, ..., a_n) and x is good, then
	all the values i >= x will also be good. 
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

int n, p;

int solve(vector<int> a, int x){
	int permutations = 1, prev = 0, cur;
	for(int i = 0; i < n; i++){
		if(i > 0){
			cur--;
			cur += ub(a, x) - prev;
			prev = ub(a, x);
		} else {
			cur = ub(a, x);
			prev = cur;
		}
		permutations *= cur;
		permutations %= p;
		x++;
	}
	return permutations > 0;
}

int main(){
	FASTIO;
	cin >> n >> p;
	vector<int> a(n);
	int maxA = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		maxA = max(a[i], maxA);
	}
	sort(a.begin(), a.end());
	vector<int> good;
	for(int x = 1; x < maxA; x++){
		if(solve(a, x)){
			good.push_back(x);
		}
	}
	if(solve(a, maxA)){
		for(int i = maxA; i <= 2000; i++){
			good.push_back(i);
		}
	}
	cout << good.size() << endl;
	for(int i: good){
		cout << i << " ";
	}
	cout << endl;
}