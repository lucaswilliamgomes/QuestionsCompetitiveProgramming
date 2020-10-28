#include <bits/stdc++.h>

using namespace std;

int main () {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    int maq1 = (a1 * 0 + a2 * 1 + a3 * 2) * 2 ;
    int maq2 = (a1 * 1 + a2 * 0 + a3 * 1) * 2;
    int maq3 = (a1 * 2 + a2 * 1 + a3 * 0) * 2; 

    int ans = min(maq1, maq2);
    ans = min (ans, maq3);
    cout << ans << endl;

    return 0;
}