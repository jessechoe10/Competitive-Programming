#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if(n == 2){
		cout << a[0] << " " << a[1] << endl; 
	} else {
		ll distance = 1e9, mountain = -1;
		for(int i = 0; i < n - 1; i++){
			if(a[i + 1] - a[i] < distance){
				mountain = i;
				distance = a[i + 1] - a[i];
			}
		}
		cout << a[mountain + 1] << " ";
		for(int i = mountain + 2; i < n; i++){
			cout << a[i] << " ";
		}
		for(int i = 0; i < mountain; i++){
			cout << a[i] << " ";
		}
		cout << a[mountain] << " ";
		cout << endl;
	}
}

int main(){
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
}
