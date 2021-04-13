#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll arr[100000];
int n, k;

int lowerBound(ll number){
    int l = 0, r = n-1, ans = n;
    while(l <= r){
        int m = l + (r-l) / 2;
        if(arr[m] >= number){
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    return ans + 1;
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<k; i++){
        ll q; cin >> q;
        cout << lowerBound(q) << endl;
    }
}
