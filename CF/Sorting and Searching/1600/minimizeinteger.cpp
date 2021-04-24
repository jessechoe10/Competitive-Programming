#include <bits/stdc++.h>

using namespace std;

#define dbg(x) for(auto& a: x) cout << a << " "
#define print(x) cout << x << endl

void solve(int t){
    string s; cin >> s;
    string even, odd;
    for(char c: s){
        if((c - '0')%2 == 0){
            even += c;
        } else {
            odd += c;
        }
    }
    merge(even.begin(), even.end(), odd.begin(), odd.end(), s.begin());
    cout << s << endl;
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}