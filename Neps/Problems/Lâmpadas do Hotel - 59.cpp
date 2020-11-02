#include <bits/stdc++.h>

using namespace std;

int main () {
    int a, b, c , d;
    cin >> a >> b >> c >> d;

    if (b == d){
        if (a == c) cout << 0 << endl;
        else cout << 1 << endl;
    } else {
        if (a == c) cout << 2 << endl;
        else cout << 1 << endl;
    }

    return 0;
}