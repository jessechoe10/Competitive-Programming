#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n, m; cin >> n >> m;
    vector<int> b(n), g(m);
    ll res = 0;
    for(int i=0; i<n; i++){
        cin >> b[i];
        res += b[i];
    }
    for(int i=0; i<m; i++){
        cin >> g[i];
    }
    sort(b.begin(), b.end(), [](int a, int b){
       return a > b; 
    });
    sort(g.begin(), g.end(), [](int a, int b){
       return a > b; 
    });
    res *= m;
    int p1 = 0, p2 = 0, cur = 0;
    int maxB = b[0], minG = g[0];
    for(int i=1; i<n; i++){
        maxB = max(maxB, b[i]);
    }
    for(int i=1; i<m; i++){
        minG = min(minG, g[i]);
    }
    if(maxB > minG){
        cout << -1 << endl;
        return 0;
    }
    while(p2 < m){
        ++cur;
        res += (g[p2] - b[p1]);
        if((cur == m-1 && g[p2+1] != b[p1]) || cur == m){
            cur = 0;
            p1++;
        }
        p2++;
    }
    cout << res << endl;
}