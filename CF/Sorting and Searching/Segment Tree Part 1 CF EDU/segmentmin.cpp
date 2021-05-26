#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segmin {
    int size; // Number of nodes in the tree
    vector<ll> mins; // Stores the segment sums
    void init(int n){
        size = 1;
        // Uses the binary heap implementation of a binary tree
        while(size < n) size *= 2;
        mins.assign(2 * size, 0LL);
    }
    void update(int i, int v, int root, int l, int r){
        if(r - l == 1){
            mins[root] = v; // Update the element at i with v
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
        // Update the minimum
        mins[root] = min(mins[2 * root + 1], mins[2 * root + 2]);
    }
    void update(int i, int v){
        update(i, v, 0, 0, size);
    }
    ll minimum(int l, int r, int root, int curL, int curR){
        // Check if the current minimum is out of the range of the current segment
        if(curL >= r || l >= curR){
            return 1e9;
        }
        if(curL >= l && curR <= r){
            return mins[root];
        }
        int m = (curL + curR) / 2;
        // Return the minimum of the left and right segments
        ll left = minimum(l, r, 2 * root + 1, curL, m);
        ll right = minimum(l, r, 2 * root + 2, m, curR);
        return min(left, right);
    }
    ll minimum(int l, int r){
        return minimum(l, r, 0, 0, size);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    segmin st;
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
            cout << st.minimum(l, r) << endl;
        }
    }
    return 0;
}