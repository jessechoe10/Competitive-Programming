// Problem Link: https://codeforces.com/problemset/problem/1342/D
// Official Editorial: https://codeforces.com/blog/entry/76633

/*
	YoRepi7's analysis:

	Given the constraints on n, we must find a linear time solution.

	After carefully observing the sample test cases, it can be observed
	that the array sizes that require the most amount of test cases are
	the ones that require the most test cases independently (without)
	considering the other constraints.

	For instance, in the first sample test case:
	
	1 2 2 3
	4 1 1

	In this case, the number of test cases for the first constraint to
	be satisfied is '1', and the number of test cases for the second
	constraint to be satisfied is '3'. The number of test cases for the
	third constraint to be satisfied is '1'.

	The reasoning behind this is that for the first constraint the number
	of arrays greater than or equal to 1 is 4. Since the maximum number of 
	arrays per test case greater than or equal to 1 is at most 4, 
	the minimum number of test cases required to satisfy that constraint for all 
	possible arrays is 1. Similarly, for the second constraint, the number 
	of arrays greater than or equal to 2 is 3. Since the number of arrays per
	test case greater than or equal to 2 is at most 1, the minimum number of
	test cases required to satisfy that constraint for all possible arrays is
	precisely 3. The number of arrays greater than or equal to 3 are 1 and there must
	be no more than 1 array per test case following this constraint; the minimum
	number of test cases satisfying the final constraint is 1.

	However, when the number of arrays is not divisible by the maximum number of
	arrays per test case for a given 'i', we output the ceil(number of arrays / c_i).

	The answer is the maximum of the minimum number of test cases satisfying each 
	constraint.

	To compute the number of arrays greater than or equal to a given 'i', we can sort
	the array m and apply binary search to compute this in O(log n) time for each i.

	Additionally, the problem asks us to print out the arrays that go into each
	test case. Given that we found 'ans', we can print out ans arrays where each
	given i is in the i % ans array. This can be proven to satisfy each constraint
	for each given test case.

	The runtime of this algorithm is O(n log n) which passes the time constraints of the 
	problem.
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

int ceil(int a, int b){
	if(a % b == 0){
		return (a / b);
	} else {
		return (a / b) + 1;
	}
}

int main(){
	int n, k; cin >> n >> k;
	vector<int> m(n);
	for(int i = 0; i < n; i++){
		cin >> m[i];
	}
	sort(m.begin(), m.end());
	vector<int> c(k);
	for(int i = 0; i < k; i++){
		cin >> c[i];
	}
	int ans = 1;
	for(int i = 1; i <= k; i++){
		int g = lb(m, i);
		g = n - g;
		ans = max(ans, ceil(g, c[i-1]));
	}
	cout << ans << endl;
	vector<vector<int>> tc(ans);
	for(int i = 0; i < n; i++){
		tc[i % ans].push_back(m[i]);
	}
	for(int i = 0; i < ans; i++){
		cout << tc[i].size() << " ";
		for(int j: tc[i]){
			cout << j << " ";
		}
		cout << endl;
	}
}