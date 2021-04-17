/*
ID: yorepi01
TASK: ride
LANG: C++14                
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string comet, group; cin >> comet >> group;
    int cometNumber = 1;
    for(int i=0; i<comet.length(); i++){
        cometNumber *= (comet[i] - 'A' + 1);
    }
    int groupNumber = 1;
    for(int i=0; i<group.length(); i++){
        groupNumber *= (group[i] - 'A' + 1);
    }
    cometNumber %= 47, groupNumber %= 47;
    if(cometNumber == groupNumber){
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }
}