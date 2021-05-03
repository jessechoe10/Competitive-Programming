#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

const ll MOD = 1e9+7;
const ll MAX_N = 2e5 + 1;

ll C[MAX_N][101];

void findChooses(){
    for(int i=0; i<=MAX_N-1; i++){
        for(int j=0; j<=min(i, 100); j++){
            if(j == 0 || j == i){
                C[i][j] = 1;
            } else {
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }
    }
}

ll choose(int n, int r){
    return C[n][r] % MOD;
}

void solve(int tc){
    int n, m, k; cin >> n >> m >> k;
    vl a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i=0; i<n; i++){
        int tuples = upper_bound(a.begin(), a.end(), a[i] + k) - a.begin() - i;
        if(tuples >= m){
            ans += choose(tuples-1, m-1) % MOD;
        }
    }
    cout << ans % MOD << endl;
}

int main(){
    findChooses();
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}