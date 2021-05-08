#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll h, c, t;

bool works(int cupsPoured){
    ld t_b = (ld)(h * (cupsPoured + 1) + c * (cupsPoured)) / (ld)(2 * cupsPoured + 1);
    return t_b >= (ld) t;
}

void solve(int tc){
    cin >> h >> c >> t;
    ll l = 0, r = 1e6 + 1, ans = 0;
    while(l <= r){
        ll m = l + (r-l) / 2;
        if(works(m)){
            ans = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    if(ans == 1e6 + 1){
        cout << 2 << endl;
    } else {
        ld tb1 = (ld)(h * (ans + 1) + c * (ans)) / (ld)(2 * ans + 1);
        ld tb2 = (ld)(h * (ans + 2) + c * (ans + 1)) / (ld)(2 * ans + 3);
        ld even = (ld)(h + c) / 2.0;
        ld absDiff = min(abs(t - tb1), min(abs(t - tb2), abs(t - even)));

        if(absDiff == abs(t - even)){
            cout << 2 << endl;
        } else if(absDiff == abs(t - tb1)){
            cout << 2 * ans + 1 << endl;
        } else {
            cout << 2 * ans + 3 << endl;
        }
    }
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}