// Problem Link: https://codeforces.com/problemset/problem/1508/A
// Official Editorial: https://codeforces.com/blog/entry/89644

/*
	YoRepi7's analysis:

	We need a linear time solution for this problem. Given what we know about a subsequence,
	this shouldn't be too difficult.

	Perhaps we can begin by observing what makes up a subsequence.

	Given some string s, if one string is a subsequence of another, then each letter in the string
	must appear at least once in the given order. 
	
	For instance: 011001010.

	In this example, the string 111010 is a subsequence of s. 1, 1, 1, 0, 1, 0 can be detected in the 
	above string. Specifically, each of those characters appear in some (distinct/non-distinct) positions
	of s.

	Given what we know about a subsequence, we can easily form a bitstring containing at least two bitstrings
	using two pointers.

	We can store two pointers: one which points to one bitstring and one that points to another. If the character
	pointing to the first bitstring is equal to the character pointing to the second bitstring, then we can
	move both pointers. Otherwise, we should move only one pointer (say, the first pointer). We can print out
	the character at a given first pointer and check if that string prints out a bitstring of length at most
	3n.

	However, to optimize this solution, it suffices to iterate over all three of the given strings and check
	which ones minimize the bitstring length. This will essentially allow us to print a bitstring of length
	at most 3n.

	This solution runs in linear time (O(n) time).
*/

#include <bits/stdc++.h>

using namespace std;

int n;

void makeNovel(string prompt1, string prompt2, string prompt3){
	int i = 0, j = 0, k = 0, l = 0;
	while(i < 2*n && j < 2*n && k < 2*n){
		int numZeros = (prompt1[i] == '0') + (prompt2[j] == '0') + (prompt3[k] == '0');
		char cur;
		if(numZeros >= 2){
			cur = '0'; 
		} else {
			cur = '1';
		}
		cout << cur;
		if(prompt1[i] == cur){
			i++;
		}
		if(prompt2[j] == cur){
			j++;
		}
		if(prompt3[k] == cur){
			k++;
		}
		l++;
	}
	l -= n;
	if(i < 2*n && i >= l){
		cout << prompt1.substr(i) << endl;
	} else if(j < 2*n && j >= l){
		cout << prompt2.substr(j) << endl;
	} else if(k < 2*n && k >= l){
		cout << prompt3.substr(k) << endl;
	} else {
		cout << endl;
	}
}

void solve(int tc){
	cin >> n;
	string prompt1, prompt2, prompt3;
	cin >> prompt1 >> prompt2 >> prompt3;
	makeNovel(prompt1, prompt2, prompt3);
}

int main(){
	int t; cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);
	}
}