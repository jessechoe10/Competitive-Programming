#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    vector<ll> a(2*n+1, 0);
    for(int i=1; i<=2*n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ret = (a[2*n] - a[n+1]) * (a[n] - a[1]);
    for(int i=2; i<=n; i++){
        ret = min((a[i + n - 1] - a[i]) * (a[2*n] - a[1]), ret);
    }
    cout << ret << endl;
}