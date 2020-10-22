#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main () {
    int passos;
    ll ans, lado = 2;

    cin >> passos;

    for (int i = 0; i < passos; i++){
        lado += lado-1;
    }

    ans = lado * lado;
    cout << ans << endl;
    return 0;
}