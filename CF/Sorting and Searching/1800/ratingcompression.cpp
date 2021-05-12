// Problem Link: https://codeforces.com/problemset/problem/1450/D
// Official Editorial: https://codeforces.com/blog/entry/85348

/*
	YoRepi7's analysis:

	If we were to purely simulate the solution to this problem, we would get time limit exceeded due to an
	overwhelming time complexity of O(n^2 logn). This solution would be done by checking whether each 
	k-compression array is a permuation in O(n log n) time using a set and doing that for all values of k
	in linear time for a total quadratic runtime. However, we must ask ourselves the question of can we do 
	better? Obviously, the answer is yes. Before we delve deeper, we must consider the edge case where k
	is equal to 1. However, we can quickly realize that the array a is the 1-compression array of a. Thus,
	it suffices to check whether or not the array a is a permuation in itself. 

	Consider the following:
	In order for a compression array of size k to be a permuation, the numbers 1...n-k+1 must uniquely appear
	in the compression array. Let's say k was n; wouldn't the n-compression array be a permuation only if it
	consists of a 1? Given that 1 <= a_i <= n, we know that the minimum possible element is a_i, right? Thus,
	any element in the array is 1, then there is a "valid" n-compression array. Let's say k was n-1; wouldn't
	the (n-1)-compression be a permuation if it consists of a 1 and 2? Given that we already found a 1 in the array, 
	it suffices to check if there is a 2 in the array, which isn't a part of the "group" where the 1 is found.
	We can fix the "groups" by using a left and right pointer, which describes the bounds of the group. Similarly,
	this logic applies for all k's from n to 2. However, we know that if k can't be found in the current "group",
	then the remaining k-compression arrays from i = k to i = 2 will not work since a valid permuation can't exist.
	Aside from checking whether a certain element can be found between our bounds, we must check if it's unique.
*/

#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve(int tc){
	int n; cin >> n; vi a(n), res(n);
	map<int, int> cnt;
	for(int i = 0; i < n; i++){
		cnt[i] = 0;
	}
	for(int i = 0; i < n; i++){
		cin >> a[i]; cnt[a[i]]++;
	}
	res[n - 1] = 1;
	int l = 0, r = n - 1;
	for(int i = 0; i < n; i++){
		if(!cnt[i + 1]) break;
		res[i] = 1;
		if(cnt[i + 1] > 1 || (a[l] != i + 1 && a[r] != i + 1)){
			break;
		}
		if(a[l] == i + 1){
			l++;
		} else {
			r--;
		}
	}
	for(int i = 0; i < n; i++){
		if(cnt[i + 1] != 1) res[n-1] = 0;
	}
	for(int i = n-1; i >= 0; i--){
		cout << res[i];
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);
	}
}
