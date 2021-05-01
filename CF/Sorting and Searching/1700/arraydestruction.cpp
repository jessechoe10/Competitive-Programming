#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

#define dbg(x) for(auto& a: x) cout << a << " "
#define print(x) cout << x << endl

int n;
int a[2000];

vector<pi> removals;

bool works(int x){
    removals.clear();
    multiset<int> ms;
    for(int i=0; i<n; i++){
        ms.insert(a[i]);
    }
    while(ms.size()){
        int cur = *ms.rbegin();
        ms.erase(ms.find(cur));
        if(ms.find(x-cur) == ms.end()){
            return false;
        }
        ms.erase(ms.find(x-cur));
        removals.push_back({cur, x-cur});
        x = cur;
    }
    return ms.empty();
}

void solve(int tc){
    cin >> n; n*=2;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i=0; i<n-1; i++){
        int x = a[i] + a[n-1];
        if(works(x)){
            print("YES");
            print(x);
            for(pi j: removals){
                cout << j.first << " " << j.second << endl;
            }
            return;
        }
    }
    print("NO");
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}