#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> s(n), t(m);
    for(int i=0; i<n; i++){
        char c; cin >> c;
        s[i] = c - 'a';
    }
    for(int i=0; i<m; i++){
        char c; cin >> c;
        t[i] = c - 'a';
    }
    vector<int> left(m), right(m);
    int p1 = 0, p2 = 0;
    while(p2 < m){
        if(s[p1] == t[p2]){
            left[p2] = p1;
            p2++;
            p1++;
        } else {
            p1++;
        }
    }
    p1 = n-1, p2 = m-1;
    while(p2 >= 0){
        if(s[p1] == t[p2]){
            right[p2] = p1;
            p2--;
            p1--;
        } else {
            p1--;
        }
    }
    int ans = 1;
    for(int i=0; i<m-1; i++){
        ans = max(right[i+1] - left[i], ans);
    }
    cout << ans << endl;
}