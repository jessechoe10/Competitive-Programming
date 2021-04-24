#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define dbg(x) for(auto& a: x) cout << a << " "
#define print(x) cout << x << endl

int n; vl p;
ll x, a, y, b, k;

bool works(int sellTickets){
    vl pct(sellTickets);
    for(int i=a-1; i<sellTickets; i+=a){
        pct[i] += x;
    }
    for(int i=b-1; i<sellTickets; i+=b){
        pct[i] += y;
    }
    sort(pct.begin(), pct.end(), greater<ll>());
    ll cur = 0;
    for(int i=0; i<sellTickets; i++){
        cur += pct[i]*p[i]/100;
    }
    return cur >= k;
}

void solve(int t){
    cin >> n;
    p.resize(n);
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    sort(p.begin(), p.end(), greater<ll>());
    cin >> x >> a >> y >> b >> k;
    int l = 0, r = n, ans = -1;
    while(l <= r){
        int mid = l + (r-l) / 2;
        if(works(mid)){
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << ans << endl;
}

int main(){
    int q; cin >> q;
    for(int i=1; i<=q; i++){
        solve(i);
    }
}