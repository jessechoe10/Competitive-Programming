// Problem Link: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
// Video Solution: https://codeforces.com/edu/course/2/lesson/4/1

/*
	YoRepi7's Solution:

	I have none. The official solution linked (above) should explain the logic/implementation well.
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct element {
	int m, c; // m represents the minimum and c represents the frequency
};

struct segmin {
	int size; // Number of nodes in the tree
	vector<element> vals; // Stores the minimums along with its frequency

	void init(int n){
		size = 1;
		// Uses the binary heap implementation of a binary tree
		while(size < n) size *= 2;
		vals.resize(2 * size);
	}

	// Return the minimum of the two nodes with the corresponding frequency as well

	element merge(element a, element b){
		// Go with the minimum of the two and store the corresponding frequency
		if(a.m < b.m){
			return {a.m, a.c};
		} else if(b.m < a.m){
			return {b.m, b.c};
		} else {
			return {a.m, a.c + b.c}; // The special case when the minimum of the left equals the minimum of right node.
		}
	}

	void build(vector<int> &a, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				vals[x] = {a[lx], 1}; // Set the frequency to each element to initially 1
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m); // DFS on the left node
		build(a, 2 * x + 2, m, rx); // DFS on the right node
		vals[x] = merge(vals[2 * x + 1], vals[2 * x + 2]); // Update the minimum element
	}

	void build(vector<int> &a){
		build(a, 0, 0, size);
	}

	void update(int i, int v, int x, int lx, int rx){
		if(rx - lx == 1){
			vals[x] = {v, 1}; // Set the frequency to each element to initially 1
			return;
		}
		int m = (lx + rx) / 2;
		if(i < m){
			update(i, v, 2 * x + 1, lx, m); // Recurse on the left node
		} else {
			update(i, v, 2 * x + 2, m, rx); // Recurse on the right node
		}
		vals[x] = merge(vals[2 * x + 1], vals[2 * x + 2]);
	}

	void update(int i, int v){
		update(i, v, 0, 0, size);
	}

	element minimum(int l, int r, int x, int lx, int rx){
		if(lx >= r || l >= rx) return {(int)1e9, 0};
		if(lx >= l && rx <= r) return vals[x];
		int m = (lx + rx) / 2;
		element leftMin = minimum(l, r, 2 * x + 1, lx, m);
		element rightMin = minimum(l, r, 2 * x + 2, m, rx);
		return merge(leftMin, rightMin); // Update the minimum and frequency of the left and right nodes
	}

	element minimum(int l, int r){
		return minimum(l, r, 0, 0, size);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	segmin st;
	st.init(n);
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	st.build(a);
	for(int i = 0; i < m; i++){
		int query; cin >> query;
		if(query == 1){
			int i, v; cin >> i >> v;
			st.update(i, v);
		} else {
			int l, r; cin >> l >> r;
			element cur = st.minimum(l, r);
			cout << cur.m << " " << cur.c << endl;
		}
	}
}