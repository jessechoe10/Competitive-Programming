#include <bits/stdc++.h>

using namespace std;

double c;

double expression(double x){
    return x*x + sqrt(x);
}

bool works(double x){
    return expression(x) >= c;
}

int main(){
    cin >> c;
    double l = 1e-6, r = c, ans = l, eps = l;
    while(l + eps < r){
        double m = (l + r) / 2;
        if(works(m)){
            ans = m;
            r = m;
        } else {
            l = m;
        }
    }
    cout << setprecision(6) << fixed << ans << endl;
}