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
