#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using mp = map<ll, ll>;
using ms = multiset<ll>;
using pq = priority_queue<ll>;
using sl = set<ll>;

#define lb lower_bound
#define ub upper_bound
#define beg begin
#define last rbegin
#define cnt count
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define sorc(x, cmp) sort(all(x), cmp)
#define dbg(x) for(auto& a: x) cout << a << " "
#define print(x) cout << x << endl
#define trav(x) for(auto& a: x)

// Binary search on the answer for the smallest value of x

ll binarySearch1(ll l, ll r, bool works(ll x)){
    ll ans = r;
    while(l <= r){
        ll m = l + (r-l) / 2;
        if(works(m)){
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    return ans;
}

// Binary search on the answer for the highest value of x

ll binarySearch2(ll l, ll r, bool works(ll x)){
    ll ans = l;
    while(l <= r){
        ll m = l + (r-l) / 2;
        if(works(m)){
            ans = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
}

void solve(int t){

}

int main(){
    cout << "Hello World" << endl;
}
