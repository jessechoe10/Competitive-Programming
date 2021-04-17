#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct assistant {
    int t, y, z;
};

int n, m;
vector<assistant> arr;

bool works(ll time){
    ll res = 0;
    for(int i=0; i<n; i++){
        ll intervals = (arr[i].t * arr[i].y + arr[i].z);
        ll totIntervals = (time / intervals);
        ll rem = (time % intervals);
        if(rem >= arr[i].t * arr[i].y){
            rem = arr[i].t * arr[i].y;
        }
        ll balloons = (totIntervals * arr[i].y) + (rem / arr[i].t);
        res += balloons;
    }
    return res >= m;
}

void balloons(ll time){
    ll cur = m;
    for(int i=0; i<n; i++){
        ll intervals = (arr[i].t * arr[i].y + arr[i].z);
        ll totIntervals = (time / intervals);
        ll rem = (time % intervals);
        if(rem >= arr[i].t * arr[i].y){
            rem = arr[i].t * arr[i].y;
        }
        ll balloons = (totIntervals * arr[i].y) + (rem / arr[i].t);
        if(balloons >= cur){
            balloons = cur; 
        }
        cur -= balloons;
        cout << balloons << " ";
    }
    cout << endl;
}

int main(){
    cin >> m >> n;
    for(int i=0; i<n; i++){
        int t, y, z; cin >> t >> y >> z;
        arr.push_back({t, y, z});
    }
    ll l = 0, r, ans;
    r = 1;
    while(!works(r)){
        r *= 2;
    }
    ans = r;
    while(l <= r){
        ll m = l + (r-l) / 2;
        if(works(m)){
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    cout << ans << endl;
    balloons(ans);
}