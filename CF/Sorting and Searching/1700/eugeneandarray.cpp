#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    vector<ll> dp(n+1, 0);
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        dp[i] = dp[i-1] + a;
    }
    set<ll> s; s.insert(0);
    int l = 0, r = 0;
    ll goodSubarrays = 0;
    while(l < n){
        while(r < n && !s.count(dp[r+1])){
            ++r;
            s.insert(dp[r]);
        }
        goodSubarrays += (r - l);
        s.erase(dp[l]);
        l++;
    }
    cout << goodSubarrays << endl;
}