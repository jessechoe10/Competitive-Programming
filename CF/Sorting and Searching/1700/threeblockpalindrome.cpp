#include <bits/stdc++.h>

using namespace std;

void solve(int tc){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i]; --a[i];
    }
    vector<vector<int>> dp(26, vector<int>(n+1));
    for(int i=0; i<n; i++){
        for(int j=0; j<26; j++){
            dp[j][i+1] = dp[j][i];
        }
        dp[a[i]][i+1]++;
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int x = 0, y = 0;
            for(int k=0; k<26; k++){
                y = max(y, dp[k][j+1] - dp[k][i]);
                x = max(x, min(dp[k][i], dp[k][n] - dp[k][j+1]));
            }
            ans = max(2 * x + y, ans);
        }
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}