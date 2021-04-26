#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;

int main(){
    int n; cin >> n;
    vl a(n);
    vector<pl> lastReceipt(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        lastReceipt[i] = {0, a[i]};
    }
    int q; cin >> q;
    vl stimulus(q+1, 0);
    for(int i=1; i<=q; i++){
        int query; cin >> query;
        int p, x;
        if(query == 1){
            cin >> p >> x;
            --p; lastReceipt[p] = {i, x};
        } else {
            cin >> x;
            stimulus[i] = x;
        }
    }
    vl maxStimulus(q+1);
    maxStimulus[q] = stimulus[q];
    for(int i=q-1; i>=0; i--){
        maxStimulus[i] = max(maxStimulus[i+1], stimulus[i]);
    }
    vl balances(n);
    for(int i=0; i<n; i++){
        balances[i] = max(lastReceipt[i].second, maxStimulus[lastReceipt[i].first]);
        cout << balances[i] << " ";
    }
    cout << endl;
}