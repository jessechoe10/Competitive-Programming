// Problem Link: https://codeforces.com/problemset/problem/1398/D
// Official Editorial: https://codeforces.com/blog/entry/81506

/*
	Wasn't able to AC due to my lack of practice with dynamic programming.
	This problem required DP, so I wasn't able to solve it unfortunately, sorry.
	However, I wrote a solution that ACs 6 test cases. Hopefully, if you know DP,
	you will be able to solve this problem (hopefully, with the help of my provided 
	solution). 

	Fortunately for you, my full solution for this problem is coming soon!

	Additionally, you can find the DP solution for this problem by clicking on
	the editorial above.
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int i, int j, int k){
	return (i && j) || (j && k) || (i && k);
}

int min(int a, int b, int c){
	return min(a, min(b, c));
}

int main(){
	int r, g, b; cin >> r >> g >> b;
	vector<int> red(r + 1, 0), green(g + 1, 0), blue(b + 1, 0);
	for(int i = 1; i <= r; i++){
		cin >> red[i];
	}
	for(int i = 1; i <= g; i++){
		cin >> green[i];
	}
	for(int i = 1; i <= b; i++){
		cin >> blue[i];
	}
	sort(red.begin() + 1, red.end());
	sort(green.begin() + 1, green.end());
	sort(blue.begin() + 1, blue.end());
	int i = r, j = g, k = b, ans = 0;
	while(check(i, j, k)){
		int sticks1 = red[i], sticks2 = green[j], sticks3 = blue[k];
		int ignoreStick = min(sticks1, sticks2, sticks3);
		if(ignoreStick == sticks1){
			ans += (sticks2 * sticks3);
			j--; k--;
		} else if(ignoreStick == sticks2){
			ans += (sticks1 * sticks3);
			i--; k--;
		} else {
			ans += (sticks1 * sticks2);
			i--; j--;
		}
	}
	cout << ans << endl;
}