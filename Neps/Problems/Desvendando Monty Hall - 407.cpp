#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, car, ans = 0;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> car;
        if (car == 2 or car == 3) ans++;
    }

    cout << ans << endl;
    return 0;
}