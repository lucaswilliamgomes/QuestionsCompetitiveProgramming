#include <bits/stdc++.h>

using namespace std;

int main () {
    int k, x, y;
    cin >> k >> x >> y;
    if (abs(x-y) >= k) cout << "EH SUFICIENTE";
    else cout << "NAO EH SUFICIENTE";
    return 0;
}