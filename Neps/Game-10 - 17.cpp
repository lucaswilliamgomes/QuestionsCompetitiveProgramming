#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, d, a, range;

    cin >> n >> d >> a;

    if (a <= d) range = d-a;
    else range = n - a + d;

    cout << range << endl;

    return 0;
}