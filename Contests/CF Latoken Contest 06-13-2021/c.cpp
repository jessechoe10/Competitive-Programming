#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 400001;
const int MOD = 1e9 + 7;

bool visited[MAXN];

vector<int> adj[MAXN];

void dfs(int node){
	visited[node] = true;
	for(int v: adj[node]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i <= n; i++){
		adj[i] = vector<int>();
		visited[i] = false;
	}
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	for(int i = 0; i < n; i++){
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
	ll ans = 1;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			ans = (ans * 2) % MOD;
			dfs(i);
		}
	}
	cout << ans << endl;
}

int main(){
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
}
