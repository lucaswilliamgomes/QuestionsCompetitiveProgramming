#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n, x, y;

bool good(ll value) {
    int s = 0;
    s += floor(value / x);
    s += floor(value / y);
    //cout << s << endl;
    return s >= n;
}

int main () {

    int timeInitial;
    cin >> n >> x >> y;    
    n--;
    timeInitial = min(x, y);
    int l = 0;
    ll r = 1000000000;
    for(int i = 0; i < 100; i++) {
        ll m = (l + r) / 2;
        if (good(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r + timeInitial << endl;
    return 0;
}