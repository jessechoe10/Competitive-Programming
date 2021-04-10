#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;

ll removeC(vl freq, ll c){
    ll ans = 0;
    for(ll i: freq){
        if(i < c){
            ans += i;
        } else {
            ans += (i - c);
        }
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    map<ll, ll> mp;
    for(int i=0; i<n; i++){
        ll a; cin >> a;
        mp[a]++;
    }
    vl freq;
    for(pl a: mp){
        freq.push_back(a.second);
    }
    set<ll> s;
    for(ll i: freq){
        s.insert(i);
    }
    ll ans = 1e10;
    for(auto& a: s){
        ans = min(ans, removeC(freq, a));
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }
}
