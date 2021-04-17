#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll n, k;
int a[10000];

bool works(double length){
    ll pieces = 0;
    for(int i=0; i<n; i++){
        pieces += (a[i] / length);
    }
    return pieces >= k;
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    double err = 1e-6, l = 1e-6, r = 1e11, ans = 1e-6;
    while(l + err < r){
        double m = (l + r) / 2;
        if(works(m)){
            l = m;
            ans = m;
        } else {
            r = m;
        }
    }
    cout << setprecision(6) << fixed << ans << endl;
}