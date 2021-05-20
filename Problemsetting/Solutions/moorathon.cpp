#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Cow {
    int t, d, w;
};

int n, m;
vector<Cow> arr;

bool works(ll time){
    ll res = 0;
    for(int i=0; i<n; i++){
        ll intervals = (arr[i].t * arr[i].d + arr[i].w);
        ll totIntervals = (time / intervals);
        ll rem = (time % intervals);
        if(rem >= arr[i].t * arr[i].d){
            rem = arr[i].t * arr[i].d;
        }
        ll balloons = (totIntervals * arr[i].d) + (rem / arr[i].t);
        res += balloons;
    }
    // Check if the total distance traveled by all cows is at least M
    return res >= m;
}

void balloons(ll time){
    ll cur = m;
    for(int i=0; i<n; i++){
        ll intervals = (arr[i].t * arr[i].d + arr[i].w);
        ll totIntervals = (time / intervals);
        ll rem = (time % intervals);
        if(rem >= arr[i].t * arr[i].d){
            rem = arr[i].t * arr[i].d;
        }
        ll totDistance = (totIntervals * arr[i].d) + (rem / arr[i].t);
        if(totDistance >= cur){
            totDistance = cur; 
        }
        // Subtract the total distance covered from the current running total.
        cur -= totDistance;
        // Print the distance
        cout << totDistance << " ";
    }
    cout << endl;
}

int main(){
    cin >> m >> n;
    for(int i=0; i<n; i++){
        int t, d, w; cin >> t >> d >> w;
        arr.push_back({t, d, w});
    }
    ll l = 0, r, ans;
    r = 1;
    while(!works(r)){
        r *= 2;
    }
    ans = r;
    while(l <= r){
        ll mid = l + (r-l) / 2;
        if(works(mid)){
            ans = mid;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    cout << ans << endl;
    balloons(ans);
}
