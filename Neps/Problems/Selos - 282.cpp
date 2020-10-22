#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool is_prime (ll num){
    int root = sqrt(num);
    if (num == 1) return false;

    for (ll x = 2; x <= root; x++){ 
        if (num % x == 0)
            return false;  
    }
    return true;
}

int main () {
    ll N;
    cin >> N;
    if (is_prime(N) || N == 1) cout << "N";
    else cout << "S";
    return 0;
}