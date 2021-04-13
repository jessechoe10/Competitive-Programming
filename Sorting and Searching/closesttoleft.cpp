#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
ll arr[100000];

int upperBound(ll number){
    int l = 0, r = n-1, ans = -1;
    while(l <= r){
        int m = l + (r-l) / 2;
        if(arr[m] <= number){
            ans = m;
            l = m+1;
        } else {
            r = m-1;
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
        cout << upperBound(q) << endl;
    }
}