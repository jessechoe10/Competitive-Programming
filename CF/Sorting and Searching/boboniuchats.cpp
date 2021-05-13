// Problem Link: https://codeforces.com/problemset/problem/1394/A
// Official Editorial: https://codeforces.com/blog/entry/81355

/*
	YoRepi7's analysis:

	Let's partition array a into two separate arrays: good and bad. good represents all of the fun factors
	less than m and bad represents all of the fun factors greater than m...

	We can represent each bad element with an "X" and each good element with a "."

	Here is the unpermuted representation of the first sample input:
	..XX.

	Here is the permuted representation (which generates the maximum fun fators) of the first sample input:
	X...X

	As we can observe here, it is optimal to put the "." between each consecutive "X" since "." is guaranteed
	to be less than "X". This important observation leads to us being able to determine the number of days after
	day 1 for the last "X" to appear. This formula is (x - 1) * (d + 1) + 1, where x represents the number of times
	"X" appears. n - (x - 1) * (d + 1) - 1 represents the number of good elements which can be attached to the left
	of the last appearing "X". 

	We can iterate through the highest x "X"s in the bad array and contribute that to our total.
	Additionally, we can iterate through the highest (n - (x - 1) * (d + 1) - 1) good elements and
	contribute that to our total.

	However, this isn't our overall answer. We must find the maximum possible total for a chosen value
	of x since there could be alternative arrangements of "X" and "." which provides a higher output...

	The X..X....X format doesn't necessarily generate the maximum; thus, it suffices to maintain prefix
	sums and iterate each value of x.  
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a[100001], b[100001], dp[100001];

int main(){
	ll n, d, m; cin >> n >> d >> m;
	int cur1 = 0, cur2 = 0;
	for(int i = 1; i <= n; i++){
		ll x; cin >> x;
		if(x <= m) a[++cur1] = x;
		else b[++cur2] = x;
	}
	sort(a + 1, a + 1 + cur1, greater<ll>());
	sort(b + 1, b + 1 + cur2, greater<ll>());
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i - 1] + a[i];
	}
	ll curSum = 0, ans = dp[n];
	for(int i = 1; i <= cur2; i++){
		curSum += b[i];
		ll y = (i - 1) * (d + 1) + 1;
		if(y > n) break;
		ans = max(ans, curSum + dp[n - y]);
	}
	cout << ans << endl;
}
