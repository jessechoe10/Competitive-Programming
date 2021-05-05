#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

void solve(int tc){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i <n ; i++){
        cin >> a[i];
    }
    vector<int> dp(2*k+1); dp[0] = n;
    for(int i = 0; i < n/2; i++){
        int x = min(a[i], a[n-1-i]), y = max(a[i], a[n-1-i]);
        dp[x+1]--;
        dp[y+k+1]++;
        dp[x+y]--;
        dp[x+y+1]++;
    }
    int ans = n;
    for(int i = 0; i <= 2*k; i++){
        dp[i+1] += dp[i];
        ans = min(ans, dp[i+1]);
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}