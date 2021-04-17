#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, x, y;

bool works(ll time){
    return (time / x) + ((time - x) / y) >= n;
}

int main(){
    cin >> n >> x >> y;
    if(x > y) swap(x, y);
    ll l = 1, r = n * max(x, y), ans = r;
    while(l <= r){
        ll m = l + (r-l) / 2;
        if(works(m)){
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    cout << ans << endl;
}