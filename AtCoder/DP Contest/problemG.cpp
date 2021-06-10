// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_g

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100000];
int dp[100000], visited[100000];

int dfs(int node){
	if(visited[node]) return dp[node];
	int best = 0; visited[node] = true;
	for(int v: adj[node]){
		best = max(best, dfs(v) + 1);
	}
	return dp[node] = best;
}

int main(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y; --x, --y;
		adj[x].push_back(y);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, dfs(i));
	}
	cout << ans << endl;
}