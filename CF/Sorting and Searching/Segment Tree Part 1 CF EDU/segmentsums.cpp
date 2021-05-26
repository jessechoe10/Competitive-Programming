#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segsum {
    
	int size; // Number of nodes in the tree
	vector<ll> sums; // Stores the segment sums
    
	void init(int n){
		size = 1;
		// Uses the binary heap implementation of a binary tree
		while(size < n) size *= 2;
		sums.assign(2 * size, 0LL);
	}
    
	void update(int i, int v, int root, int l, int r){
		if(r - l == 1){
			sums[root] = v; // Update the element at i with v
			return;
		}
		int m = (l + r) / 2;
		// Check which side i is on
		if(i < m){
			// DFS on the left half of the segment tree
			update(i, v, 2 * root + 1, l, m);
		} else {
			// DFS on the right half of the segment tree
			update(i, v, 2 * root + 2, m, r);
		}
		// Update the sum
		sums[root] = sums[2 * root + 1] + sums[2 * root + 2];
	}
    
	void update(int i, int v){
		update(i, v, 0, 0, size);
	}
    
	ll sum(int l, int r, int root, int curL, int curR){
		// Check if the current sum is out of the range of the current segment
		if(curL >= r || l >= curR){
			return 0;
		}
        // Check if the current sum is completely inside the current segment
		if(curL >= l && curR <= r){
			return sums[root];
		}
		int m = (curL + curR) / 2;
		// Return the sum of the left and right segments
		ll left = sum(l, r, 2 * root + 1, curL, m);
		ll right = sum(l, r, 2 * root + 2, m, curR);
		return left + right;
	}
	ll sum(int l, int r){
		return sum(l, r, 0, 0, size);
	}
    
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	segsum st;
	st.init(n);
	for(int i = 0; i < n; i++){
		int v; cin >> v;
		st.update(i, v);
	}
	for(int i = 0; i < m; i++){
		int query; cin >> query;
		if(query == 1){
			int i, v; cin >> i >> v;
			st.update(i, v);
		} else {
			int l, r; cin >> l >> r;
			cout << st.sum(l, r) << endl;
		}
	}
	return 0;
}
