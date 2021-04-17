/*
ID: yorepi01
TASK: friday
LANG: C++14                
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    int n; cin >> n;
    int dotw = 0;
    vector<int> thirteenth(7);
    for(int i=0; i<n; i++){
        for(int m=1; m<=12; m++){
            if(m == 4 || m == 6 || m == 9 || m == 11){
                for(int d=1; d<=30; d++){
                    if(d == 13){
                        thirteenth[dotw]++;
                    }
                    ++dotw;
                    dotw %= 7;
                }
            } else if(m == 2){
                if((i+1900) % 4 == 0){
                    if(((i+1900) % 400) && ((i+1900) % 100 == 0)){
                        for(int d=1; d<=28; d++){
                            if(d == 13){
                                thirteenth[dotw]++;
                            }
                            ++dotw;
                            dotw %= 7;
                        }
                    } else {
                        for(int d=1; d<=29; d++){
                            if(d == 13){
                                thirteenth[dotw]++;
                            }
                            ++dotw;
                            dotw %= 7;
                        }
                    }
                } else {
                    for(int d=1; d<=28; d++){
                        if(d == 13){
                            thirteenth[dotw]++;
                        }
                        ++dotw;
                        dotw %= 7;
                    }
                }
            } else {
                for(int d=1; d<=31; d++){
                    if(d == 13){
                        thirteenth[dotw]++;
                    }
                    ++dotw;
                    dotw %= 7;
                }
            }
        }
    }
    for(int i=5; i<7; i++){
        cout << thirteenth[i] << " ";
    }
    for(int i=0; i<5; i++){
        cout << thirteenth[i];
        if(i != 4){
            cout << " ";
        } else {
            cout << endl;
        }
    }
}