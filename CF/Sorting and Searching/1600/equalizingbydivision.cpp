#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n, k; cin >> n >> k;
    vector<int> adj[200001];
    for(int i=0; i<n; i++){
        int a; cin >> a;
        int cur = 0;
        while(a > 0){
            adj[a].push_back(cur);
            a /= 2;
            ++cur;
        }
    }
    ll ans = INT_MAX;
    for(int i=0; i<200001; i++){
        if(adj[i].size() < k){
            continue;
        }
        sort(adj[i].begin(), adj[i].end());
        ll cur = 0;
        for(int j=0; j<k; j++){
            cur += adj[i][j];
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
}