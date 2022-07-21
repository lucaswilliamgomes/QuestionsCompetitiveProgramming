#include <bits/stdc++.h>
#define ll long long

using namespace std;

// ll calc (ll a, ll b) {
//     // ll ans = a;
//     // for (int i = 0; i < b; i++) {
//     //     ans *= 2;
//     // }
//     return a ^ b;
// }

int main () {
    int n;
    cin >> n;
    // vector<ll> totais(n);
    ll max_ = 0;
    int ans;

    
    for (int i = 0; i < n; i++) {
        ll aux_a, aux_b;
        cin >> aux_a >> aux_b;
        ll resp = aux_a ^ aux_b;
        if (resp > max_) {
            ans = i;
            max_ = resp;
        }
        // max_ = max(calc(aux_a, aux_b), max_);
    }

    cout << calc(135, 20) << " " << calc(2, 4999) << endl;
    cout << ans+1 << endl;

    return 0;
}