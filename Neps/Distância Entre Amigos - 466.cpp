#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main () {
    ll N, aux;
    vector <ll> buildings;
    ll best = 0, ans = 0;

    cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> aux;
        buildings.push_back(aux);
    }

    best = buildings[0];

    for (ll i = 0; i < N; i++) {
        ans = max(ans, buildings[i] + i + best);
        best = max(best, buildings[i] - i);
    }

    cout << ans;
    return 0;
}