#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool works(vector<ll> arr, ll k, ld length){
    ll totPieces = 0;
    for(int i: arr){
        totPieces += i / length;
    }
    return totPieces >= k;
}

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    ld epsilon = 1e-8, l = 1e-6, r = 1e15, ans = 0;
    while(l + epsilon < r){
        ld m = (l + r) / 2;
        if(works(arr, k, m)){
            l = m;
            ans = m;
        } else {
            r = m;
        }
    }
    cout << ans << endl;
}