#include <bits/stdc++.h>
#define ll long long

using namespace std;

char is_primo (ll num) {

    int raiz = sqrt(num);
    if (num == 1) return 'N';

    for (ll x = 2; x <= raiz; x++)   
        if (num % x == 0)
            return 'N';    
    
    return 'S';
}

int main () {
    ll N;
    cin >> N;
    cout << is_primo(N) << endl;
    return 0;
}