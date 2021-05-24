#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segtree {
    int size; // Number of nodes in the tree
    vector<ll> sums; // Stores the segment sums
    void init(int n){
        size = 1;
        // Uses the binary heap implementation of a binary tree
        while(size < n) size *= 2;
        sums.assign(2 * size, 0LL);
    }
    void dfs(vector<int> a, int root, int l, int r){
        // When we finally arrive at the element itself
        if(r - l == 1){
            // We need to make sure that the element is within the bound of the array
            if(l < (int)a.size()){
                sums[root] = a[l];
            }
            return;
        }
        // The left segment is from [l, m] and the right segment is from [m, r]
        int m = (l + r) / 2;
        // DFS on the left and right half of the tree
        dfs(a, 2 * root + 1, l, m);
        dfs(a, 2 * root + 2, m, r);
        // The sum of each upper node is the sum of the two previous lower nodes
        sums[root] = sums[2 * root + 1] + sums[2 * root + 2];
    }
    void dfs(vector<int> a){
        dfs(a, 0, 0, size);
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
    segtree st;
    st.init(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    st.dfs(a);
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