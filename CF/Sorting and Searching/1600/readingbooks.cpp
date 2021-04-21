#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define dbg(x) for(auto& a: x) cout << a << " "
#define print(x) cout << x << endl

int books1[200000], books2[200000], books3[200000];

int main(){
    int n, k; cin >> n >> k;
    int s1 = 0, s2 = 0, s3 = 0;
    for(int i=0; i<n; i++){
        int t, a, b; cin >> t >> a >> b;
        if(a && b){
            books1[s1++] = t;
        } else if(a){
            books2[s2++] = t;
        } else if(b){
            books3[s3++] = t;
        }
    }
    sort(books2, books2+s2); sort(books3, books3+s3);
    for(int i=0; i<min(s2, s3); ++i){
        books1[s1++] = books2[i] + books3[i];
    }
    if(s1 < k){
        print(-1);
    } else {
        sort(books1, books1+s1);
        ll res = 0;
        for(int i=0; i<k; i++){
            res += books1[i];
        }
        print(res);
    }
}