#include <bits/stdc++.h>

using namespace std;

void solve(int tc){
    int n; cin >> n;
    string s; cin >> s;
    int same = 0, diff = 1;
    for(int i = 1; i < n; i++){
        if(s[i-1] != s[i]) diff++;
        else same++;
        same = min(same, diff);
    }
    same += (diff - same + 1) / 2;
    cout << same << endl;
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}