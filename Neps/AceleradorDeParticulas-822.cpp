#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll length, aux;
    cin >> length;
    length = length - 5;

    aux = floor(length/8);

    if (length < 8) cout << length;
    else {
        if ((aux * 8) + 1 == length ) cout << 1;
        else if ((aux * 8) + 2 == length) cout << 2;
        else if ((aux * 8) + 3 == length) cout << 3;
    }
    return 0;
}