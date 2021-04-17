#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

ll arr[100000];
int n, k;

bool binarySearch(ll number){
    int l = 0, r = n-1;
    while(l <= r){
        int mid = l + (r-l) / 2;
        if(arr[mid] == number){
            return true;
        } else if(arr[mid] < number){
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return false;
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<k; i++){
        ll q; cin >> q; 
        if(binarySearch(q)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}