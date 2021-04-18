#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n, m; cin >> n >> m;
    map<ll, ll> mp;
    for(int i=0; i<n; i++){
        ll a; cin >> a;
        mp[a]++;
    }
    ll ans = 0;
    for(int i=0; i<m; i++){
        ll b; cin >> b;
        ans += mp[b];
    }
    cout << ans << endl;
}