#include <bits/stdc++.h>
#define ll  long long

using namespace std;

int mdc (ll num1, ll num2){
    return (num2 == 0) ? num1 : mdc(num2, num1 % num2);
}

ll mmc (ll num1, ll num2){
    return (num1 * num2) / mdc(num1, num2);
}

int main(int argc, char const *argv[]){
    ll a, b, c, d;

    cin >> a >> b >> c >> d;

    ll denominador = mmc(b, d);
    ll numerador = ((denominador / b) * a) + ((denominador / d) * c);

    ll divisor = mdc (numerador, denominador);

    cout << numerador/divisor << " " <<  denominador/divisor;

    return 0;
}