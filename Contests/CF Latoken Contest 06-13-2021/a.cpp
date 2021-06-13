#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m;
char grid[50][50];
char grid1[50][50], grid2[50][50];

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if((i % 2) == (j % 2)){
				grid1[i][j] = 'W';
				grid2[i][j] = 'R'; 
			} else {
				grid1[i][j] = 'R';
				grid2[i][j] = 'W';
			}
		}
	}
	bool works1 = true, works2 = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if((grid[i][j]) != '.'){
				if(grid1[i][j] != grid[i][j]){
					works1 = false;
				}
				if(grid2[i][j] != grid[i][j]){
					works2 = false;
				}
			}
		}
	}
	if(!works1 && !works2){
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		if(works1){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					cout << grid1[i][j];
				}
				cout << endl;
			}
		} else {
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					cout << grid2[i][j];
				}
				cout << endl;
			}
		}
	}
}

int main(){
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
}
