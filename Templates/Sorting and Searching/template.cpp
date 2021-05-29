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

struct segtree {
	
	int size; // This represents the number of nodes in
	vector<ll> segtree; // Stores the segment tree
	
	void init(int n){
		// Initialize the segment tree by finding the size and setting each node to a default value (say, 0).
	}
	void update(int i, int v, int root, int l, int r){
		// Update a given element of the tree and do that for all of the nodes connected to that
	}
	void update(int i, int v){
		update(i, v, 0, 0, size);
	}
	ll operation(int l, int r, int root, int curL, int curR){
		// For a given associative operation, find the operation applied to the range [l, r]
	}
	ll operation(int l, int r){
		return operation(l, r, 0, 0, size);
	}
	
};

void solve(int tc){
          
}

int main(){
	FASTIO;
	solve(1);
}
