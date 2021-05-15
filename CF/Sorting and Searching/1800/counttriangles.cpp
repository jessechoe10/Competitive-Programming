// Problem Link: https://codeforces.com/problemset/problem/1355/C
// Official Editorial: https://codeforces.com/blog/entry/77491

/*
	YoRepi7's analysis:

	We can use the triangle inequality theorem to check if sides x, y, and z forms a triangle.
    The properties are as follows:

    x + y > z
    x + z > y
    y + z > x

    It can be proven that the second and third conditions are always true for all triplets of x, y, and z,
    given the constraints.

    Thus, it suffices to check only the first condition of the triangle inequality theorem. The naive cubic
    time solution would be to fix a given value of z and iterate over all values of x and y in quadratic time 
    and check for each pair (x, y, z) the number of triangles satisfying x + y > z. However that is too slow. 
    The next thing that comes to mind is a quadratic time solution which is a slight speedup from the previous
    solution which uses two pointers. However, this is still too slow. We must devise a linear time solution.

    We can use prefix sums! Let's fix z like we did before. We can use prefix sums to iterate over all values
    of x and compute the minimum possible sum for a fixed x. The minimum possible sum is [x + B]. For each
    value from x + B to x + C + 1, we can use prefix sums to maintain a running total to compute the number
    of pairs of <X, Y> greater than Z. This solution will run in linear time which is the algorithm we are
    looking for!
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6;

int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    vector<ll> dp(N + 1);
    for(int i = a; i <= b; i++){
        dp[i + b]++;
        dp[i + c + 1]--;
    }
    for(int i = 1; i <= N; i++){
        dp[i] += dp[i - 1]; 
    }
    for(int i = 1; i <= N; i++){
        dp[i] += dp[i - 1]; 
    }
    ll ans = 0;
    for(int i = c; i <= d; i++){
        ans += dp[N] - dp[i];
    }
    cout << ans << endl;
}