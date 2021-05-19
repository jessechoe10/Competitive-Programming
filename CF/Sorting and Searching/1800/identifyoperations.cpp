// Problem Link: https://codeforces.com/problemset/problem/1442/B
// Official Editorial: https://codeforces.com/blog/entry/84298

/*
	YoRepi7's analysis:
	
	After careful observation, we can consider the combinations of the outputs as a binary tree.
	Since each number in array b was either appended from the right / left of the current element,
	there is at most two possibilites which for a given index i. Occasionally, it's impossible to
	output the given array b when both elements adjacent to the current element have been appended
	to array a.

	Sometimes, thre is exactly one possibility for a given index i, which is when either the left
	or right element has been appended (but not both).

	We can check whether each element has been appended by storing whether a given element in b
	has been appended or not (say, using a boolean array).

	We can keep track of the number of possible sequences by multiplying the number of possibilites
	at a given index i to a running total.

	The time complexity of this algorithm is linear (O(n) time).
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

void solve(int t){
	int n, k; cin >> n >> k;
	vector<int> pos(n), vis(n);
	vector<int> a(n), b(k);
	for(int i = 0; i < n; i++){
		cin >> a[i]; a[i]--;
		pos[a[i]] = i;
	}
	for(int i = 0; i < k; i++){
		cin >> b[i]; b[i]--;
		vis[b[i]] = true;
	}
	ll ans = 1;
	for(int i = 0; i < k; i++){
		vis[b[i]] = 0;
		ll cur = 0;
		if((pos[b[i]] - 1 >= 0) && (!vis[a[pos[b[i]] - 1]])){
			cur++;
		}
		if((pos[b[i]] + 1 < n) && (!vis[a[pos[b[i]] + 1]])){
			cur++;
		}
		ans = ans * cur % MOD;
	}
	cout << ans << endl;
}

int main(){
	int t; cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);
	}
}