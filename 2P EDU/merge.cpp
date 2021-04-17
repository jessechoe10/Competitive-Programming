#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m), c;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    int l = 0, j = 0;
    while(l < n || j < m){
        if((j == m && l < n) || (a[l] < b[j])){
            c.push_back(a[l]);
            ++l;
        } else {
            c.push_back(b[j]);
            ++j;
        }
    }
    for(ll i: c){
        cout << i << " ";
    }
}