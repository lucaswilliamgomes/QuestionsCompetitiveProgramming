#include <bits/stdc++.h>

using namespace std;

int main () {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    if ((a + b) < c) cout << 1;
    else if (a < c or b < c) cout << 2;
    else cout << 3;

    return 0;
}