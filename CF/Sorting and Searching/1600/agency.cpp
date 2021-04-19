#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

ll binomialCoeff(int n, int k)
{
    // Code copied from: https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
    ll C[n + 1][k + 1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
                C[i][j] %= mod;
        }
    }
    return C[n][k];
}

void solve(int t){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [](int a, int b){
        return a > b;
    });
    vector<int> bloggers;
    int minBlogger = a[k-1];
    for(int i=0; i<n; i++){
        if(a[i] < minBlogger){
            break;
        } else {
            bloggers.push_back(a[i]);
        }
    }
    int fixed = 0, cnt = 0;
    for(int i: bloggers){
        if(i > minBlogger){
            fixed++;
        }
        if(i == minBlogger){
            cnt++;
        }
    }
    n = bloggers.size();
    cout << binomialCoeff(cnt, k - fixed) << endl;
}

int main(){
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}