#include <bits/stdc++.h>

using namespace std;

#define dbg(x) for(auto& a: x) cout << a << " "
#define print(x) cout << x << endl
#define sor(x) sort(begin(x), end(x))

void solve(int tc){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    sor(s);
    if(s[0] != s[k-1]){
        print(s[k-1]);
    } else {
        cout << s[0];
        if(s[k] != s[n-1]){
            for(int i=k; i<n; i++){
                cout << s[i];
            }
            print("");
        } else {
            for(int i=0; i<(n-1)/k; i++){
                cout << s[n-1];
            }
            print("");
        }
    }
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}