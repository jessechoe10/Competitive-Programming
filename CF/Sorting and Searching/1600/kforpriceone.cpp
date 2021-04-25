#include <bits/stdc++.h>

using namespace std;

void solve(int tc){
    int n, p, k; cin >> n >> p >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> dp(n+1);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i] = dp[i-1] + a[i-1];
    }
    int m = 0;
    for(int i=0; i<k; i++){
        int cur = i, sum = dp[i];
        if(sum > p) break;
        for(int j=(i + k - 1); j<n; j+=k){
            if(a[j] + sum <= p){
                cur += k;
                sum += a[j];
            } else {
                break;
            }
        }
        m = max(cur, m);
    }
    cout << m << endl;
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}