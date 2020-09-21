#include <bits/stdc++.h>
#define ll long long

using namespace std;

int mdc(ll num1, ll num2){
    return (num2 == 0) ? num1 : mdc(num2, num1 % num2);
}

int main () {
    ll M, N;
    cin >> N >> M;

    for (ll x = M; x >= 1; x--){
        if (mdc(N , x) == 1){
            cout << x;
            break;
        }
    }
}