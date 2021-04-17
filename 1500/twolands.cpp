#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    ll arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        arr[i] = abs(arr[i]);
    }
    ll ans = 0;
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        ans += (upper_bound(arr, arr+n, 2*arr[i]) - arr - 1 - i);
    }
    cout << ans << endl;
}