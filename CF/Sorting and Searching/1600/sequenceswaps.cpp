#include <bits/stdc++.h>

using namespace std;

bool isSorted(vector<int> arr){
    for(int i=0; i<arr.size()-1; i++){
        if(arr[i] > arr[i+1]) return false;
    }
    return true;
}

bool isSortable(vector<int> arr, int cur, int curPos){
    for(int i=curPos; i<arr.size(); i++){
        if(arr[i] < cur) return false;
    }
    return true;
}

void solve(int t){
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    if(isSorted(arr)){
        cout << 0 << endl;
        return;
    }
    int pos = n;
    for(int i=0; i<n; i++){
        if(arr[i] > x){
            pos = i;
            break;
        }
    }
    if(pos == n || !isSortable(arr, x, pos)){
        cout << -1 << endl;
        return;
    }
    int cur = x, curPos = 0, res = 0;
    while(!isSorted(arr) && curPos < n){
        if(arr[curPos] > cur){
            if(!isSortable(arr, cur, curPos)){
                cout << -1 << endl;
                return;
            }
            swap(cur, arr[curPos]);
            ++res;
        }
        ++curPos;
    }
    if(!isSorted(arr)){
        cout << -1 << endl;
        return;
    }
    cout << res << endl;
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}