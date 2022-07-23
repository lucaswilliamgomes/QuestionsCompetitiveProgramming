#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    int max_ = 0;
    int ans;

    for (int i = 0; i < n; i++) {
        int aux_a, aux_b;
        cin >> aux_a >> aux_b;
        double resp = pow(aux_a, log10(aux_b));
        cout << resp << endl;
        if (resp > max_) {
            ans = i;
            max_ = resp;
        }
    }

    cout << ans+1 << endl;
    return 0;
}