#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll j = 0, ans = 0;
    for(int i=0; i<n; i++){
        while(a[j] - a[i] <= 2 && j < n){
            ++j;
        }
        j--;
        if(j-i >= 2) ans += (j-i)*(j-i-1) / 2;
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }
}