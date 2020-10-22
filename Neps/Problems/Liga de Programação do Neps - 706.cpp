#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, ans;
    cin >> n;
    ans = n - 9;

    if (ans <= 0) ans = 24 + ans;
    if (ans == 24) ans = 0;
    
    cout << ans << endl; 

    return 0;
}