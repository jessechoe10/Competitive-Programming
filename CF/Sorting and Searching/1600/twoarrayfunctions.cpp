#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i] = (a[i] * (i+1) * (n-i));
    }
    vector<ll> b(n);
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end());
    ll ans = 0;
    for(int i=0; i<n; i++){
        ans = ((ans + (a[i]%MOD) * b[i]) % MOD) % MOD;
    }
    cout << ans << endl;
}
