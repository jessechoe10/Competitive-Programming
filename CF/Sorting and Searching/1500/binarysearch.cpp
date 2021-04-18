#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main(){
    int n, x, pos; cin >> n >> x >> pos;
    int l = 0, r = n;
    ll cur1 = n-x, cur2 = x-1, ans = 1;
    while(l < r){
        int m = (l + r) / 2;
        if(m < pos){
            ans *= cur2;
            ans %= mod;
            --cur2;
            l = m+1;
        } else if(m > pos){
            ans *= cur1;
            ans %= mod;
            --cur1;
            r = m;
        } else {
            l = m+1;
        }
    }
    for(int i=1; i<=(cur1 + cur2); i++){
        ans *= i;
        ans %= mod;
    }
    cout << ans << endl;
}