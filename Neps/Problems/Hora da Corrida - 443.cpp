#include <bits/stdc++.h>

using namespace std;

int main () {
    float voltas, placas;
    int ans;
    cin >> voltas >> placas;
    for (int i = 1;i <= 9;i++){
        ans = ceil ((voltas*placas/10) * i);
        cout << ans << " ";
    }
    
    cout << endl;

    return 0;
}