#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n; cin >> n;
    int ret = 0;
    for(ll i=3; i*i <= 2*n-1; i+=2){
        ++ret;
    }
    cout << ret << endl;
}

int main(){
    int t; cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }
}