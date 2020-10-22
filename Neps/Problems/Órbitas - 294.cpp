#include <bits/stdc++.h>
#define ll long long

using namespace std;

int mdc (ll a, ll b){
    return (b == 0) ? a : mdc(b, a % b);
}

int main () {
    ll num1, num2;
    cin >> num1 >> num2;
    cout << (num1 * num2) / mdc(num1, num2);

    return 0;
}