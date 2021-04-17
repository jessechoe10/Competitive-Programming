#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m), res(m);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    int i = 0, j = 0;
    while(j < m){
        if(a[i] >= b[j] || (i == n)){
            j++;
            cout << i << " ";
        } else {
            i++;
        }
    }
    cout << endl;
}