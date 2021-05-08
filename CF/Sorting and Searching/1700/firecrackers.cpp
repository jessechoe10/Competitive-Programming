#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

ll n, m, a, b, topFirecrackers, totalTime;

bool works(vl s, ll firecrackers){
    int curTime = 1;
    for(int i = firecrackers - 1; i >= 0; i--){
        if(curTime + s[i] > totalTime){
            return false;
        } else {
            ++curTime;
        }
    }
    return true;
}

void solve(int tc){
    cin >> n >> m >> a >> b;
    vl s(m);
    for(int i = 0; i < m; i++){
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    topFirecrackers = min(m, abs(a - b) - 1);
    if(a < b){
        totalTime = b - 1;
    } else if(a > b){
        totalTime = n - b;
    } else {
        return;
    }
    ll l = 0, r = topFirecrackers, ans = 0;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(works(s, mid)){
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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