#include <bits/stdc++.h>

using namespace std;

string t, p;
vector<int> arr;

bool canDelete(vector<char> a){
    if(a.size() < p.length()){
        return false;
    }
    int p1 = 0, p2 = 0;
    while(p2 < p.length() && p1 < a.size()){
        if(a[p1] == p[p2]){
            p2++;
        }
        p1++;
    }
    return (p2 >= p.length());
}

bool works(int letters){
    set<int> s;
    for(int i=0; i<letters; i++){
        s.insert(arr[i]);
    }
    vector<char> a;
    for(int i=0; i<t.length(); i++){
        if(!s.count(i)){
            a.push_back(t[i]);
        }
    }
    return canDelete(a);
}

int main(){
    cin >> t >> p;
    for(int i=0; i<t.length(); i++){
        int a; cin >> a;
        arr.push_back(--a);
    }
    int l = 0, r = t.length()-1, ans = 0;
    while(l <= r){
        int m = l + (r-l) / 2;
        if(works(m)){
            ans = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    cout << ans << endl;
}