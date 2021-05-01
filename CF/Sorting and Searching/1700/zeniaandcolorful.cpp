#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define sz(x) (x).size()
#define lb(a, x) lower_bound(begin(a), end(a), x)
#define ub(a, x) upper_bound(begin(a), end(a), x)

// We need to find three triplets whose sum(x, y, z) is minimal. x, y, z must be part of a, b, c

ll sum(ll x, ll y, ll z){
    return pow(abs(x-y), 2) + pow(abs(y-z), 2) + pow(abs(x-z), 2);
}

ll search(vl a, vl b, vl c){
    ll ans = 3e18;
    for(int i=0; i<sz(a); i++){
        // Find the closest values of y and z to x and compute the minimum sum(x, y, z) for a fixed x
        ll x = a[i];
        auto y = lb(b, x), z = ub(c, x);
        if(y == b.end() || z == c.begin()) continue;
        --z;
        ans = min(ans, sum(x, *y, *z));
    }
    return ans;
}

ll min(ll a, ll b, ll c, ll d, ll e, ll f){
    return min(a, min(b, min(c, min(d, min(e, f)))));
}

void solve(int tc){
    int nr, ng, nb; cin >> nr >> ng >> nb;
    vl red(nr), green(ng), blue(nb);
    for(int i = 0; i < nr; i++){
        cin >> red[i];
    }
    for(int i = 0; i < ng; i++){
        cin >> green[i];
    }
    for(int i = 0; i < nb; i++){
        cin >> blue[i];
    }
    sort(red.begin(), red.end());
    sort(green.begin(), green.end());
    sort(blue.begin(), blue.end());
    
    ll a = search(red, green, blue), b = search(red, blue, green), c = search(blue, red, green), d = search(blue, green, red), e = search(green, red, blue), f = search(green, blue, red);
    cout << min(a, b, c, d, e, f) << endl;
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}