#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define dbg(x) for(auto& a: x) cout << a << " "
#define print(x) cout << x << endl

set<ll> s;

ll a[100000], dp[100001];

void addSums(int l, int r){
    int mid = upper_bound(a+l, a+r+1, (a[l] + a[r]) / 2) - a;
    s.insert(dp[r+1] - dp[l]);
    if(mid - 1 == r){
        return;
    }
    addSums(l, mid-1);
    addSums(mid, r);
}

void solve(int t){
    int n, q; cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i=0; i<n; i++){
        dp[i+1] = dp[i] + a[i];
    }
    addSums(0, n-1);
    for(int i=0; i<q; i++){
        int s_i; cin >> s_i;
        if(s.count(s_i)){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    s.clear();
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}