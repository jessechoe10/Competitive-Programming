#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define dbg(x) for(auto& a: x) cout << a << " "
#define print(x) cout << x << endl

void solve(int tc){
    int n; cin >> n;
    vector<ll> b(2*n);
    for(int i=0; i<2*n; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end(), greater<ll>());
    vector<ll> d(n), a(n);
    for(int i=0; i<n; i++){
        // Check if b is symmetric
        if(b[i*2] != b[i*2+1]){
            cout << "NO" << endl;
            return;
        }
        d[i] = b[i*2];
    }
    for(int i=1; i<n; i++){
        // Check if each element is unique and divisible by 2 * (n-i) since it's sorted in descending. Otherwise it'd be 2 * (i+1)
        if(d[i-1] == d[i] || (d[i-1] - d[i]) % (2 * (n-i))){
            cout << "NO" << endl;
            return;
        }
        a[i] = (d[i-1] - d[i]) / (2 * (n-i));
    }
    for(int i=1; i<n; i++){
        d[n-1] -= 2 * i * a[i];
    }
    // Check if the a0 can generate d0
    if(d[n-1] <= 0 || d[n-1] % (2 * n)){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}