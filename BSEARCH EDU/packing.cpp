#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool works(ll w, ll h, ll n, ll side){
    return (side / w) * (side / h) >= n;
}

int main(){
    ll w, h, n; cin >> w >> h >> n;
    ll l = 0, r = 1;
    while(!works(w, h, n, r)){
        r*=2;
    }
    ll ans = r;
    while(l <= r){
        ll m = (l+r) / 2;
        if(works(w, h, n, m)){
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    cout << ans << endl;
}