// Problem Link: https://codeforces.com/problemset/problem/1375/D
// Official Editorial: https://codeforces.com/blog/entry/79731

/*
	YoRepi7's analysis:

	Due to the relatively small n, we can apply a quadratic time solution
	for this problem.

	After careful observation, we can realize that the MEX of an array must 
	always be between 0...n.

	To ease the process of finding the MEX of an array, we should attempt to
	make the non-decreasing array as 0, 1, 2, ... , n-1, n.

	It can be proven that the following algorithm will require no more than
	2n operations:

	1. If the MEX of a is n, then find the lowest unsorted element and replace
	it with the index containing that given position while setting the element
	at that given index to be n. 
	
	For instance, the sample input: 2 0 1 
	
	We would choose position 1 since that isn't in its sorted position.
	Then, we find the position where 0 is located (position 2) and set a_2 equal
	to n. We set position 1 to 0.

	2. If the MEX of a is less than n, then we can replace a_MEX with MEX and continue.

	We can then print out the positions which were changed for each iteration of the algorithm.

	This algorithm will repeat until all elements are considered sorted (0, 1, ... , n - 1, n).

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

bool isIncreasing(vector<int> a){
	if(a[0] != 0) return false;
	for(int i = 1; i < a.size(); i++){
		if(a[i] <= a[i - 1] || a[i] != i){
			return false;
		}
	}
	return true;
}

int findMEX(vector<int> a){
	vector<bool> vis(a.size());
	for(int i: a){
		vis[i] = true;
	}
	for(int i = 0; i < a.size(); i++){
		if(!vis[i]) return i;
	}
	return a.size();
}

int findFirstIndex(vector<int> a){
	for(int i = 0; i < a.size(); i++){
		if(a[i] != i){
			return i;
		}
	}
	return -1;
}

int findIndex(vector<int> a, int idx){
	for(int i = 0; i < a.size(); i++){
		if(a[i] == idx){
			return i;
		}
	}
	return -1;
}

void solve(int t){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> ops;
	while(!isIncreasing(a)){
		int mex = findMEX(a);
		if(mex == n){
			int i = findFirstIndex(a);
			int j = findIndex(a, i);
			ops.push_back(j + 1);
			ops.push_back(i + 1);
			a[j] = n;
			a[i] = i;
		} else {
			a[mex] = mex;
			ops.push_back(mex + 1);
		}
	}
	cout << ops.size() << endl;
	for(int i: ops){
		cout << i << " ";
	}
	cout << endl;
}

int main(){
	FASTIO;
	int t; cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);
	}
}