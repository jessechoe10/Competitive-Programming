#include <bits/stdc++.h>

using namespace std;

void solve(int t){
    int n; cin >> n;
    vector<int> a(n), cnt(n);
    for(int i=0; i<n; i++){
        cin >> a[i]; --a[i];
        cnt[a[i]]++;
    }
    sort(cnt.begin(), cnt.end());
    int max = cnt[n-1], maxCnt = 0;
    for(int i=0; i<n; i++){
        if(cnt[i] == max){
            maxCnt++;
        }
    }
    cout << (n - maxCnt) / (max - 1) - 1 << endl;
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}