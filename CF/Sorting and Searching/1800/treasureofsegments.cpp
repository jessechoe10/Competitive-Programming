// Problem Link: https://codeforces.com/problemset/problem/1462/F
// Official Editorial: https://codeforces.com/blog/entry/85594

/*
	Let's consider the two conditions that allows us to "delete" a segment.

	Two segments are considered to be disjoint if and only if a given segment i is
	either to the left or to the right of a given segment j.

	For the first condition to be satisfied, r_i < l_j must be true. For the second 
	condition to be satisfied, r_j < l_i must be true.

	Now, it suffices to find the maximum number of "good" segments. We can compute this
	by finding how many segments a of r are less than a given l_i and how many segments b
	of l are less than a given r_i. This requires sorting l and r and binary searching
	for these values. The total number of "good" segments for a given i is b - a.

	We can find the maximum number of "good" segments s and print the answer n - s. 
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

#define ub(a, x) upper_bound(begin(a), end(a), x) - begin(a)
#define lb(a, x) lower_bound(begin(a), end(a), x) - begin(a)

void solve(int t){
	int n; cin >> n;
	vector<pi> segments(n);
	vector<ll> left(n), right(n);
	for(int i = 0; i < n; i++){
		cin >> segments[i].first >> segments[i].second;
		left[i] = segments[i].first, right[i] = segments[i].second;
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	int maxGood = 0;
	for(int i = 0; i < n; i++){
		int high = ub(left, segments[i].second), low = lb(right, segments[i].first);
		maxGood = max(maxGood, high - low);
	}
	cout << n - maxGood << endl;
}

int main(){
	int t; cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);
	}
}