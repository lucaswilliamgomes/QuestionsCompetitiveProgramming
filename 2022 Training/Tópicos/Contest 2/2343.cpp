#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main () {
    int n;
    cin >> n;

    bool m[550][550];
    int ans = 0;

    for(int i = 0; i < n; i++) {
        int aux_a, aux_b;
        cin >> aux_a >> aux_b;
        if (m[aux_a][aux_b]) {
            ans = 1;
        } else {
            m[aux_a][aux_b] = true;
        }
    }

    cout << ans << endl;
    

    return 0;
}