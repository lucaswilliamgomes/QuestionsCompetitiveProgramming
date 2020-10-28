#include <bits/stdc++.h>

using namespace std;

int main (){
    int a, b, c, d, f, g, ansa, ansb, ansc, ans = 0;
    cin >> a >> b >> c >> d >> f >> g;
    ansa = d - a; ansb = f - b; ansc = g - c;
    if (ansa > 0) ans += ansa;
    if (ansb > 0) ans += ansb;
    if (ansc > 0) ans += ansc;
    cout << ans << endl;
    return 0;
}