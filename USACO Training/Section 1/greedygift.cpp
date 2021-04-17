/*
ID: yorepi01
TASK: gift1
LANG: C++14                
*/

#include <bits/stdc++.h>

using namespace std;

int totalBalance(int amt, int ppl){
    if(ppl == 0){
        return -amt;
    }
    return amt - (amt % ppl); 
}

int main(){
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    int n; cin >> n;
    map<string, int> m;
    vector<string> names;
    for(int i=0; i<n; i++){
        string person; cin >> person;
        names.push_back(person);
        m[person] = i;
    }
    vector<int> cur(n, 0);
    for(int t=0; t<n; t++){
        string giver; cin >> giver;
        int amt, ppl; cin >> amt >> ppl;
        cur[m[giver]] -= totalBalance(amt, ppl);
        for(int i=0; i<ppl; i++){
            string receiver; cin >> receiver;
            cur[m[receiver]] += (amt / ppl);
        }
    }
    for(int i=0; i<n; i++){
        cout << names[i] << " " << cur[m[names[i]]] << endl;
    }   
}