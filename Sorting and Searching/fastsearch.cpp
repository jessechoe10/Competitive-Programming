#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

int main(){
    int n; cin >> n;
    vl arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int k; cin >> k;
    for(int i=0; i<k; i++){
        ll l, r; cin >> l >> r;
        cout << upper_bound(arr.begin(), arr.end(), r) - lower_bound(arr.begin(), arr.end(), l) << " ";
    }
    cout << endl;
}