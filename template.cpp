#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 5e6;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b){
	return ((a) / gcd(a, b)) * b;
}

vector<int> factor(int n){
	vector<int> ret;
	for(int i = 2; i * i <= n; i++){
		while(n % i == 0){
			ret.push_back(i);
			n /= i;
		}
	}
	if(n > 1) ret.push_back(n);
	return ret;
}

void sort(vector<int>& arr){
	sort(arr.begin(), arr.end());
}

int countRange(vector<int>& arr, int l, int r){
	return upper_bound(arr.begin(), arr.end(), r) - lower_bound(arr.begin(), arr.end(), l);
}

vector<int> psum(vector<int>& arr){
	int n = arr.size();
	vector<int> dp(n);
	dp[0] = arr[0];
	for(int i = 1; i < n; i++){
		dp[i] = dp[i - 1] + arr[i];
	}
	return dp;
}

int sum(vector<int> dp, int l, int r){
	return dp[r + 1] - dp[l];
}

bool visited[MAXN];
vector<int> adj[MAXN];

void dfs(int u){
	visited[u] = true;
	for(int v: adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

void solve(){

}

int main(){
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
}
