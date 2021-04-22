#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

struct cmp {
    bool operator()(const pi &a, const pi &b){
        int seg1 = a.second - a.first + 1;
        int seg2 = b.second - b.first + 1;
        if(seg1 == seg2){
            return a.first > b.first;
        }
        return seg1 < seg2;
    }
};

void solve(int t){
    int n; cin >> n;
    vector<int> arr(n);
    int cur = 0;
    set<pi, cmp> segment;
    segment.insert({0, n-1});
    while(cur < n){
        pi a = *segment.rbegin();
        int l = a.first, r = a.second;
        segment.erase(a);
        if((r - l + 1) % 2 == 1){
            arr[(l + r) / 2] = cur + 1;
            segment.insert({l, (l + r) / 2 - 1});
            segment.insert({(l + r) / 2 + 1, r});
        } else {
            arr[(l + r - 1) / 2] = cur + 1;
            segment.insert({l, ((l + r - 1) / 2) - 1});
            segment.insert({((l + r - 1) / 2 + 1), r});
        }
        ++cur;
    }
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}